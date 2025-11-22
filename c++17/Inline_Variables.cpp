//C++17 – Inline Variables Example

/*
 Why inline variables ?
 Example 1 — Inline Global Variable
1. To avoid multiple-definition errors
If you put a global variable in a header file, and include that header in
many .cpp files, the compiler creates multiple copies  linker error.

inline tells the compiler:
Create only one copy of this variable.
2. Works like inline functions
An inline function can appear in many files without issues,
an inline variable can also appear in many files.
3. Useful for:
Global variables placed in header files
Static class members (you don’t need a .cpp definition anymore)
Constants shared across files
Singleton objects

Example 2 — Inline Static Data Member
Before C++17:
You declared static members inside class AND you define them in a .cpp file.
With C++17 inline variables: no need for .cpp definition.

*/

#include <iostream>
#include <string>
using namespace std;

inline int maxUsers = 10;   // only one copy of this variable

// Inline variable
inline string APP_NAME = "MyApplication";

// Inline constant
inline const int MAX_CONNECTIONS = 10;

class Logger
{
public:
    static inline int logLevel = 1;   // inline static member
    static inline string tag = "DEBUG";

    static void log(const string& msg)
    {
        cout << "[" << tag << "] Level " << logLevel << ": " << msg << endl;
    }
};

class Car 
{
public:
    static inline int wheels = 4; // no .cpp needed
};

int main()
{
	cout << "\n=== Inline Variables Example ===\n" << endl;

    cout << "Max User = " << maxUsers <<endl;

    cout << "App Name  : " << APP_NAME << endl;
    cout << "Connections: " << MAX_CONNECTIONS << endl;

    APP_NAME = "NewApp"; // allowed (not const)
    cout << "Updated App Name: " << APP_NAME << endl;

    cout << "\n=== Inline Static Data Member === \n" << endl;

    Logger::log("Application started");

    Logger::logLevel = 2;
    Logger::tag = "INFO";
    Logger::log("Configuration updated");

    cout << "\n=== Inline static class member ===" << endl;
    cout << Car::wheels <<endl;

    cout << "\n=== End of Program ===" << endl;

    return 0;
}
