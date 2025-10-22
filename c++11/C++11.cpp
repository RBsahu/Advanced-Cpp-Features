// C++11 Features Demonstration with code example
#include <iostream>
#include<cstring>
#include <vector>
#include <map>
#include <algorithm>
#include <memory> // Include for smart pointers
#include <cassert>   // For assert
using namespace std;

class Test1
{

    int data;
public:
    // 'auto' cannot be used for non-static class members in C++11
        //auto i = 22;
    Test1()
    {
        data = 11;
    }

    void show() const {
        cout << "Auto cannot be used as class member variable" << endl;
        cout << data << endl;
    }
};
//C++11 override and final Specifiers
// Base class
class Base {
public:
    virtual void showMessage() {
        cout << "Base::showMessage()" << endl;
    }

    virtual void display() {
        cout << "Base::display()" << endl;
    }

    virtual void greet() final { // final prevents overriding in derived class
        cout << "Base::greet()" << endl;
    }

    virtual ~Base() {} // Always make base destructors virtual
};

// Derived class using override and final
class Derived : public Base {
public:
    void showMessage() override { // Correctly overrides Base::showMessage
        cout << "Derived::showMessage()" << endl;
    }

    // Uncommenting the below line will cause compile-time error:
    // void greet() override { cout << "Derived::greet()" << endl; } //  Error: 'Base::greet' is final

    void display() final { // Cannot be overridden further
        cout << "Derived::display() (final)" << endl;
    }
};

// Further derived class
class Child : public Derived {
public:
    // Uncommenting the below line will cause compile-time error:
    // void display() override { cout << "Child::display()" << endl; } //  Error: 'Derived::display' is final
};

//C++11 Smart Pointers (unique_ptr, shared_ptr, weak_ptr)
class Test
{
private:
    int value;
public:
    Test(int v) : value(v)
    {
        cout << "Test" << value << "constructed" << endl;
    }
    ~Test()
    {
        cout << value << " destroyed" << endl;
    }
    void show() const {
        cout << "Value = " << value << endl;
    }
};

// C++11 Assertions (assert and static_assert)

// Compile-time constant
constexpr int ARRAY_SIZE = 5;

// Function demonstrating runtime assert
void checkPositive(int value)
{
    assert(value > 0 && "Value must be positive!"); // Runtime check
    cout << "Value is positive: " << value << endl;
}

int main()
{

    cout << "C++11 features demonstration\n\n";
    cout << "\n=== Auto Type Deduction ===" << endl;

    /*
    Rules for 'auto' in C++11:
    1. Must have an initializer
    2. Type is deduced at compile time
    3. Cannot deduce type from function parameters or class members
    4. Works well with iterators, lambdas, and templates
    */

    // Must have an initializer
    auto y = 11; // deduced as int
    cout << "\nValue of y: " << y << endl;

    // References and const qualifiers preservation
    int a = 5;
    int const& ref = a;
    const int c = 10;

    cout << "Value of a: " << a << endl;
    cout << "Value of ref: " << ref << endl;
    cout << "Value of c: " << c << endl;

    auto x = ref;      // deduced as int (reference dropped)
    auto z = c;        // deduced as int (const dropped)
    const auto d = c;  // deduced as const int

    cout << "Value of x: " << x << endl;
    cout << "Value of z: " << z << endl;
    cout << "Value of d: " << d << endl;

    //cout << "2. Range-Based for Loop: ";
    cout << "\n=== Range-Based for Loop ===" << endl;

    // Using auto in range-based for loop
    vector<int> v = { 1, 2, 3, 4, 5 };
    cout << "Display Vector Elements: ";
    for (auto i : v)
        cout << i << " ";
    cout << endl;

    Test1 t;
    t.show();

    // Using auto in map iteration
    map<int, string> m;
    m.insert({ 1, "Ram" });
    m.insert({ 2, "Balak" });
    m.insert({ 3, "Sahu" });
    m.insert({ 4, "Test" });

    cout << "\n=== Display Map Elements  ===" << endl;
    for (const auto& x : m)
        cout << x.first << " --> " << x.second << endl;

    // Invalid example: 'auto' cannot be used as a function parameter type in C++11
    // void test(auto x); //  Error

    cout << "\n=== Lambda Function  ===" << endl;
    cout << "\n Example 1: Basic Lambda :";
    auto test = []()
        {
            cout << "\n Hello from Lambda function:" << endl;
        };

    // call lamda function
    test();

    cout << "\n Example 2: Lambda with Parameters and Return :";
    auto add = [](int a, int b)
        {
            return a + b;
        };
    cout << "\nSum = " << add(5, 3) << endl;
    cout << "\n Example 3: Lambda Capturing Variables :";
    int x1 = 10;
    int y1 = 20;
    auto sum = [x1, y1]() // capture by value
        {
            return x1 + y1;
        };
    auto modify = [&x1, &y1]() // capture by reference
        {
            x1 += 10;
            y1 += 20;
            return x1 + y1;
        };

    /// Uses original values of x1 and y1
    cout << "\n capture by value :" << sum();
    cout << "\n capture by reference :" << modify();
    cout << "\nAfter modify: x1 = " << x1 << ", y1 = " << y1 << "\n";

    cout << "\n Example: Capture by this pointer :";
    class capture_this
    {
        int value;
    public:
        capture_this() = default;
        capture_this(int v) :value(v) {}
        void print()
        {
            // [this] lambda access object’s member  value.
            auto show = [this]()
                {
                    cout << "\n Value = " << value << endl;
                };
            show(); // call lambda function show
        }
    };

    capture_this tt(100);
    tt.print();


    cout << "\n Example 4: Lambda in STL Algorithms :";

    vector<int> vec = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    for_each(vec.begin(), vec.end(), [](int n)
        {
            cout << n * n << " "; // print square of each element
        });

    cout << endl;
    class Base1
    {
        char* str;
    public:
        Base1() {}
        Base1(const char* s)
        {
            str = new char(sizeof(s));
            strcpy_s(str, sizeof(str), s);
        }
        Base1(const Base1& b)
        {
            str = new char(sizeof(b.str));
            strcpy_s(str, sizeof(str), b.str);
        }
        void printString()
        {
            cout << "\nString :" << str << endl;
        }
    };
    Base1 b1;
    Base1 b2("Ram");
    b2.printString();

    auto object = [](Base1 b)
        {
            b.printString();
        };

    Base1 b4 = b2;
    object(b4);
    cout << "\n=== Override and Final Specifiers  ===" << endl;

    Base* basePtr = new Derived();
    basePtr->showMessage(); // Calls Derived::showMessage()
    basePtr->display();     // Calls Derived::display()
    basePtr->greet();       // Calls Base::greet() (final)
    delete basePtr;

    cout << "\n Smart Pointers (unique_ptr, shared_ptr, weak_ptr):" << endl;
    cout << "\n=== unique_ptr Example ===" << endl;
    {
        unique_ptr<Test> ptr1 = make_unique<Test>(10);
        ptr1->show();

        // unique_ptr cannot be copied, only moved
        unique_ptr<Test> ptr2 = move(ptr1);
        if (!ptr1)
            cout << "ptr1 is now nullptr after move." << endl;
        ptr2->show();
    } // ptr2 goes out of scope, object automatically deleted

    cout << "\n=== shared_ptr Example ===" << endl;
    {
        shared_ptr<Test> sp1 = make_shared<Test>(20);
        cout << "sp1 use_count = " << sp1.use_count() << endl;

        {
            shared_ptr<Test> sp2 = sp1; // Shared ownership
            cout << "sp1 use_count = " << sp1.use_count() << endl;
            cout << "sp2 use_count = " << sp2.use_count() << endl;
            sp2->show();
        } // sp2 goes out of scope

        cout << "After sp2 destroyed, sp1 use_count = " << sp1.use_count() << endl;
    } // sp1 goes out of scope, object deleted

    cout << "\n=== weak_ptr Example ===" << endl;
    {
        shared_ptr<Test> sp3 = make_shared<Test>(30);
        weak_ptr<Test> wp = sp3; // Weak reference, doesn’t increase count

        cout << "sp3 use_count = " << sp3.use_count() << endl;

        if (auto temp = wp.lock()) { // lock() creates a temporary shared_ptr if object still exists
            cout << "Accessing object through weak_ptr: ";
            temp->show();
        }

        sp3.reset(); // Destroy the managed object
        cout << "sp3 reset. Object destroyed.\n";

        if (wp.expired())
            cout << "weak_ptr expired. Object no longer exists." << endl;
    }



    cout << "\nUniform Initialization (Brace Initialization) :" << endl;
    cout << "=== Uniform Initialization Examples ===" << endl;

    //  Built-in types
    int aa{ 10 };           // Brace initialization
    double bb{ 3.14 };
    cout << "aa = " << a << ", bb = " << bb << endl;
    //  Array initialization
    int arr1[5]{ 1, 2, 3 }; // Remaining elements zero-initialized
    cout << "arr1 = ";
    for (int i = 0; i < 5; ++i)
        cout << arr1[i] << " ";
    cout << endl;

    //  STL container initialization
    vector<int> vec1{ 1, 2, 3, 4, 5 };
    cout << "Vector elements: ";
    for (auto vv : vec1)
        cout << vv << " ";
    cout << endl;


    cout << "\nassert and static_assert :" << endl;
    cout << "=== static_assert Example ===" << endl;

    // Compile-time check
    static_assert(ARRAY_SIZE > 0, "ARRAY_SIZE must be greater than 0");

    int arr[ARRAY_SIZE] = { 1, 2, 3, 4, 5 };
    cout << "Array of size " << ARRAY_SIZE << " created." << endl;

    cout << "\n=== assert Example ===" << endl;
    checkPositive(10);   //  Passes
    //  Uncommenting causes runtime assertion failure  
    // We will get run time error if the value is negative
    //checkPositive(-5); 

    cout << "\n=== End of Program ===" << endl;
    return 0;
}
