// C++11 auto Features with Definition/Syntax/Uses and code example

/*
Definition
auto keyword is used for automatic type deduction, which instructs the 
compiler to deduce the type of a variable from its initializer 
at compile time.

Syntax
auto variable_name = initializer;

Restrictions/Limitations of auto
Cannot be used without initializer
auto x;   // ERROR
Cannot deduce function parameters (C++11)
void func(auto x);  // ERROR in C++11
(Allowed only from C++20)
Cannot deduce different types in same statement
auto x = 10, y = 3.14;  // ERROR
Cannot replace explicit interface types
auto getData();  // NOT allowed in C++11
(C++14 allows auto return type with trailing return)
Works well with iterators, lambdas, and templates
 */

#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main()
{
    cout << "C++11 features auto";
    cout << "\n=== Auto with variable declaration ===" << endl;     

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
    
    cout << "\n=== Auto with Range-Based for Loop ===" << endl;
    // Using auto in range-based for loop
    vector<int> v = { 1, 2, 3, 4, 5 };
    cout << "Display Vector Elements: ";
    for (auto i : v)
        cout << i << " ";
   
    cout << endl;
    cout << "\n=== Auto with Map ===" << endl;
    // Using auto in map iteration
    map<int, string> m;
    m.insert({ 1, "Ram" });
    m.insert({ 2, "Balak" });
    m.insert({ 3, "Sahu" });
    m.insert({ 4, "Test" });
 
    for (const auto& x : m)
        cout << x.first << " --> " << x.second << endl;

    cout << "\n=== Auto with Lambda Function  ===" << endl;
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
    // Uses original values of x1 and y1
    cout << "\n capture by value :" << sum();
    cout << "\n capture by reference :" << modify();
    cout << "\nAfter modify: x1 = " << x1 << ", y1 = " << y1 << "\n";
}
