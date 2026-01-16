//code example for override identifier in C++11
/*
Definition
The override specifier is used to override a function and it makes sure that
overriding is done correctly. It is useful in finding the mistakes while
overriding a function.
The compiler will generate an error if the function is not overridden correctly.
 */

#include <iostream>
using namespace std;

class Base 
{
public:
    virtual void display() 
    {
        cout << "Display from Base" << std::endl;
    }

    virtual void compute(int x) 
    {
        cout << "Compute Base: " << x << std::endl;
    }

    void nonVirtual() 
    {
        cout << "Normal Base function" << std::endl;
    }
};

class Derived : public Base 
{
public:
    // Correct usage: exactly matches the Base::display signature
    void display() override 
    {
        cout << "Display from Derived" << std::endl;
    }

    // ERROR 1: Parameter type mismatch (double vs int)
    // Without 'override', this would silently create a new function
    // void compute(double x) override; 

    // ERROR 2: Const-correctness mismatch
    // void display() const override; 

    // ERROR 3: Attempting to override a non-virtual function
    // void nonVirtual() override; 
};

int main()
{
    cout << "C++11 features override identifier\n";
    Base* ptr = new Derived();
    ptr->display(); // Calls Derived::display() due to polymorphism
    delete ptr;
  
    return 0;       
}
