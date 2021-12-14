#include <iostream>
#include <memory>
#include <assert.h>

using namespace std;

// 函数返回是唯一可以拷贝的场景
template<class T>
unique_ptr<T> clone()
{
    unique_ptr<T> ptr(new T());
    return ptr;
}


void singleDemo()
{
    unique_ptr<int> p1(new int(5));
    cout << *p1 << endl;
    // unique_ptr不支持拷贝和赋值
    //unique_ptr<int> p2(p1);
    //unique_ptr<int> p3 = p2;
    
    // 支持移动构造
    unique_ptr<int> p2 = std::move(p1);
    cout << *p2 << endl;
    unique_ptr<int> p3 = clone<int>();
    cout << *p3 << endl;
}

void moveDemo()
{
    std::unique_ptr<int> ptr1;
    // ptr1 don't allocate memory
    //cout << *ptr1 << endl;
    std::unique_ptr<int> ptr2(new int(4));
    auto ptr3 = make_unique<int>();
    // ptr2释放指向对象的所有权，并且被置为nullptr
    cout << "Ptr2 release before:" << ptr2.get() << endl;
    int *pF = ptr2.release();
    std::cout << "Ptr2 release before:" << ptr2.get() << " and pF valule:" << *pF << endl;

    // 所有权转移，转移后ptr3变为控指针
    std::cout << "move before ptr1 address:" << ptr1.get() << " and ptr3 address:" << ptr3.get() << endl;
    ptr1 = std::move(ptr3);
    std::cout << "move after ptr1 address:" << ptr1.get() << " and ptr3 address:" << ptr3.get() << endl;
    cout << "move before ptr1 address:" << ptr1.get() << endl;
    ptr1.reset();
    cout << "move after ptr1 address:" << ptr1.get() << endl;
}


void deleteDemo()
{
    // 自定义delete函数
    struct D{
        void operator()(int* a)
        {
            cout << "D operator(), num=" << *a << std::endl;
            delete a;
        }
    };
    unique_ptr<int,D> ptr(new int);
} 


int main()
{
    singleDemo();
    moveDemo();
    deleteDemo();
    return 0;
}
