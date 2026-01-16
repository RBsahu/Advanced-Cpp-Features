//code example for Final Specifier in C++11
/*
Definition
The final specifier used to prevent inheritance and other classes can not inherit
from it.
To avoid virtual function overriding  in the derived classes.
 */

#include <iostream>
using namespace std;

//Preventing a class from being inherited
class Base final 
{   
public:
    void display() 
    {
        cout << "Base class" << endl;
    }
};

// Compile error because base class is final
//error C3246: 'Derived': cannot inherit from 'Base' as it has been declared as 'final'
class Derived : public Base 
{    
    void show() 
    {
        cout << "Derived class" << endl;
    }
};

//Preventing a virtual function from being overridden
class Base1 
{
public:
    // 'func' is marked final
    virtual void func() final 
    { 
        cout << "Base implementation" << std::endl;
    }
};

class Derived1 : public Base1 
{
public:
    // This will cause a compilation error: attempting to override a final function
    // void func() override 
    // { 
    //     std::cout << "Derived implementation" << std::endl;
    // }
    void func2() 
    { 
        cout << "Derived implementation" << std::endl;
	}
};



int main()
{
    cout << "C++11 features Final Specifier\n";
	cout << "Using the final Specifier with Class\n";
    cout << "Using the final Specifier with Function\n";

    Derived1 obj;
    obj.func2(); // Calls Base implementation
  
    return 0;       
}
