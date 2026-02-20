/*
 Observer Pattern in C++
 Definition:
The Observer Pattern is a behavioral design pattern where:
1.One object (Subject) holds the main data.
2.Many other objects (Observers) want to be notified whenever that data changes.
This is called a "one-to-many" relationship.

Real-Time Uses in Industry
Real Scenario	        Subject	        Observer
GUI Button Click	    Button	        UI Elements
share Price Change  	Stock Engine	Trader App
Sensor Data Change	    IoT Device	    Monitoring Dashboard
Weather Monitoring  	Weather Server	Display Units
Logging Framework	    Log Generator	File/Console
Event Handling in Qt	Signal	        Slot

*/

#include <iostream>
#include <vector>
using namespace std;

// Observer Interface
// Any class that wants to receive updates must implement this
class observer
{
public:
    // Pure virtual function for update notification
    virtual void update(float t) = 0;
    virtual ~observer() 
    {
		cout << "Observer destroyed" << endl;
    }
};
// Concrete Observer Class
// Display class that will receive temperature updates
class display : public observer
{
public:
    // Override update method to print temperature
    void update(float temp)
    {
        cout << "Temp :" << temp << endl;
    }
};
// Subject Class
// Weather class which maintains observer list
class wether
{
private:
    float temp;                   // State data (temperature)
    vector<observer*> v;          // List of observers

public:
    // Register an observer
    void attached(observer* ob)
    {
        v.push_back(ob);
    }

    // Remove an observer
    void dettached(observer* ob)
    {
        //This removes all observers, not a specific one.
        //v.clear();  // (Note: Clears all observers – not ideal)

        v.erase(remove(v.begin(), v.end(), ob), v.end());
    }

    // Notify all observers about state change
    void notify()
    {
        for (observer* ob : v)
        {
            ob->update(temp);     // Call update method
        }
    }

    // Set new temperature and notify observers
    void setData(float t)
    {
        temp = t;
        notify();                 // Trigger notification
    }
};

int main()
{
    wether w;     // Subject
    display d1;
    display d2;   // Observer

    w.attached(&d1);     // Register observer
    w.attached(&d2);    // Register another observer
    w.setData(11.23f);    // Change state  notify observer	     
	w.setData(12.23f);    // Change state  notify observers
    return 0;
}

