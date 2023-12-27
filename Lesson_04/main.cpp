#include <iostream>

#include "TShared_ptr.h"
#include "TWeak_ptr.h"

using namespace std;

int main()
{

    {//shared_ptr
        int a = 3;
        SharedPtr<int> ptr1(&a);
        SharedPtr<int> ptr2 = ptr1;
        SharedPtr<int> ptr3 = ptr2;
        cout << "shared_ptr Test" <<endl;
        cout << "sharedCounter: " << ptr1.count().sharedCounter <<endl;
        ptr3.reset();
        cout << "sharedCounter: " << ptr1.count().sharedCounter <<endl;
        ptr2.reset();
        cout << "sharedCounter: " << ptr1.count().sharedCounter <<endl;
        cout << "shared_ptr Test end\n" <<endl;
    }

    {//weak_ptr
        int a= 3;
        WeakPtr<int> ptr2;
        WeakPtr<int> ptr3;
        {
            SharedPtr<int> ptr1(&a);
            ptr2 = ptr1;
            ptr3 = ptr2;
            cout << "weak_ptr Test" <<endl;
            cout << "Counter{shared, weak}: " << ptr1.count().sharedCounter << ", " << ptr1.count().weakCounter <<endl;
        }
        cout << "Counter{shared, weak}: " << ptr2.count().sharedCounter << ", " << ptr2.count().weakCounter <<endl;
        cout << "weak_ptr Test end" <<endl;

    }
        return 0;
}
