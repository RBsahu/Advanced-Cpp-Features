//Definition/Syntax/Uses and code example for range-based for loop in C++11

/*

Definition
A Smart Pointer in C++11 is an object that manages the lifetime of a dynamically 
allocated resource using RAII (Resource Acquisition Is Initialization).
It automatically releases memory when it goes out of scope, preventing memory leaks, 
dangling pointers, and double deletion.
Smart pointers are defined in the <memory> header.

Types of Smart Pointers (C++11)
Smart Pointer	Ownership Model
unique_ptr	Exclusive ownership
shared_ptr	Shared ownership
weak_ptr	Non-owning reference

Syntax
#include <memory>

std::unique_ptr<Type> ptr;
std::shared_ptr<Type> ptr;
std::weak_ptr<Type>   ptr;

unique_ptr
Definition
The unique_ptr<> does not support copying.
If you try to copy a unique_ptr<>, you'll get compiler errors.

Syntax
std::unique_ptr<Type> ptr(new Type);

Use Case
Single owner resource
File handles, mutex, memory buffers
Factory pattern
Prevent accidental copies

shared_ptr in C++
A shared_ptr is a smart pointer that manages a resource that is shared across multiple owners.

weak_ptr
A weak_ptr is created as a copy of shared_ptr.
A weak pointer is a smart pointer that does not take ownership of an object 
but act as an observer.
it does not participate in reference counting to delete an object or extend its lifetime.
Weak pointers are used to break the circular dependency that shared pointers create.
The existence or destruction of weak_ptr has no effect on the shared_ptr or its other copies

 */

#include <iostream>
#include <memory> 

using namespace std;

class A
{
public:
    void printA() { cout << "A struct...." << endl; }
    void show() { cout << "Show from A" << endl; }
};

class Test 
{   
public:
    int data;
    Test() : data(0)
    {
        cout << "Test created with default value: " << data << endl;
	}
    Test(int value)  : data(value)
    {
        cout << "Test created with value: " << data << endl;
    }
    ~Test()
    {
        cout << "Test destroyed with value: " << data << endl;
    }    
};


int main()
{
    cout << "C++11 features smart pointer\n";
    
    cout << "Unique pointer\n";
    unique_ptr<A> p1(new A);
    p1->printA();

    // displays address of the containing pointer 
    cout << p1.get() << endl;

    cout << endl;
    // will give compile time error 
	// while copying unique_ptr
    //unique_ptr<A> p2 = p1;
    //p2->printA();

    // now address stored in p1 should get copied to p2 
    unique_ptr<A> p2 = move(p1);

    p2->printA();
    cout << p1.get() << endl;
    cout << p2.get() << endl;

    cout << "\nShared pointer\n";
    // creating a shared pointer and accessing the object
    shared_ptr<A> p11(new A);
    // printting the address of the managed object
    cout << p11.get() << endl;
    p11->show();

    // creating a new shared pointer that shares ownership
    shared_ptr<A> p22(p11);
    p22->show();

    // printing addresses of P1 and P2
    cout << p1.get() << endl;
    cout << p2.get() << endl;

    // Returns the number of shared_ptr objects
    // referring to the same managed object.
    cout << p11.use_count() << endl;
    cout << p22.use_count() << endl;

   
    p11.reset();
    cout << p11.get() << endl;
    cout << p22.use_count() << endl;
    cout << p22.get() << endl;

    cout << "Weak pointer\n";

    // creating shared pointer with resource ownership
    shared_ptr<Test> shared_Ptr = make_shared<Test>(42);

    // creating weak pointer to the previously created
    // shared Tests
    weak_ptr<Test> weak_Ptr = shared_Ptr;

    // Access Tests using weak_ptr
    if (!weak_Ptr.expired()) {
        cout << "The value stored in shared_Ptr:"<< (*weak_Ptr.lock()).data << endl;
    }
    // deleting Test
    shared_Ptr.reset();


    return 0;
       
}
