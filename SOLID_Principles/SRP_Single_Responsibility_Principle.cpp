
/*
 Single Responsibility Principle (SRP) 
 Definition
 A class should have only one reason to change.
 A class should perform only one job / responsibility.
 Each responsibility should be handled by a separate class.

Benefits of SRP include:
Reducing tight coupling
Improving maintainability
Enhancing testability
Easier debugging
Better modular design

Violating SRP (Bad Design Example)

Suppose we are creating a Student class which:
Stores student data
Saves data to file
Generates report

#include<iostream>
#include<fstream>
using namespace std;

class Student
{
    string name;
    int rollNo;

public:
    Student(string n, int r) : name(n), rollNo(r) {}

    void saveToFile()
    {
        ofstream file("student.txt");
        file << name << " " << rollNo;
        file.close();
    }

    void generateReport()
    {
        cout << "Student Report\n";
        cout << "Name: " << name << endl;
        cout << "Roll No: " << rollNo << endl;
    }
};  
int main()
{
    Student s("Ram", 101);
    // Saving student data to file
    s.saveToFile();
    // Generating student report
    s.generateReport();
    return 0;
}

Problem:
This class has 3 responsibilities:
Data handling
File storage
Report generation
So, this class will change if:
Storage mechanism changes (DB instead of file)
Report format changes
Student data structure changes
Multiple reasons to change = SRP violation    

*/

#include<iostream>
#include<fstream>
using namespace std;
// Applying SRP (Good Design)
class Student
{
    string name;
    int rollNo;

public:
    Student(string n, int r) : name(n), rollNo(r) {}

    string getName() const { return name; }
    int getRollNo() const { return rollNo; }
};
// File Storage Class
class StudentFileStorage
{
public:
    void saveToFile(const Student& s)
    {
        ofstream file("student.txt");
        file << s.getName() << " " << s.getRollNo();
        file.close();
    }
};
// Report Generator Class
class StudentReportGenerator
{
public:
    void generateReport(const Student& s)
    {
        cout << "Student Report\n";
        cout << "Name: " << s.getName() << endl;
        cout << "Roll No: " << s.getRollNo() << endl;
    }
};
int main()
{
    Student s("Ram", 101);

    StudentFileStorage storage;
    storage.saveToFile(s);

    StudentReportGenerator report;
    report.generateReport(s);

    return 0;
}
