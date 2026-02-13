// code example for Digit Separator
/*
Definition:
In C++14 and later, the single quote character (') is used as a digit separator 
within numeric literals to improve code readability. 
The compiler ignores the separator,so it does not affect the actual numeric value.

*/

#include <iostream>
#include <iomanip> // std::setprecision is defined in:
using namespace std;

int main()
{    
	cout << "\n Digit Separator with Examples :"<<endl;
    long long int a = 1'23'456;
    long long int b = 12'34'56;
    long long int c = 123'456;

    // Print all the value
    cout << "a:" << a << endl;
    cout << "b:" << b << endl;
    cout << "c:" << c << endl;

    // Example 1: Integer literal
    long long large_number = 1'000'000'000; // Represents one billion
    cout << "Large integer: " << large_number << endl;

    // Example 2: Floating-point literal
    double pi = 3.14159'26535'89793; // Separators in both integral and fractional parts
    cout << "Pi value: " << fixed << setprecision(15) << pi << endl;

    // Example 3: Hexadecimal literal
    unsigned int hex_value = 0xFF'FF'FF'FF; // Separators in hexadecimal
    cout << "Hexadecimal (decimal): " << hex_value << endl;
    cout << "Hexadecimal (hex): 0x" << hex << hex_value << endl;

    // Example 4: Binary literal (also introduced in C++14)
    int binary_value = 0b1100'0000'1111'1111; // Separators in binary
    cout << "Binary (decimal): " << dec << binary_value << endl;
    
    cout << endl;    
}
