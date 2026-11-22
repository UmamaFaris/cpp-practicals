
#include <iostream>
using namespace std;

// Base class
class Person {
protected:
    string name;
    int age;

public:
    Person(string n, int a) {
        name = n;
        age = a;
    }

    void displayPerson() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

// Derived class (Single Inheritance)
class Student : public Person {
protected:
    int studentID;
    string course;

public:
    Student(string n, int a, int id, string c)
        : Person(n, a) {
        studentID = id;
        course = c;
    }

    void displayStudent() {
        displayPerson();
        cout << "Student ID: " << studentID << endl;
        cout << "Course: " << course << endl;
    }
};

// Derived class (Multilevel Inheritance)
class GraduateStudent : public Student {
private:
    string researchTopic;

public:
    GraduateStudent(string n, int a, int id,
                    string c, string topic)
        : Student(n, a, id, c) {
        researchTopic = topic;
    }

    void displayGraduate() {
        displayStudent();
        cout << "Research Topic: " << researchTopic << endl;
    }
};

int main() {

    // Single Inheritance
    cout << "Student Details:" << endl;

    Student s1("Rahul", 20, 101, "Computer Science");
    s1.displayStudent();

    cout << "\n----------------------\n";

    // Multilevel Inheritance
    cout << "Graduate Student Details:" << endl;

    GraduateStudent g1("Aman", 23, 102,
                       "Cyber Security",
                       "Artificial Intelligence");

    g1.displayGraduate();

    return 0;
}
