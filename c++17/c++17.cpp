// c++17.cpp : Features Demonstration with code example

#include <iostream>
#include <tuple>
#include <map>
#include<optional>
#include<variant>
#include <any>
#include <type_traits> // For std::is_integral_v
#include<string_view>
#include <vector>
#include <algorithm>
#include <execution>

using namespace std;

//Inline Variables
struct Test {
    inline static int count = 0;
};

// std::optional
optional<int> getValue(bool flag)
{
    if (flag) 
    {
        return 42;
    } else 
    {
        return nullopt;
    }
}
optional<string> getID(int id)
{
    if (id == 101)
    {
        return "Admin";
    }
    else
    {
        return "NormalUser";
    }       

    return nullopt;
}
//if constexpr
template <typename T>
void print_type(T value) 
{
    if constexpr (is_integral_v<T>) 
    {
        cout << "integral type: " << value <<endl;
    }
    else if constexpr (std::is_floating_point_v<T>)
    {
        cout << "floating-point type : " << value <<endl;
    }
    else {
        cout << "This is a non-numeric type: " << value <<endl;
    }
}
//std::string_view
void printString(string_view str)
{
    cout << "String View :" << str << endl;
}

// C++17 Nested Namespace Definition
namespace Company::Department::Project 
{
    void showInfo() 
    {
        cout << "Welcome to Company::Department::Project\n";
    }

    namespace Utils 
    {
        void helper() 
        {
            cout << "Inside Company::Department::Project::Utils\n";
        }
    }
}



int main()
{
    cout << "C++ 17 Features :\n";
    cout << "\n=== Structured Bindings === :"<<endl;
    pair<int, std::string> person = { 101, "Ram" };

    // Structured binding – C++17 feature
    auto [id, name] = person;

    cout << "ID   : " << id << std::endl;
    cout << "Name : " << name <<endl;

    map<std::string, int> scores = {
        {"Alice", 85}, {"Bob", 92}, {"Charlie", 78}
    };

    for (const auto& [name, score] : scores) {
        cout << name << " scored " << score <<endl;
    }

	tuple<int, double> t(1,2.5);
    int x = std::get<0>(t);
    double y = std::get<1>(t);

    cout << x << ", " << y << endl; // 1, 2.5

    cout << "\n=== if and switch with Initializers === :"<<endl;
    if (int x = 5; x > 0) 
    {
        cout << x << " is positive" << endl;
    }

    cout << "\n=== Inline Variables === :"<<endl;
    cout << Test::count << endl;

    cout << "\n=== optional === :"<<endl;
    auto val = getValue(true);
    if (val)
        cout << "Value :" << *val << endl;

    optional<string> user1 = getID(101);
    if(user1)
        cout << "User1 ID: " << *user1 << endl;
    else
        cout << "User1 ID 101 not found: "<< endl;

	optional<string> user2 = getID(202);
    if (user2)
        cout << "User2 ID: " << *user2 << endl;
    else
        cout << "User2 ID 102 not found: " << endl;

    cout << "\n=== std::variant === :"<<endl;
    variant<int, string> data;
    data = 11;
    cout <<" "<< get<int>(data);
    data = "Ram";
    cout <<" "<< get<string>(data);
    cout << endl;

    cout << "\n=== std::any === :"<<endl;
    any a  = 10;
    cout << " " << any_cast<int>(a);
	a = "Hello";
	cout << " " << any_cast<const char*>(a);
    cout << endl;

    cout << "\n=== if constexpr === :"<<endl;
    print_type(10);        // Calls the integral branch
    print_type(3.14);      // Calls the floating-point branch
    print_type("Hello");   // Calls the non-numeric branch
    print_type('A');       // Calls the integral branch (char is integral)
        
    cout << "\n=== std::string_view === :"<<endl;
    string s = "Hello";
    printString(s);
	printString("World");

    cout << "\n=== Nested namespaces === :" << endl;
    // Accessing functions inside nested namespaces
    Company::Department::Project::showInfo();
    Company::Department::Project::Utils::helper();

    cout << "\n=== Parallel Algorithms === :" << endl;
    vector<int> v = { 5, 3, 1, 4, 2 };
    sort(execution::par, v.begin(), v.end());
    for (auto i : v) 
        cout << i << " "; // 1 2 3 4 5

    vector<int> data1(1000, 1); // 1000 elements, all 1

    // Parallel reduction
    int sum = reduce(execution::par, data1.begin(), data1.end());

    cout << "\nSum = " << sum << "\n";
    cout << endl;
    
    cout << "\n=== End of Program ===" << endl;
    cout << endl;

    return 0;
}

