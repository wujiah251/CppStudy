#ifndef THREAD_POOL_H_
#define THREAD_POOL_H_

#include <condition_variable>
#include <functional>
#include <future>
#include <iostream>
#include <mutex>
#include <memory>
#include <queue>
#include <stdexcept>
#include <thread>
#include <type_traits>
#include <vector>

class ThreadPool
{
    public:
        // 构造函数，传入线程数量
        ThreadPool(size_t threads);

        // 模板函数，添加任务
        template<class F, class... Args>
            auto enqueue(F&& f, Args&&... args) -> std::future<typename std::result_of<F(Args...)>::type>;

        // 析构函数
        ~ThreadPool();


    private:
        std::vector<std::thread> _workers; // 工作线程组
        std::queue<std::function<void()>> _tasks; // 任务队列
        std::mutex _mutex;         // 用于控制任务队列并发的互斥锁
        std::condition_variable _condition; // 条件变量
        bool stop;
};


inline ThreadPool::ThreadPool(size_t threads)
    :stop(false)
{
    for(int i=0;i<threads;++i)
    {
        _workers.emplace_back([this]{
                while(true)
                {
                std::function<void()> task;
                {
                // 独占锁
                std::unique_lock<std::mutex> lock(this->_mutex);
                // 等待条件：线程池停止或者size>0
                this->_condition.wait(lock,
                        [this]{return this->stop || !this->_tasks.empty();});
                if(this->stop && this->_tasks.empty())
                {
                return;
                }
                task = std::move(this->_tasks.front());
                this->_tasks.pop();
                }
                task();
                }
                });
    }
}

template<class F,class... Args>
auto ThreadPool::enqueue(F&& f,Args&&... args)->std::future<typename std::result_of<F(Args...)>::type>
{
    using return_type = typename std::result_of<F(Args...)>::type;
    auto task = std::make_shared<std::packaged_task<return_type()>> (
            std::bind(std::forward<F>(f), std::forward<Args>(args)...)
            );
    std::future<return_type> res = task->get_future();
    {
        if(stop){
            throw std::runtime_error("enqueu on stopped ThreadPool");
        }
        _tasks.emplace([task]
                (){(*task)();}
                );
    }
    _condition.notify_one();
    return res;
}

ThreadPool::~ThreadPool()
{
    {
        std::unique_lock<std::mutex> lock(_mutex);
        stop = true;
    }
    _condition.notify_all();
    for(std::thread &worker: _workers){
        worker.join();
    }
    std::cout << "all worker stop" << std::endl;
}

#endif
