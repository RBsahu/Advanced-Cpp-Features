// C++11 Features Demonstration with code example
#include <iostream>
#include<cstring>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Test
{
    int data;
public:
    // 'auto' cannot be used for non-static class members in C++11
        //auto i = 22;
    Test()
    {
        data = 11;
    }
    void show() const {
        cout << "Auto cannot be used as class member variable" << endl;
        cout << data << endl;
    }
};

int main()
{
    cout << "C++11 features demonstration\n\n";
    cout << "auto keyword:\n";
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

    // Using auto in range-based for loop
    vector<int> v = { 1, 2, 3, 4, 5 };
    cout << "Display Vector Elements: ";
    for (auto i : v)
        cout << i << " ";
    cout << endl;

    Test t;
    t.show();

    // Using auto in map iteration
    map<int, string> m;
    m.insert({ 1, "Ram" });
    m.insert({ 2, "Balak" });
    m.insert({ 3, "Sahu" });
    m.insert({ 4, "Test" });

    cout << "Display Map Elements:\n";
    for (const auto& x : m)
        cout << x.first << " --> " << x.second << endl;

    // Invalid example: 'auto' cannot be used as a function parameter type in C++11
    // void test(auto x); //  Error   
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
	cout<<"\n capture by value :"<<sum();
	cout<<"\n capture by reference :" << modify();
    cout<<"\nAfter modify: x1 = " << x1 << ", y1 = " << y1 << "\n";

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
    class Base
    {
        char* str;
    public:
        Base() {}
        Base(const char* s)
        {
            str = new char(sizeof(s));
            strcpy_s(str,sizeof(str), s);
        }
        Base(const Base& b)
        {
            str = new char(sizeof(b.str));
            strcpy_s(str, sizeof(str), b.str);            
        }
        void printString()
        {
            cout << "\nString :" << str << endl;
        }
    };
    Base b1;
    Base b2("Ram");
    b2.printString();

    auto object = [](Base b)
        {
            b.printString();
        };

    Base b4 = b2;
    object(b4);

    return 0;
}
