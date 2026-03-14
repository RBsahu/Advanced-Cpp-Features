/*
* Set Definition:
set is an associative container that stores unique elements in sorted order.
It is usually implemented using a Red-Black Tree.

Key points:
Elements are automatically sorted
Duplicate elements are NOT allowed
Search/insert/delete complexity		 O(log n)

MultiSet Definition:
ultiset is an associative container that stores elements in sorted order and 
allows duplicate elements.
Key Points:
Allows Duplicate Elements
multiset can store multiple elements with the same value
Elements are Automatically Sorted in ascending order by default.

unordered_set definition:
unordered_set is an associative container that stores unique elements and organizes them
using a hash table.

Key characteristics:
Unique elements only
Unordered storage
Implemented using hash table
Very fast lookup

Important Difference: set, multiset, unordered_set
Feature	                set	            multiset	    unordered_set
Duplicate elements	    Not allowed	    Allowed	        Not allowed
Ordering	            Sorted	        Sorted	        Unordered
Implementation	        Red-Black Tree	Red-Black Tree	Hash Table
Search complexity	    O(log n)	    O(log n)	    O(1) average

Real-World Uses of unordered_set
Fast membership checking
Example:Check if user ID already exists
Removing duplicates
Example:Unique elements from large dataset
Graph algorithms
Example:Visited nodes tracking
Caching systems
Example:
Store unique session tokens

*/

#include <iostream>
#include <set>
#include <unordered_set>
using namespace std;
int main()
{
    set<int> s;
    s.insert(30);
    s.insert(10);
    s.insert(20);
    s.insert(10); // duplicate (ignored)

    cout << "Elements in set:\n";

    for (const auto& x : s)
    {
        cout << x << " ";
    }

	cout << "\nSize of set: " << s.size() << endl;

	cout << "Searching in set :\n";
    auto it = s.find(20);
    if (it != s.end())
        cout << "Element found: " << *it <<endl;
    else
        cout << "Element not found\n";

	cout << "Deleting from set :\n";
    s.erase(20);

    std::cout << "After deletion:\n";
    for (auto x : s)
        cout << x << " ";

    multiset<int> ms;
    ms.insert(30);
    ms.insert(10);
    ms.insert(20);
    ms.insert(10); // duplicate allowed

    cout << "\nElements in multiset:\n";
    for (const auto& x : ms)
    {
        cout << x << " ";
    }

	cout << "\nSize of multiset: " << ms.size() << endl;
	cout << "Searching in multiset :\n";
    auto it1 = ms.find(10);

    if (it1 != ms.end())
        cout << "Element found: " << *it1 <<endl;

    // count() tells how many times a value appears.
	cout << "\nCounting Duplicate Elements :" << endl;
	cout << "Count of 10 in multiset: " << ms.count(10) << endl;
	cout << "\nDeleting from multiset :\n";
	ms.erase(10); // removes all occurrences of 10
    for (auto x : ms)
        cout << x << " ";

    unordered_set<int> us;

    us.insert(30);
    us.insert(10);
    us.insert(20);
    us.insert(10);   // duplicate ignored
    cout << "\nElements in unordered_set:\n";

    for (const auto& x : us)
    {
        cout << x << " ";
    }
	cout << "\nSize of unordered_set: " << us.size() << endl;
	cout << "Searching in unordered_set :\n";

    auto it2 = us.find(20);
    if (it2 != us.end())
        cout << "Element found\n";
    else
        cout << "Element not found\n";
	cout << "\nDeleting from unordered_set :\n";
	us.erase(20);
    for (auto x : us)
        cout << x << " ";
    if (us.count(10))
        cout << "\nElement exists";

	cout << "\n Remove Duplicate Elements from Array :\n";
	int arr[6] = { 10, 20, 30, 10, 20, 40 };
    unordered_set<int> us1;

    for (int x : arr)
        us1.insert(x);
    cout << "Unique elements:\n";
    for (auto x : us1)
        cout << x << " ";

    return 0;
}