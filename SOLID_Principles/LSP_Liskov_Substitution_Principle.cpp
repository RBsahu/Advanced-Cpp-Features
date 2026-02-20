
/*

Liskov Substitution Principle (LSP) — Definition

Derived class objects must be substitutable for their base class objects
without breaking the program.

Which means:
Child class should behave like the parent class
Derived class should not change expected behavior

In Simple Words:
If B is derived from A,
then object of B should be usable wherever A is expected
without changing correctness of the program

LSP Violation (Classic Rectangle–Square Problem)
Step 1: Base Class

class Rectangle
{
protected:
    int width, height;
public:
    virtual void setWidth(int w)
    {
        width = w;
    }
    virtual void setHeight(int h)
    {
        height = h;
    }
    int getArea()
    {
        return width * height;
    }
};
Step 2: Derived Class (Wrong Design)
class Square : public Rectangle
{
public:
    void setWidth(int w) override
    {
        width = height = w;
    }

    void setHeight(int h) override
    {
        width = height = h;
    }
};
Step 3: Main Function
#include<iostream>
using namespace std;

void calculateArea(Rectangle& r)
{
    r.setWidth(5);
    r.setHeight(4);

    cout << "Expected Area = 20\n";
    cout << "Actual Area = " << r.getArea() << endl;
}

int main()
{
    Rectangle rect;
    Square square;

    calculateArea(rect);    // Works fine
    calculateArea(square);  //  Problem

    return 0;
}
Output:
Expected Area = 20
Actual Area = 25
Why?
Because:
square.setWidth(5);
square.setHeight(4);
Internally becomes:
width = height = 4;

So:
 Behavior changed
 Base class contract broken
 Program correctness affected

 LSP Violated
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