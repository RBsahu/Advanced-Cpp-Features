/*
Factory Design Pattern – 
Definition
Factory method is a creational design pattern which solves the problem of 
creating product objects without specifying their concrete classes.
Instead of creating objects directly using new, you define a method 
(called a factory method) to create objects.
Why Use It?
To simplify object creation.
To hide the details of which class is being instantiated.
To allow different types of objects to be created through a common interface.
To decide object type dynamically at runtime.

*/
#include<iostream>
using namespace std;

// Abstract Base Class
// Common interface for all shapes
class shape
{
public:
    // Pure virtual function
    virtual void draw() = 0;

    // Static factory method
    // Responsible for object creation
    static shape* create(string type);
};

// Concrete Class - Circle
class circle : public shape
{
public:
    void draw()
    {
        cout << "Draw circle ..." << endl;
    }
};

// Concrete Class - Square
class Square : public shape
{
public:
    void draw()
    {
        cout << "Draw Square ..." << endl;
    }
};

// Factory Method Implementation
shape* shape::create(string type)
{
    // Object creation based on input
    if (type == "circle")
        return new circle(); 

    if (type == "Square")
        return new Square();

    return nullptr;   // if invalid type
}

//Modern C++ Fix(Recommended) Use smart pointer :
static unique_ptr<shape> create(string type)
{
    if (type == "circle")
        return make_unique<circle>();

    if (type == "Square")
        return make_unique<Square>();

    return nullptr;
}

int main()
{
    cout << "Factory pattern :" << endl;

    // Client does not create object directly
    shape* s1 = shape::create("circle");
    shape* s2 = shape::create("Square");

    // Use common interface
    s1->draw();
    s2->draw();

    return 0;
}