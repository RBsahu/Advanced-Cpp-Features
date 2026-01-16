//code example for constexpr in C++11
/*
Definition:
constexpr is used to indicate that a variable, function, or constructor can be 
evaluated at compile time, provided all inputs are known at compile time.
It helps achieve better performance, safer code, and compile-time validation.

Syntax:
constexpr [type] [name] = [value];
Requirements:
Must be initialized at the point of declaration.
The initializer must be a constant expression (computable at compile-time).

Use Case: 
Array sizes, template parameters, constants
constexpr does NOT force compile-time evaluation
It allows both compile-time and run-time evaluation
Real-World Uses of constexpr

Define compile-time constants
Improve performance by avoiding run-time computation
Enable safer template programming
Replace macros (#define)
Embedded systems & performance-critical code
Use with static_assert
Interview One-Liners
"constexpr allows computation at compile time when possible"
"constexpr functions can also run at runtime"
"C++11 constexpr functions are very restrictive"
"constexpr is safer and better than macros"
*/

#include <iostream>
using namespace std;

constexpr int square(int x)
{
    return x * x;
}

constexpr int add(int a, int b)
{
    return a + b;
}
constexpr int maxValue(int a, int b)
{
    return (a > b) ? a : b;
}
class Point
{
public:
    constexpr Point(int x, int y) : x_(x), y_(y) {}

    constexpr int getX() const { return x_; }
    constexpr int getY() const { return y_; }

private:
    int x_;
    int y_;
};

int main()
{
    cout << " C++11 features constexpr\n";

	cout << "\nExample 1: constexpr Variable :\n";
    constexpr int size = 5;
    int arr[size];   // Valid: compile-time constant
    cout << "Array size = " << size << endl;

    cout << "\nExample 2: constexpr Function (Compile-Time) :\n";
    constexpr int result = square(5);  // Evaluated at compile time
    cout << "Square = " << result <<endl;

    cout << "\nExample 3: constexpr Function (Run-Time) :\n";
    int x = 3, y = 4;
    int result2 = add(x, y); // Evaluated at run time
    cout << "Result = " << result2 <<endl;


    cout << "\nExample 4: constexpr with static_assert :\n";
    static_assert(maxValue(10, 20) == 20, "Compile-time check failed");

    cout << "\nExample 5: constexpr Constructor (C++11) :\n";
    constexpr Point p(10, 20);  // Compile-time object
    cout << p.getX() << ", " << p.getY() <<endl;

     
	cout << "\n\n End of Program \n";
    return 0;       
}
