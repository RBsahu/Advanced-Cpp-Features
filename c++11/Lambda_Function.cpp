// C++11 Lambda Function with Definition/Syntax/Uses and code example

/*
Definition

A Lambda Function in C++11 is an anonymous (unnamed) inline function that 
can be defined at the point of use and can capture variables from its 
surrounding scope.
Lambda functions are mainly used to write short, one-time, function-like
logic without creating a separate function.

Syntax
[capture](parameters) -> return_type {
    function_body;
}
Use of lambda function :
when function is uses only once
The code is small.
Pass a function into another function

 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    cout << "C++11 features Lambda Function\n";

    cout << "Example :Basic Lambda Function(No parameters, no return value)\n ";
    []() {
        cout << "Hello World from a lambda function!\n";
        }(); // The '()' at the end calls the lambda


    cout << "\n Example : Basic Lambda :";
    auto test = []()
        {
            cout << "\n Hello from Lambda function:" << endl;
        };

    // call lamda function
    test();
    cout << "\n Example : Lambda with Parameters and Return :";
    auto add = [](int a, int b)
        {
            return a + b;
        };
    cout << "\nSum = " << add(5, 3) << endl;
    cout << "\n Example : Lambda Capturing Variables :";
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

    cout << "\n Example : Using Lambdas in Loops :";
    for (int i = 1; i <= 3; i++)
    {
        auto print = [i]()
            {
                cout << "Number: " << i << "\n";
            };
        print();
    }

    cout << "\n Example : Lambda Function as Argument in STL Algorithm :";
    vector<int> nums = { 1, 2, 3, 4, 5, 8, 10, 12 };
    
    auto even_count = count_if(nums.begin(), nums.end(), [](int num)
        {
            return num % 2 == 0;
        });

    cout << "\nTotal even number in vector are :" << even_count;

    cout << endl;
}
