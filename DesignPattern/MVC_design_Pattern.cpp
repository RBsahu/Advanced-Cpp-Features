/*
MVC (Model–View–Controller) is an design pattern that separates an application
into three interconnected components:

Model -         Manages data and business logic
View -          Displays data to user
Controller -    Handles user input and updates Model

This separation improves:
 Maintainability
 Scalability
 Testability
 Loose Coupling

 MVC Components in C++
Component	        Responsibility
Model	            Store and manage data
View	            Display data
Controller	        Handle user input

*/

#include<iostream>
#include<vector>
using namespace std;

// Student Data Structure
class Student
{
public:
    string name;
    int rollNo;

    Student(string n, int r)
    {
        name = n;
        rollNo = r;
    }
};

// -------------------- MODEL --------------------
// Stores list of students
class StudentModel
{
private:
    vector<Student> students;

public:
    // Add new student
    void addStudent(string name, int rollNo)
    {
        students.push_back(Student(name, rollNo));
    }

    // Return all students
    vector<Student>& getStudents()
    {
        return students;
    }
};

// -------------------- VIEW --------------------
// Displays list of students
class StudentView
{
public:
    void displayAllStudents(vector<Student>& students)
    {
        cout << "Student List:\n";

        for (auto& s : students)
        {
            cout << "Name: " << s.name
                << " RollNo: " << s.rollNo << endl;
        }
    }
};

// -------------------- CONTROLLER --------------------
class StudentController
{
private:
    StudentModel* model;
    StudentView* view;

public:
    StudentController(StudentModel* m, StudentView* v)
    {
        model = m;
        view = v;
    }

    // Add student via controller
    void addStudent(string name, int rollNo)
    {
        model->addStudent(name, rollNo);
    }

    // Update view
    void updateView()
    {
        view->displayAllStudents(
            model->getStudents());
    }
};

// -------------------- CLIENT --------------------
int main()
{
    StudentModel model;
    StudentView view;

    StudentController controller(&model, &view);

    // Add multiple students
    controller.addStudent("Ram", 101);
    controller.addStudent("Sahu", 102);
    controller.addStudent("Ravi", 103);

    // Display all students
    controller.updateView();

    return 0;
}