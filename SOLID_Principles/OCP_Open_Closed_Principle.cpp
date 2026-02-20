
/*
 Open–Closed Principle (OCP) — Definition
 Software entities (classes, modules, functions) should be:
 Open for Extension
 Closed for Modification

You should be able to add new behavior
without modifying existing code

We should extend a class behavior,not modify existing working code.
Because modifying existing code may:
Introduce bugs
Break regression-tested modules
Impact deployed systems
Violate backward compatibility

Why This Follows OCP?

If tomorrow you need:
Pentagon
Ellipse
Hexagon
You just create:

*/


#include<iostream>
using namespace std;

// ---------------- Base Abstract Class ----------------
class Shape
{
public:
    virtual double area() = 0;
    virtual ~Shape() {}
};

// ---------------- Derived Classes ----------------
class Circle : public Shape
{
    double radius;

public:
    Circle(double r) : radius(r) {}

    double area() override
    {
        return 3.14 * radius * radius;
    }
};

class Rectangle : public Shape
{
    double length, width;

public:
    Rectangle(double l, double w) : length(l), width(w) {}

    double area() override
    {
        return length * width;
    }
};

class Triangle : public Shape
{
    double base, height;

public:
    Triangle(double b, double h) : base(b), height(h) {}

    double area() override
    {
        return 0.5 * base * height;
    }
};

// ----------- New Shape Added Without Modifying Old Code -----------
class Square : public Shape
{
    double side;

public:
    Square(double s) : side(s) {}

    double area() override
    {
        return side * side;
    }
};

// ---------------- Area Calculator ----------------
class AreaCalculator
{
public:
    double calculateArea(Shape* shape)
    {
        return shape->area();
    }
};

// ---------------- Main Function ----------------
int main()
{
    AreaCalculator calculator;

    Shape* circle = new Circle(5);
    Shape* rectangle = new Rectangle(4, 6);
    Shape* triangle = new Triangle(4, 6);
    Shape* square = new Square(5);

    cout << "Circle Area: " << calculator.calculateArea(circle) << endl;
    cout << "Rectangle Area: " << calculator.calculateArea(rectangle) << endl;
    cout << "Triangle Area: " << calculator.calculateArea(triangle) << endl;
    cout << "Square Area: " << calculator.calculateArea(square) << endl;

    delete circle;
    delete rectangle;
    delete triangle;
    delete square;

    return 0;
}