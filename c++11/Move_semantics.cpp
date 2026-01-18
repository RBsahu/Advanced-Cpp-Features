//code example for Move semantics in C++11
/*
Definition:
Move Semantics transfers resources from one object to another, avoiding deep copies and
improving performance.
Uses rvalue references (&&), move constructor, move assignment, and std::move().
After move, the source object is valid but empty.
Commonly used in STL containers and resource-managing classes.

Basic Syntax – Move Semantics (C++11)

Type&& rvalueRef;                 // Rvalue reference
ClassName(ClassName&& other);     // Move constructor
ClassName& operator=(ClassName&& other); // Move assignment
std::move(object);                // Convert to rvalue

Use Cases – Move Semantics (C++11)
To avoid expensive deep copies of objects holding dynamic memoryWhen returning objects from functions
During STL container reallocation (e.g., std::vector resize)
To transfer ownership of resources safely
To improve performance with temporary objects

*/

#include <iostream>
using namespace std;

//Implement own move constructor c++
class Test
{
private:
	int* data;
public:
	Test() {}
	Test(int value)
	{
		data = new int(value);
	}
	~Test()
	{
		delete data;
	}
	Test(Test&& t) noexcept
	{
		data = t.data;
		t.data = nullptr;
	}
	Test& operator=(Test&& t) noexcept
	{
		if (this != &t)
		{
			delete data; // Free existing resource
			data = t.data; // Transfer ownership
			t.data = nullptr; // Nullify source

		}
		return *this;
	}
	Test(const Test& t)
	{
		data = new int;
		data = t.data;
	}
	Test& operator=(const Test& t) = delete;
	// Function to  the value
	void Printdata()
	{
		if (data)
		{
			cout << "Data :" << *data << endl;
		}
		else
		{
			cout << "Data is NULL :" << endl;
		}
	}
};


int main()
{
    cout << " C++11 features Move semantics\n";
	Test t1(11);
	cout << " Object t1 ";
	t1.Printdata();

	Test t2 = move(t1);
	cout << " Object t2 ";
	t2.Printdata();

	Test t3 = t1;
	cout << " Object t3 ";
	t3.Printdata();

	Test t4 = t2;
	cout << " Object t4 ";
	t4.Printdata();


	cout << "\n\n End of Program \n";
    return 0;       
}
