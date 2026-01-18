//code example for enum class in C++11
/*
Definition:
enum class provide:
Strong type safety
Scoped names
No implicit conversion to int

Basic Syntax:
enum class EnumName : underlying_type
{
    VALUE1,
    VALUE2,
    VALUE3
};
underlying_type is optional (default is int)
Values are accessed using scope resolution EnumName::VALUE

Use Cases of enum class
No name collision
No implicit conversion to int
Avoids name collisions
Improves type safety

*/

#include <iostream>
using namespace std;


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

	cout << "\n Simple Code Example :\n";
    Color c = Color::Red;

    if (c == Color::Red) 
    {
        cout << " Color is Red" << endl;
    }

    cout << "\n enum class with Explicit Underlying Type :\n";
    ErrorCode err = ErrorCode::NOT_FOUND;

    cout << " Error code value: " << static_cast<int>(err) << endl;

	cout << "\n Comparison Between Two enum class Types (Not Allowed) :\n";
    enum class A { X };
    enum class B { X };

    // if (A::X == B::X)  Compilation error

    cout << "\n Device State :";
    DeviceState current = DeviceState::ON;
    printState(current);


    // Problem with Traditional enum
    //enum Color { Red, Green };
    //enum Traffic { Red, Yellow };    
    
    //Color c = Red;      // Ambiguous

    //Solution using enum class
    enum class Color { Red, Green };
    enum class Traffic { Red, Yellow };
    Color cc = Color::Red;
    Traffic t = Traffic::Red;   

	cout << "\n\n End of Program \n";
    return 0;       
}
