
/*

Interface Segregation Principle (ISP) — Definition
Clients should not be forced to depend on interfaces they do not use.

Which means:
Do not create fat / large interfaces
Break large interfaces into smaller specific ones
Classes should implement only what they need

ISP Violation (Bad Design)
Suppose we create a Machine interface:
class Machine
{
public:
    virtual void print() = 0;
    virtual void scan() = 0;
    virtual void fax() = 0;
};

Now Printer class:
class Printer : public Machine
{
public:
    void print() override
    {
        cout << "Printing..." << endl;
    }

    void scan() override
    {
        // Not needed
    }
    void fax() override
    {
        // Not needed
    }
};
Problem:

Printer:
Can print 
Cannot scan 
Cannot fax 
Still forced to implement:

Now (Correct Design):

Interfaces are split into:
IPrinter
IScanner
IFax

*/

#include<iostream>
using namespace std;

// ---------------- Small Segregated Interfaces ----------------

// Only Printing Responsibility
class IPrinter
{
public:
    virtual void print() = 0;
};

// Only Scanning Responsibility
class IScanner
{
public:
    virtual void scan() = 0;
};

// Only Fax Responsibility
class IFax
{
public:
    virtual void fax() = 0;
};

// ---------------- Concrete Classes ----------------

// Printer supports only print
class Printer : public IPrinter
{
public:
    void print() override
    {
        cout << "Printer is Printing..." << endl;
    }
};

// Scanner supports only scan
class Scanner : public IScanner
{
public:
    void scan() override
    {
        cout << "Scanner is Scanning..." << endl;
    }
};

// MultiFunction Printer supports all
class MultiFunctionPrinter : public IPrinter, public IScanner, public IFax
{
public:
    void print() override
    {
        cout << "MFP Printing..." << endl;
    }

    void scan() override
    {
        cout << "MFP Scanning..." << endl;
    }

    void fax() override
    {
        cout << "MFP Faxing..." << endl;
    }
};

// ---------------- Main Function ----------------

int main()
{
    Printer p;
    Scanner s;
    MultiFunctionPrinter mfp;

    p.print();     // Only print
    s.scan();      // Only scan

    mfp.print();   // All features
    mfp.scan();
    mfp.fax();

    return 0;
}

