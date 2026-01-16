//code example for static_assert in C++11
/*
Definition
Static Assertions (static_assert): Enables compile-time checking of conditions.
It allows the programmer to check a condition during compilation.
If the condition evaluates to false, compilation fails with a 
user-defined error message.
It helps catch logic, type, or configuration errors early, before the program runs.

Syntax
static_assert(constant_expression, "error_message");

Rules
constant_expression must be evaluated at compile time.
error_message must be a string literal.
No runtime overhead.

Use Case
Enforce template constraints
Prevent invalid template instantiations
Template constraints
Type checking
Platform assumptions
Memory/layout validation

 */

#include <iostream>
using namespace std;

//static_assert for Array Size Validation
template<typename T>
void processData()
{
    static_assert(is_integral<T>::value,"T must be an integral type");
}

// Function to print array elements
//static_assert for Array Size Validation
template<size_t N>
void printArray(int(&arr)[N])
{
    static_assert(N <= 10, "Array size must not exceed 10");

    for (size_t i = 0; i < N; ++i)
        cout << arr[i] << " ";
}

int main()
{
    cout << " C++11 features static_assert\n";

	cout << "\n Simple Code Example :\n";
    // Compiles only if int is at least 4 bytes
    // otherwise Compilation fails
    static_assert(sizeof(int) >= 4, "int must be at least 4 bytes");
    cout << " Program compiled successfully.\n";

	cout << "\n Type Validation Example :\n";
    processData<int>();     // OK
    //processData<float>(); // Compilation error

	cout << "\n static_assert for Array Size Validation\n";
    int a[5] = { 1,2,3,4,5 };
    int b[15] = { 0 };

    printArray(a);   //  OK
    // printArray(b); //  Compile-time error
     
	cout << "\n\n End of Program \n";
    return 0;       
}
