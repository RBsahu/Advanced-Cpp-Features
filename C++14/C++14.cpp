// C++14 Features Demonstration with code example
#include <iostream>
#include <string>
#include <memory>
using namespace std;
// for Generic Lambda Function
auto sum = [](auto a, auto b)
    {
        return(a + b);
    };

// for Variable Templates 
template<typename T>
constexpr T pi = T(3.1415926535897932385);

//constexpr Function(C++11 Style)
constexpr int square(int x)
{
    return (x * x);
}
// Example 3 – C++14 constexpr with Loops and Conditions
constexpr int factorial(int n)
{
    if (n <= 1)
        return 1;
    else
        return (n * factorial(n - 1));
}

int main()
{
    cout << "C++ 14 Features :\n";
	cout << "\n 1. Generic Lambda Function :";
    cout << "\n Adding integers :" << sum(10, 20);
    cout << "\n Adding doubles :" << sum(3.25, 25);

    string s1 = "C++ ";
    string s2 = "14 ";
    cout << "\n String :" << sum(s1, s2);

    cout << "\n\n 2. Return Type Deduction :";
    auto muliply = [](double x,double y)
        {
        return(x * y);
		};

    cout << "\n Multiply  :"<<muliply(11,5);

    cout << "\n\n 3. Binary Literals :";
    int a = 0b111;
    int b = 0b1010;
    int h = 0x13ac;
    int o = 0117;
    cout << "\nBinary number a :" << a << endl;
    cout << "Binary number b :" << b << endl;
    cout << "Octal  number h :" << b << endl;
    cout << "Hexadecimal   o :" << b << endl;

    cout << "\n 4. Digit Separators:";
    long long int a1 = 1'23'456;
    long long int b1 = 11'23'456;
    long long int c1 = 1'23'45678;

    // Print all the value
    cout << "\na:" << a1 << endl;
    cout << "b:" << b1 << endl;
    cout << "c:" << c1 << endl;

    cout << "\n 5. constexpr  :";
    cout << "\nExample 1 - Simple constexpr Variable  :";

    constexpr int arraySize = 100;
    //allowed, evaluated at compile time
    // OK: arraySize is a constant expression
    int arr[arraySize];
    cout << "\nArray Size :"<<sizeof(arr)/sizeof(arr[0]);
    cout << "\nExample 2 - constexpr Function (C++11 Style)  :";

    constexpr int output = square(9);
    cout << "\nSquare (compile-time): " << output << endl;

    cout << "\nExample 3 - C++14 constexpr with Loops and Conditions  :";
    cout << "\nFactorial(runtime): " << factorial(5) << endl; // evaluated at runtime

    cout << "\n\n 6. Variable Templates :";      
    cout << "\npi value as Integer   :" << pi<int>;
    cout << "\npi value as double   :" << pi<double>;
    cout << "\npi value as long double   :" << pi<long double>; 
    cout << endl;
    cout << "\n\n 7. make_unique to create unique_ptr :";

    unique_ptr<int> p1 = make_unique<int>(100);
    auto p2 = make_unique<int>(200);
	cout << "\nValue of p1 :" << *p1;
	cout << "\nValue of p2 :" << *p2;

    cout << endl;
    
}
