// STL_Standard_Template_Library.cpp : 

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>  // Required for std::accumulate
#include<functional> // Required for predefined functors
#include <set>
#include <map>
#include <string>
#include<list>
#include <deque>
#include<unordered_set>
#include<unordered_map>


using namespace std;
//C++ Functors
class Test
{
public:
    // overload function call/parentheses operator
    void operator()() {
        cout << "Hello World!";
    }
};
//C++ Functor With Return Type and Parameters
class Add 
{
public:
    // overload function call operator
    // accept two integer arguments
    // return their sum
    int operator() (int a, int b) {
        return a + b;
    }
};
//Example 2: C++ Functor With a Member Variable
class Add_To_Sum {

private:
    int initial_sum;

public:

    // constructor to initialize member variable  
    Add_To_Sum(int sum) {
        initial_sum = sum;
    }

    // overload function call operator
    int operator()(int num) {
        return initial_sum + num;
    }

};


int main()
{
    cout << "Components of STL :\n";

    cout << "\n=== Containers(Sequence,Adaptors,Associative,Unordered)===:";   
    cout << "\n\n=== Vector Containers === :" << endl;
    vector<int> v1; // Create an empty vector of integers
    if (v1.empty())
        cout << "\nVector v1 is empty :" << endl;
    else
        cout<< "\nVector v1 is not empty :" ;
	cout << "\nSize of v1 : " << v1.size(); // Output the size of the vector
	cout << "\ncapacity of v1 : " << v1.capacity(); // Output the capacity of the vector
    for(int i = 1; i <= 5; i++)
		v1.push_back(i); // Add elements to the vector
	cout << "\nElements in v1 : ";
    for(auto it = v1.begin(); it != v1.end(); ++it)
		cout << *it << " "; // Output the elements of the vector

    // Create a vector of size 5, initialized all vector elements with 11
	vector<int> v2(5, 11); 
    cout << "\nElements in v2 : ";
    for (auto i2 : v2)
        cout << i2 << " ";

    cout << "\nInitializes vector using initializer list.  :";
    vector<int> v3 = {1,2,3,4,5};
    cout << "\nElements in v3 : ";
    for (auto i3 : v3)
        cout << i3 << " ";

    cout << "\nElement at index 2 using []: " << v3[2] << endl;

    // Accessing using at()
	cout << "Element at index 3 using at(): " << v3.at(3) << endl;

    cout << "\n\n=== List Containers === :" << endl;
    list<string> city = {"Bangalore","Pune","Delhi","Patna"};
    city.push_back("Chennai");
	cout << "List of Cities: ";
    for (const auto& c : city)
		cout << c << " ";

    cout << "\n\n=== Set Containers === :" << endl;
    set<int> st = { 5, 2, 3, 2 }; // duplicates are ignored
    st.insert(1);
    cout << "Set: ";
    for (int s : st)
        cout << s << " ";

    cout << "\n\n=== Map Containers === :" << endl;
    map<int,string> m;
    m[1] = "One";
    m[2] = "Two";
    m[3] = "Three";
	cout << "Map contents:\n";
    for (auto& pair : m) {
        cout << pair.first << " : " << pair.second << "\n";
	}

    cout << "\n\n=== deque Containers === :" << endl;
    deque<int> dq;
    dq.push_back(10);
    dq.push_front(5);
    cout << "Deque: ";
    for (int d : dq) cout << d << " ";
    cout << endl;
    
    cout << "\n\n=== Unordered Set Containers===:";
    unordered_set<int> us = {6,7,16,15,81,25};
	us.insert(7); // duplicate, will be ignored
	cout << "\nnordered Set: ";
    for (int n : us)
		cout << n << " ";
        
    cout << "\n\n=== Unordered Multiset Containers===:";
	unordered_multiset<int> ums = { 6,7,16,15,81,25,7 };
	ums.insert(7); // duplicate, will be added
	cout << "\nUnordered Multiset: ";
	for (int n : ums)
		cout << n << " ";

    cout << "\n\n=== Unordered Map Containers===:";
	unordered_map<int, string> um;
	um[1] = "One";
	um[2] = "Two";
	um[3] = "Three";
	cout << "\nUnordered Map contents:\n";
	for (auto& pair : um) {
		cout << pair.first << " : " << pair.second << "\n";
	}       
    
    cout << "\n\n=== Unordered Multi Map Containers===:";
	unordered_multimap<int, string> umm;
	umm.insert({ 1, "One" });
	umm.insert({ 2, "Two" });
	umm.insert({ 1, "Three" }); // duplicate key
    for(auto& pair : umm) {
        cout << pair.first << " : " << pair.second << "\n";
	}
   
    cout << "\n=== STL Algorithms === :" << endl;    
    vector<int> numbers = { 5, 2, 8, 5, 1, 3, 2, 8, 9 };
    cout << "\n";

    //Display original vector
    cout << "Original Vector: ";
    for (int n : numbers)
        cout << n << " ";
    cout << "\n";

    //  Sort the vector
    sort(numbers.begin(), numbers.end());
    cout << "After sort(): ";
    for (int n : numbers)
        cout << n << " ";
    cout << "\n";

    // Remove duplicates using unique() + erase()
    auto last = std::unique(numbers.begin(), numbers.end());
    numbers.erase(last, numbers.end());
    std::cout << "After unique(): ";
    for (int n : numbers)
        cout << n << " ";
    cout << "\n";

    // Reverse the vector
    reverse(numbers.begin(), numbers.end());
    cout << "After reverse(): ";
    for (int n : numbers)
        cout << n << " ";
    cout << "\n";

    // Find a specific element
    int key = 5;
    auto it = find(numbers.begin(), numbers.end(), key);
    if (it != numbers.end())
        cout << "Element " << key << " found at position " << (it - numbers.begin()) << "\n";
    else
        cout << "Element " << key << " not found.\n";

    // Count occurrences
    int count_val = 2;    
    __int64 cnt = count(numbers.begin(), numbers.end(), count_val);
    cout << "Count of " << count_val << " = " << cnt << "\n";

    // Compute sum using accumulate()
    int sum = std::accumulate(numbers.begin(), numbers.end(), 0);
    cout << "Sum of all elements = " << sum << "\n";

    // Find max and min
    auto max_it = max_element(numbers.begin(), numbers.end());
    auto min_it = min_element(numbers.begin(), numbers.end());
    std::cout << "Max element = " << *max_it << ", Min element = " << *min_it << "\n";

    
       

    cout << "\n=== Iterators ===:"<<endl;
    vector<int> numbers1 = { 10, 20, 30, 40, 50 };
    vector<int>::iterator itr;
    vector<int>::const_iterator cit;
    vector<int>::reverse_iterator rit;
    //Forward traversal using iterator
    cout << "Forward traversal using iterator: ";
    itr = numbers1.begin();
    while (itr != numbers1.end())
    {
        cout << *itr << " ";
        ++itr;
	}
    
    //Read-only traversal using const_iterator
    cout << "\nUsing const_iterator (read-only) : ";
    cit = numbers1.cbegin();
    while (cit != numbers1.cend())
    {
        cout << *cit << " ";
        ++cit;
	}


    //Reverse traversal using reverse_iterator
	cout << "\nReverse traversal using reverse_iterator : ";
    rit = numbers1.rbegin();
    while (rit != numbers1.rend())
    {
        std::cout << *rit << " ";
        ++rit;
    }
    
    cout << "\n";
    cout << "\n=== Functors ===:" << endl;
    cout << "\nExample 1: C++ Functor  :";
    // create an object of Greet class
    Test test;
    // call the object as a function
    test();        
    cout << "\nC++ Functor With Return Type and Parameters  :";
    // create an object of Add class
    Add add;

    // call the add  object
    int sum1 = add(100, 78);
    cout << "\nsum1  :"<<sum1;

    cout << "\nExample 2: C++ Functor With a Member Variable  :";
    // create object of Add_To_Sum class
  // initialize member variable of object with value 100
    Add_To_Sum add1 = Add_To_Sum(100);

    // call the add object with 78 as argument
    int final_sum = add1(78);

    cout << "final sum = " << final_sum;
    cout << "\nExample 3: C++ Predefined Functor with STL  :";
	vector<int> nums = { 10, 20, 30, 40, 50 };
    // sort the vector in descending order
    sort(nums.begin(), nums.end(), greater<int>());
    for(auto n : nums)
    {
		cout << n << " ";
	}  
    cout << endl;
    cout << "\n=== End of Program ===" << endl;

    return 0;
}
