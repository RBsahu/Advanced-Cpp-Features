// Generic Lambda Function with code example
/*
Definition:
A Lambda function in C++14 is an anonymous function (function without a name) that can be 
defined inline and used for short, one-time operations.
A lambda is a callable object that can capture variables from its surrounding scope and 
execute logic without writing a separate function.

Basic Syntax:
// Generic lambda with automatic return type deduction
auto generic_lambda = [](auto param1, auto param2) 
{
    // function body
    return param1 + param2;
};

Capture List and Meaning:
[]	Capture nothing
[x]	Capture x by value
[&x]	Capture x by reference
[=]	Capture all by value
[&]	Capture all by reference

Use Cases
Real-Time Use Cases (Industry Level)

1. STL Algorithms
std::sort
std::transform
std::for_each

2. Callback Systems
Event dispatchers
Thread pools
Task schedulers

3. Template Replacement
Avoid writing:

template<typename T>
void print(T value);

Instead use:
auto print = [](auto value){};

Cleaner + local scope + readable.

*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// for Generic Lambda Function
auto add = [](auto a, auto b)
    {
        return (a + b);
    };

int main()
{    
	cout << "\n Basic Example :";
    cout << "\n Adding integers :" << add(10, 20);
    cout << "\n Adding doubles  :" << add(3.25, 25);  

    string s1 = "Hello ";
    string s2 = "Ram";
    string sum_str = add(s1, s2);
	cout << "\n Adding strings  :" << sum_str;

    cout << "\n Generic Lambda with STL :";
    //Cleaner than writing a template functor.
    vector<int> vec = { 5, 2, 8, 1 };
    sort(vec.begin(), vec.end(),
        [](auto a, auto b)
        {
            return a > b;   // Descending
        });

    for (auto v : vec)
        cout << v << " ";

	cout << "\n\n Basic Working Example :"<<endl;
    // Generic lambda (C++14)
    auto print = [](auto value)
        {
            cout << value <<endl;
        };

    print(10);                 // int
    print(3.14);               // double
    print("Hello Ram");        // const char*
    print(string("C++14")); // string
        
    cout << "\nBetter Version(Avoid Copies ) :" << endl;

    auto print1 = [](const auto& value)
        {
            cout << value << endl;
        };

    string big = "High performance C++";
    print1(big);   // No copy

    cout << "\nPrinting Containers (Real STL Usage) :" << endl;
    vector<int> data = { 1, 2, 3, 4, 5 };

    auto print2 = [](const auto& container)
        {
            for (const auto& item : container)
                cout << item << " ";
            cout << std::endl;
        };

    print2(data);

    cout << endl;    
}
