//Definition/Syntax/Uses and code example for range-based for loop in C++11

/*

Definition
The range-based for loop is a simpler form of the for loop.
It runs the loop over a group of elements that can be iterated, such as arrays, strings, 
and STL containers.

Syntax
for (declaration: range)
{
    // statements
}
where,
declaration: Declaration of the variable that will be used to represent each element of the range.
range: Name of the range.

Advantages:
Simplicity: No need to calculate container size or manually increment counters.
Readability: More concise than traditional for loops.
Limitations:
Whole Collection Only: It always iterates from start to finish; 
No Index Access:

 */

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    cout << "C++11 features range-based for loop\n";

	cout << "\nBasic Iteration (By Value):\n";
	int arr[] = { 10, 20, 30, 40, 50 };
	for (int x : arr)
		cout << x << " ";

	cout << "\nModifying Elements (By Reference):\n";
    vector<int> numbers = { 1, 2, 3, 4, 5 };

    for (auto& n : numbers) 
    {
        n *= 10; // Multiplies each original element by 10
    }
    // Prints: 10 20 30 40 50
    for (int n : numbers)
    {
        cout << n << " ";
    }
	cout << "\nEfficient Read-Only Access (By Const Reference) :\n";
    vector<string> fruits = { "Apple", "Banana", "Cherry" };

    for (const auto& fruit : fruits) 
    {
        cout << fruit <<endl;
    }


    cout << endl;
}
