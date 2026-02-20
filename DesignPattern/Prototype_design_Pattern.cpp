/*
Prototype Design Pattern – 
Definition (C++)

Prototype is a creational design pattern used to create new objects by copying an 
existing object instead of creating from scratch.
It allows object creation through cloning mechanism using a virtual clone() function.
The cloning process internally uses the copy constructor to duplicate object state.
It supports runtime polymorphic object creation without knowing the exact derived class type.
It avoids expensive object initialization by copying a pre-configured prototype instance.
It reduces object creation cost in performance-critical systems.
It eliminates the need of subclassing for object creation.
It provides flexibility to create complex objects dynamically.

It is useful when object creation is:
time consuming
resource intensive
configuration heavy

It follows:
Encapsulation (object creation hidden)
Open/Closed Principle (new types added easily)

*/
#include<iostream>
using namespace std;

// Prototype Interface
class Shape
{
public:
    // Clone method
    virtual Shape* clone() = 0;

    virtual void draw() = 0;

    virtual ~Shape() {}
};

// Concrete Prototype - Circle
class Circle : public Shape
{
private:
    int radius;

public:
    // Constructor
    Circle(int r)
    {
        radius = r;
    }

    // Copy Constructor
    Circle(const Circle& c)
    {
        radius = c.radius;
    }

    // Clone Method Implementation
    Shape* clone() override
    {
        // Create new object by copying existing one
        return new Circle(*this);
    }

    void draw() override
    {
        cout << "Circle Radius: " << radius << endl;
    }
};

// Concrete Prototype - Square
class Square : public Shape
{
private:
    int side;

public:
    Square(int s)
    {
        side = s;
    }
    // Copy Constructor
    Square(const Square& sq)
    {
        side = sq.side;
    }

    // Clone method
    Shape* clone() override
    {
        return new Square(*this);
    }
    void draw() override
    {
        cout << "Square Side: " << side << endl;
    }
};

int main()
{
    // Create prototype objects
    Shape* c1 = new Circle(10);
    Shape* s1 = new Square(5);

    // Clone prototype objects
    Shape* c2 = c1->clone();
    Shape* s2 = s1->clone();

    c1->draw();
    c2->draw();

    s1->draw();
    s2->draw();

    return 0;
}