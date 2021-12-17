#include "thread_pool.h"

static void test(int n)
{
    int count = 1;
    for(int i=0;i<n;++i)
    {
        count += i;
    }
}


int main()
{
    ThreadPool pool(5);
    for(int i=0;i<100;++i){
        pool.enqueue(test,100);
    }
    return 0;
}
