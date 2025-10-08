// C++11.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Test {
    //  Not allowed in C++11: 'auto' for non-static data member
    // auto value = 10; //  Error: ‘auto’ not allowed here
public:
    void show() const {
        cout << "\nAuto cannot be used as class member variable" <<endl;
    }
};

int main()
{
    cout << "C++ 11 features \n\n";
    cout << "auto :\n";

    // Syntax
    //auto variable_name = value;
    /*
    Auto keyword  can be used for any data types.
    auto-typed variables deduced by the compiler based on initializer.
    Rules of auto (C++11)
    1. Must have an initializer
    2. Type deduced at compile time - The compiler determines the type
    during compilation, not runtime.
    3. Cannot deduce from function parameter or member variable
    4. Can be used with iterators, lambdas, templates, etc.

    */

    // compiler error without an initializer
    //auto x;

    //Must have an initializer
    auto y = 11; // deduced as int
    cout << "\n Value of y :" << y << endl;


    //References and const qualifiers preserved
    int a = 5;
    int const& ref = a;
    const int c = 10;
    cout << "\n Value of a :" << a << endl;
    cout << "\n Value of ref :" << ref << endl;
    cout << "\n Value of c :" << c << endl;

    auto x = ref;
    //const auto& y = ref;
    auto z = c;
    const auto d = c; 

    cout << "\n Value of x :" << x << endl;
    //cout << "\n Value of y :" << ref << endl;
    cout << "\n Value of z :" << z << endl;
    cout << "\n Value of d :" << d << endl;

    // Using auto in range-based for loop
    vector<int> v = {1,2,3,4,5};
    cout << "Display Vector Elements :" << endl;
    for (auto i : v)
        cout << i << " ";

    Test t;
    t.show();

    map<int, string> m;
    // Inserting a key value pair
    m.insert({ 1,"Ram" });
    m.insert({ 2,"Balak" });
    m.insert({ 3,"Sahu" });
    m.insert({ 4,"Test" });

    cout << "Display Map Elements :" << endl;
    for (auto const& x : m)
        cout << x.first << "-->" << x.second << endl;
    
    // compiler error - Cannot deduce from function parameter
    //void test(auto x);
}
