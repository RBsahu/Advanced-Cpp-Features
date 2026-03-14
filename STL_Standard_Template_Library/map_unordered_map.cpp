/*
map Definition:
map stores elements in sorted order of keys (by default ascending).

Key Features:
Keys are sorted automatically
No duplicate keys allowed
Iteration gives sorted order
Slower than unordered_map for large datasets

multimap Definition:
multimap is an associative container that stores key-value pairs in sorted order 
and allows multiple elements with the same key.

Key Features:
Duplicate keys allowed
Keys are sorted automatically
Implemented using balanced BST
No operator[] support

unordered_map Definition:
unordered_map stores elements in no particular order.
Key Features:
No ordering of elements
Faster lookup than map
Uses hash function
Iteration order is random

unordered_multimap Definition:
unordered_multimap is an associative container that stores key–value pairs,
allows duplicate keys, and stores elements in no particular order
because it uses a hash table internally.

Key Features:
multimap  allows duplicate keys
unordered_map  hash-based storage (no sorting)

Difference Between  map, multimap,and  unordered_map
Feature	                map	                multimap	    unordered_map
Duplicate keys	        Not allowed	        Allowed	        Not allowed
Ordering	            Sorted	            Sorted	        Unordered
Implementation	        Red-Black Tree	    Red-Black Tree	Hash Table
operator[]	            Yes	                No	            Yes
Search Complexity	    O(log n)	        O(log n)	    O(1) average

Use map when:
You need sorted data
Range queries are needed
Deterministic iteration order

Use unordered_map when:
You need fast lookup
Order does not matter

*/

#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;

int main()
{
    map<int, string> m;
    m[3] = "Ram";
    m[1] = "Balak";
    m[2] = "sahu";
	m[4] = "Ravi";

    cout << "Elements in map (sorted):\n";
    for (const auto& p : m)
    {
        cout << p.first << " : " << p.second << endl;
    }

    //map stores unique keys, so deleting by key removes only one element.
	cout << "\nDelete from map : " << endl;
    // delete by key
    m.erase(2);
    cout << "\nAfter delete key 2:\n";
    for (const auto& p : m)
        cout << p.first << " -> " << p.second << endl;

    multimap<int, string> emp;
    emp.insert({ 101, "Ram" });
    emp.insert({ 102, "Balak" });
    emp.insert({ 101, "Sahu" });   // duplicate key allowed
    emp.insert({ 103, "Ravi" });

    cout << "\nMultimap elements:\n";
    for (const auto& p : emp)
    {
        cout << p.first << " -> " << p.second << endl;
    }

	cout << "\nFinding Elements in multimap :" << endl;
    // Finding Elements in multimapUsing find()
    // it will Returns first occurrence.
    auto it = emp.find(101);
    if (it != emp.end())
    {
        cout << it->first << " " << it->second << endl;
    }
	cout << "Delete from std::multimap : " << endl;
    // delete all elements with key 1
    emp.erase(101);
    cout << "\After delete key 101:\n";
    for (const auto& p : emp)
        cout << p.first << " -> " << p.second << endl;

    unordered_map<int, string> um;
    um[3] = "Ram";
    um[1] = "Balak";
    um[2] = "sahu";

    cout << "\nElements in unordered_map:\n";
    for (const auto& p : um)
    {
        cout << p.first << " : " << p.second << endl;
    }
	cout << "Delete from std::unordered_map : " << endl;
    // delete key
    um.erase(2);
    cout << "\nAfter delete key 2:\n";
    for (const auto& p : um)
        cout << p.first << " -> " << p.second << endl;

    unordered_multimap<int, string> umm;

    umm.insert({ 1, "Ram" });
    umm.insert({ 1, "Amit" });
    umm.insert({ 2, "Ravi" });
    umm.insert({ 3, "Sahu" });

    cout << "Elements in unordered_multimap:\n";

    for (const auto& p : umm)
    {
        cout << p.first << " -> " << p.second << endl;
    }

    //find() returns first matching element.
    cout << "\nFinding Elements in unordered_multimap :" << endl;
    auto it1 = umm.find(1);
    if (it1 != umm.end())
    {
        std::cout << "Found: "
            << it1->first << " -> "
            << it1->second << std::endl;
    }

    //Get All Values with Same Key Use equal_range()
	cout << "\nGet All Values with Same Key in unordered_multimap : " << endl;
    auto range = umm.equal_range(1);
    cout << "Values for key = 1\n";
    for (auto it = range.first; it != range.second; ++it)
    {
        cout << it->second << endl;
    }
    return 0;
}