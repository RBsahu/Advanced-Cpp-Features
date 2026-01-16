//code example for enum class in C++11
/*
Definition:
enum class (also called scoped enumeration) is provides strongly-typed and scope-safe enumerations.

Unlike traditional enum, an enum class:
Does not implicitly convert to integers
Keeps enumerator names inside the enum scope
Avoids name collisions
Improves type safety

Syntax:
Use Cases of enum class
Avoid name conflicts - When multiple enums have same enumerator names
Improve type safety - Prevents accidental comparison with integers or other enums
Large codebases & APIs - Used in modern C++ libraries, embedded systems, and framework APIs
Switch-case clarity - Makes code more readable and maintainable


*/

#include <iostream>
using namespace std;

enum class EnumName 
{
    Enumerator1,
    Enumerator2,
    Enumerator3
};

enum class Color 
{
    Red,
    Green,
    Blue
};

//enum class with Explicit Underlying Type
enum class ErrorCode : int 
{
    OK = 0,
    NOT_FOUND = 404,
    INTERNAL_ERROR = 500
};
//Device State Management (Embedded / System Software)
enum class DeviceState {
    OFF,
    ON,
    SLEEP
};

void printState(DeviceState state) {
    if (state == DeviceState::ON)
        cout << "Device is ON" << endl;
}

int main()
{
    cout << " C++11 features enum class\n";

	cout << "\nBasic Code Example :\n";
    Color c = Color::Red;

    if (c == Color::Red) 
    {
        cout << "Color is Red" << endl;
    }

    cout << "\nenum class with Explicit Underlying Type :\n";
    ErrorCode err = ErrorCode::NOT_FOUND;

    cout << "Error code value: " << static_cast<int>(err) << endl;

	cout << "\n Comparison Between Two enum class Types (Not Allowed) :\n";
    enum class A { X };
    enum class B { X };

    // if (A::X == B::X)  Compilation error

    cout << "\n Real-Time Use Case Example Device State Management(Embedded / System Software)";
    DeviceState current = DeviceState::ON;
    printState(current);


	cout << "\n\n End of Program \n";
    return 0;       
}
