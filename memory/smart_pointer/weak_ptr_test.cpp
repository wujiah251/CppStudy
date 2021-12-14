#include <iostream>
#include <memory>
using namespace std;


int main()
{
    shared_ptr<int> ptr(new int(5));
    weak_ptr<int> wp(ptr);
    cout << "创建weak_ptr后，引用计数=" << wp.use_count() << endl;
    if (shared_ptr<int> pa = wp.lock())
    {
        cout << *pa << endl;
    }
    else
    {
        cout << "wp 指向对象为空" << endl;
    }
    cout << wp.expired() << endl;
    ptr.reset();
    if (shared_ptr<int> pb = wp.lock())
    {
        cout << *pb << endl;
    }
    else
    {
        cout << "wp 指向对象为空" << endl;
    }
    cout << wp.expired() << endl;
    return 0;
}
