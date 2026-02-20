#include <iostream>
#include <vector>
#include <algorithm>
#include <mutex>
#include <thread>
using namespace std;

// Observer Interface
class observer
{
public:
    virtual void update(float t) = 0;
    virtual ~observer() {}
};

// Concrete Observer
class display : public observer
{
public:
    void update(float temp) override
    {
        cout << "Thread: " << this_thread::get_id()
            << " Temp: " << temp << endl;
    }
};

// Subject Class (Thread Safe)
class weather
{
private:
    float temp;

    vector<observer*> observers;
    mutex mtx;   // Protect shared resource

public:

    // Attach observer (Thread Safe)
    void attach(observer* ob)
    {
        lock_guard<mutex> lock(mtx);
        observers.push_back(ob);
    }

    // Detach observer (Thread Safe)
    void detach(observer* ob)
    {
        lock_guard<mutex> lock(mtx);
        observers.erase(remove(observers.begin(),
            observers.end(),
            ob),
            observers.end());
    }

    // Notify Observers (Thread Safe)
    void notify()
    {
        vector<observer*> localCopy;

        // Critical Section
        {
            lock_guard<mutex> lock(mtx);
            localCopy = observers;
        }

        // Notify outside lock (Important)
        for (observer* ob : localCopy)
        {
            ob->update(temp);
        }
    }

    // Update state (Thread Safe)
    void setData(float t)
    {
        {
            lock_guard<mutex> lock(mtx);
            temp = t;
        }
        notify();
    }
};

int main()
{
    weather w;
    display d1, d2;

    w.attach(&d1);
    w.attach(&d2);

    thread t1([&]() 
        {
        for (int i = 0;i < 5;i++)
            w.setData(10.5 + i);
        });

    thread t2([&]() 
        {
        for (int i = 0;i < 5;i++)
            w.setData(20.5 + i);
        });

    t1.join();
    t2.join();

    return 0;
}