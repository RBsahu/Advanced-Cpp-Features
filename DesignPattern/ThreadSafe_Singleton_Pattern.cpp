/*
Singleton Design Pattern
Definition
The Singleton Design Pattern is a creational design pattern that ensures 
a class has only one instance throughout the lifetime of an application and 
provides a global point of access to that instance.

This is usually achieved by:
Making the constructor private
Creating a static instance inside the class
Providing a public static method to access that instance

When Do We Use Singleton? (Real-Time Systems)
Used when exactly one shared resource is needed across multiple modules/threads:
 Logger Manager
 Configuration Manager
 Database Connection Pool
 Hardware Device Controller
 Thread Pool Manager
 Cache Manager
 Network Routing Table
*/

#include <iostream>
#include <mutex>
using namespace std;

class singleton
{
private:
    // Private constructor
    singleton()
    {
        cout << "Singleton Object Created\n";
    }

    // Delete Copy Constructor
    singleton(const singleton&) = delete;

    // Delete Assignment Operator
    singleton& operator=(const singleton&) = delete;

    static singleton* obj;   // Static instance pointer
    static mutex mtx;        // Mutex for thread safety

public:
    static singleton* getObj();
};

// Static member initialization
singleton* singleton::obj = nullptr;
mutex singleton::mtx;

// Thread Safe Instance Creation
singleton* singleton::getObj()
{
    // First check (No Lock)
    if (obj == nullptr)
    {
        lock_guard<mutex> lock(mtx);

        // Second Check (With Lock)
        if (obj == nullptr)
        {
            obj = new singleton();
        }
    }
    return obj;
}

int main()
{
    singleton* s1 = singleton::getObj();
    singleton* s2 = singleton::getObj();

    cout << "Address s1: " << s1 << endl;
    cout << "Address s2: " << s2 << endl;

    return 0;
}