/*
Abstract Factory Pattern – Definition
Abstract Factory is a creational design pattern that provides an interface for 
creating families of related or dependent objects without specifying their concrete
classes.

Factory creates one object
Abstract Factory creates group of related objects

Real-Time Example
Imagine:
GUI Toolkit supports:
Windows OS
Linux OS
Each OS needs:
 Button
 Checkbox
 Now:

Windows = WindowsButton + WindowsCheckbox
Linux = LinuxButton + LinuxCheckbox
Client should not know which one is created.

Advantages
 Family of related objects created together
 Client independent of concrete class
 Supports Open/Closed Principle
 Ensures compatibility among products
*/

//Step 1: Abstract Product Interfaces
#include<iostream>
using namespace std;

// Button Interface
class Button
{
public:
    virtual void paint() = 0;
};

// Checkbox Interface
class Checkbox
{
public:
    virtual void paint() = 0;
};
//Step 2: Concrete Products(Windows)
class WindowsButton : public Button
{
public:
    void paint()
    {
        cout << "Windows Button\n";
    }
};

class WindowsCheckbox : public Checkbox
{
public:
    void paint()
    {
        cout << "Windows Checkbox\n";
    }
};
//Step 3: Concrete Products (Linux)
class LinuxButton : public Button
{
public:
    void paint()
    {
        cout << "Linux Button\n";
    }
};

class LinuxCheckbox : public Checkbox
{
public:
    void paint()
    {
        cout << "Linux Checkbox\n";
    }
};
//Step 4: Abstract Factory Interface
class GUIFactory
{
public:
    virtual Button* createButton() = 0;
    virtual Checkbox* createCheckbox() = 0;
};
//Step 5: Concrete Factories
class WindowsFactory : public GUIFactory
{
public:
    Button* createButton()
    {
        return new WindowsButton();
    }

    Checkbox* createCheckbox()
    {
        return new WindowsCheckbox();
    }
};

class LinuxFactory : public GUIFactory
{
public:
    Button* createButton()
    {
        return new LinuxButton();
    }

    Checkbox* createCheckbox()
    {
        return new LinuxCheckbox();
    }
};
//Step 6: Client Code
int main()
{
    GUIFactory* factory;

    // Suppose OS is Windows
    factory = new WindowsFactory();

    Button* btn = factory->createButton();
    Checkbox* chk = factory->createCheckbox();

    btn->paint();
    chk->paint();

	factory = new LinuxFactory();
	Button* linuxBtn = factory->createButton();
	Checkbox* linuxChk = factory->createCheckbox();
	linuxBtn->paint();
	linuxChk->paint();

    return 0;
}