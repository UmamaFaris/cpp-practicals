
# C++ Practicals

## Practical 05: Single and Multilevel Inheritance

### Aim
To understand inheritance in C++ and learn how
data and functions can be reused between classes.

### Concepts Used
- Base Class
- Derived Class
- Single Inheritance
- Multilevel Inheritance
- Constructors
- Function Reusability

### Class Structure

Person
   |
 Student
   |
GraduateStudent

### Description

1. Person is the base class containing name and age.
2. Student inherits Person and contains student ID and course.
3. GraduateStudent inherits Student and contains a research topic.

### How to Run

1. Open main.cpp.
2. Compile the program:

   g++ main.cpp -o main

3. Run the program:

   ./main

### Expected Output

Student Details:
Name: Rahul
Age: 20
Student ID: 101
Course: Computer Science

----------------------

Graduate Student Details:
Name: Aman
Age: 23
Student ID: 102
Course: Cyber Security
Research Topic: Artificial Intelligence

### Result

Successfully implemented single and multilevel
inheritance using C++ classes.
