// DesignPattern.cpp : Code example for Design Pattern

#include <iostream>
#include<mutex>
#include<vector> 

using namespace std;

//Singleton Design
mutex m;

class singleton
{
    singleton();
    static singleton* obj;
public:
    static singleton* getobj();

};
singleton::singleton()
{
    cout << "\nObject created :" << endl;
}
singleton* singleton::obj = nullptr;
singleton* singleton::getobj()
{
    unique_lock<mutex> lock(m);
    if (obj == nullptr)
    {
        obj = new singleton();
    }
    lock.unlock();  
    return obj;
}

//Observer design pattern
class Observer
{
public:
    virtual void update(float t) = 0;
};

class display :public Observer
{
public:
    void update(float temp)
    {
        cout << "Temp :" << temp << endl;
    }
};
class weather
{
private:
    float temp;
    vector<Observer*> v;
public:
    void attached(Observer* ob)
    {
        v.push_back(ob);
    }
    void dettached(Observer* ob)
    {
        v.clear();
    }
    void notify()
    {
        for (Observer* ob : v)
        {
            ob->update(temp);
        }
    }
    void setData(float t)
    {
        temp = t;
        notify();
    }
};
// Factory pattern
class shape
{
public:
    virtual void draw() = 0;
    static shape* create(string type);
};

class circle :public shape
{
public:
    void draw()
    {
        cout << " Draw circle ..." << endl;
    }
};

class Square :public shape
{
public:
    void draw()
    {
        cout << " Draw Square ..." << endl;
    }
};

shape* shape::create(string type)
{
    if (type == "circle")
        return new circle();
    if (type == "Square")
        return new Square();
    return 0;
}
//Prototype  Design Patterns
// Step 1: Define an Abstract Base Class
class Shape
{
public:
    virtual Shape* clone() const = 0; // Clone method for creating copies.
    virtual void draw() const = 0; // Draw method for shape.
    // Virtual destructor for proper cleanup.
    virtual ~Shape()
    {
        cout << " Virtual destructor :" << endl;
    }
};
//Step 2: Create Concrete Prototype Classes
class Circle : public Shape
{
private:
    double radius;
public:
    Circle()
    {
        radius = 10;
    }
    Circle(double r) : radius(r) {}
    Shape* clone() const override
    {
        return new Circle(*this);
    }
    void draw() const override
    {
        cout << "Drawing a circle with radius " << radius << endl;
    }
};
class Rectangle : public Shape
{
private:
    double width;
    double height;
public:
    Rectangle()
    {
        width = 11;
        height = 22;
    }
    Rectangle(double w, double h) : width(w), height(h) {}
    Shape* clone() const override {
        return new Rectangle(*this);
    }
    void draw() const override
    {
        cout << "Drawing a rectangle with width " << width << " and height " << height << endl;
    }
};


int main()
{
    cout << "Design Pattern\n";
    cout << "\n===  Thread safe Singleton Design pattern ===:"<<endl;
    singleton* s1 = singleton::getobj();
    singleton* s2;
    s2 = singleton::getobj();
   
    cout << "\n===  Observer design pattern ===:" << endl;

    weather w;
    display d1, d2;
    w.attached(&d1);
    w.setData(21.13);

    cout << "\n===  Factory pattern ===:" << endl;
    shape* obj1 = shape::create("circle");
    shape* obj2 = shape::create("Square");

    obj1->draw();
    obj2->draw();

    cout << "\n=== Prototype  Design Patterns ===:" << endl;
    Circle c;
    c.draw();
    Rectangle r;
    r.draw();
    cout << "Making clone object :" << endl;
	Shape* c1 = c.clone();
	Shape* r1 = r.clone();
	c1->draw();
	r1->draw();  
    
    cout << "\n=== End of Program ===" << endl;
    cout << endl;
    return 0;
}

