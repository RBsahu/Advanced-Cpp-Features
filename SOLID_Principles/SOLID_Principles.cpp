// SOLID_Principles.cpp : Code example for SOLID Principles

#include <iostream>
using namespace std;

// Single Responsibility Principle (SRP)
class Logger
{
public:
    void log(string msg)
    {
        cout << "Log: " << msg << endl;
    }
};
class User {
    string name;
public:
    User(string name) : name(name) {}
    void Msg() {
        cout << "\nHello, " << name << endl;
    }
};
// Open/Closed Principle (OCP)
class Shape {
public:
    virtual void draw() = 0;
    virtual ~Shape() {}
};

class Circle : public Shape {
public:
    void draw() override {
        cout << "\nDrawing Circle" << endl;
    }
};

class Square : public Shape {
public:
    void draw() override {
        cout << "\nDrawing Square" << endl;
    }
};

void createShape(Shape* shape) {
    shape->draw();
}

// Liskov Substitution Principle (LSP)  
class Bird {
public:
    virtual void fly() {
        cout << "Bird is flying" << endl;
    }
};

class Sparrow : public Bird {
public:
    void fly() override {
        cout << "\nSparrow flying" << endl;
    }
};

void makeBirdFly(Bird* b) {
    b->fly();
}
// Interface Segregation Principle (ISP)
class IPrint {
public:
    virtual void print() = 0;
};


class Printer : public IPrint
{
public:
    void print() override
    {
        cout << "\nPrinting document..." << endl;
    }
};

class IScan {
public:
    virtual void scan() = 0;
};

class Scanner : public IScan
{
public:
    void scan() override
    {
        cout << "\nScanning document..." << endl;
    }
};
// Dependency Inversion Principle (DIP)
class IMessage {
public:
    virtual void send(const string& msg) = 0;
};

class Email : public IMessage {
public:
    void send(const string& msg) override {
        cout << "\nSending Email: " << msg << endl;
    }
};

class Notification {
    IMessage* messageService;
public:
    Notification(IMessage* service) : messageService(service) {}
    void notify(const string& msg) {
        messageService->send(msg);
    }
};

int main()
{
    cout << "SOLID Principles\n";
    cout << "\n1.  SRP - Single Responsibility Principle   :";
    User user("Ram");
    user.Msg();

    Logger logger;
    logger.log("\nLog message.");
    cout << "\n2.  OCP - Open/Closed Principle   :";
    Circle c;
    Square s;

    createShape(&c);
    createShape(&s);

    cout << "\n3.  LSP - Liskov Substitution Principle   :";
    Sparrow sparrow;
    makeBirdFly(&sparrow);

    cout << "\n4.  ISP - Interface Segregation Principle   :";
    Printer p;
    p.print();
    Scanner ss;
    ss.scan();

    cout << "\n5.  DIP - Dependency Inversion Principle Principle   :";
    Email email;
    Notification notify(&email);
    notify.notify("\nSOLID principles explained.");
    
    cout << endl;
	return 0;
}

