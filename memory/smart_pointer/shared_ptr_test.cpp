#include <iostream>
#include <memory>
using namespace std;

class A
{
public:
    int i;
    A(int n):i(n){}
    ~A(){cout << i << " " << "destroyed" << endl;}
};

void singleDemo()
{
    shared_ptr<A> ptr1(new A(2));
    shared_ptr<A> ptr2(ptr1);
    shared_ptr<A> ptr3;
    ptr3 = ptr2;
    cout << "ptr1 use count=" << ptr1.use_count() << endl;
    if(ptr1.unique())
    {
        cout << "ptr1 is unique" << endl;
    }
    else
    {
        cout << "ptr is not unique" << endl;
    }
    cout << "ptr1:" << ptr1->i
        << ",ptr2:" << ptr2->i
        << ",ptr3:" << ptr3->i << endl;
    A *p = ptr3.get();
    cout << p->i << endl;
    ptr1.reset(new A(3));
    cout << "ptr1 use count = " << ptr1.use_count() << endl;
    if(ptr1.unique())
    {
        cout << "ptr1 is unique" << endl;
    }
    else
    {
        cout << "ptr1 is not unique" << endl;
    }
    
    ptr2 = make_shared<A>(4);
    ptr1.swap(ptr2);
    cout << ptr1->i << endl;
    ptr3.reset(new A(5));
    cout << "end" << endl;
}

int main()
{
    singleDemo();

    return 0;
}
