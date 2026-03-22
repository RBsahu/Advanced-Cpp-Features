/*
Definition:
Vector is a dynamic array that can automatically resize when elements are added or removed.
vector stores elements in contiguous memory.
Doubling strategy - capacity grows (~2x)
push_back() - amortized O(1)
insert() / erase() - O(n)
Prefer reserve() to avoid reallocations
Difference between:
size() - elements count
capacity() - allocated memory

Uses:
Dynamic size array (no need to predefine size)
Fast access using index (like array)
Efficient insertion/removal at end

empty() – Check if Empty
clear() – Remove All Elements
push_back() – Insert Element
pop_back() – Remove Last Element
size() – Number of Elements
capacity() – Allocated Storage
resize() – Change Size
reserve() – Pre-allocate Memory
at() – Safe Access
operator[] – Fast Access
front() & back()
insert() – Insert at Position
erase() – Remove Element
assign() – Assign Values
swap() – Swap Two Vectors
Iterators (begin, end)

*/
#include <iostream>
#include<vector>
using namespace std;

int main()
{
    vector<int> v;
    cout << " Vector size :" << v.size();
    cout << "\n Vector capacity :" << v.capacity();

    if (v.empty())
        cout << "\nVector is empty :";

    v.push_back(11); 
    v.push_back(22); 
    v.push_back(33);    

    v.erase(v.begin() + 1);
    for (int x : v)
        cout << x << " ";

    cout << "\n Vector size :" << v.size();
    cout << "\n Vector capacity :" << v.capacity()<<endl;

    // Insert element 8 at index 2
    v.insert(v.begin() + 2, 8);

    for (auto i : v)
        cout << i << " ";

    v.pop_back();    

    v.resize(10, 100); // add elements
    cout << "\n Vector size :" << v.size();
    cout << "\n Vector capacity :" << v.capacity() << endl;
    for (auto i : v)
        cout << i << " ";

    v.resize(5); // add elements
    cout << "\n Vector size :" << v.size();
    cout << "\n Vector capacity :" << v.capacity() << endl;
    for (auto i : v)
        cout << i << " ";

    v.reserve(10);
    cout << "\nCapacity: " << v.capacity();
    cout << "\n operator[]  Fast Access: " << v[0]; 
	cout << "\n operator[]  Fast Access: " << v[1]; 
    cout <<"\nat()  Safe Access :"<< v.at(3); // safe access

    cout << "\nFront: " << v.front() << endl;
    cout << "Back: " << v.back() << endl;

    v.clear();
    cout << "Size after clear: " << v.size();

    v.insert(v.begin(), 3);
    cout << endl;
    for (int x : v)
        cout << x << " ";

    
    vector<int> v1;
    v.assign(5, 100);  
    for (int x : v1)
        cout << x << " ";

	cout << "\n Swap Two Vectors :" << endl;
    vector<int> v11 = { 1,2 };
    vector<int> v22 = { 3,4 };
    v1.swap(v22);

    for (int x : v1)
        cout << x << " ";

    vector<int> v33 = { 10,20,30 };

	cout << "\nIterators (begin, end) : " << endl;
    for (auto it = v33.begin(); it != v33.end(); ++it)
        cout << *it << " ";

    cout<<endl;
    return 0;
}