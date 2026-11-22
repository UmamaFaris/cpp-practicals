
# C++ Practicals

## Practical 06: Runtime Polymorphism and Abstract Classes

### Aim
To demonstrate runtime polymorphism using an abstract
Shape class and derived classes.

### Concepts Used
- Abstract Class
- Pure Virtual Function
- Virtual Destructor
- Runtime Polymorphism
- Function Overriding
- Base Class Pointers

### Classes Used

1. Shape - Abstract base class.
2. Circle - Calculates circle area.
3. Rectangle - Calculates rectangle area.
4. Triangle - Calculates triangle area.

### Description

The Shape class contains a pure virtual area()
function.

Circle, Rectangle and Triangle inherit the Shape
class and implement their own area() functions.

Base class pointers are used to call the correct
area() function at runtime.

### Formulas

- Circle = 3.14 * radius * radius
- Rectangle = length * width
- Triangle = 0.5 * base * height

### How to Run

1. Open main.cpp.
2. Compile:

   g++ main.cpp -o main

3. Run:

   .\main.exe

### Expected Output

Area of Circle: 78.5
Area of Rectangle: 50
Area of Triangle: 24

### Result

Successfully implemented runtime polymorphism
and abstract classes using C++.
