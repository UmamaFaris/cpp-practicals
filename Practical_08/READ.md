
# Practical 08: Singleton Design Pattern

## Aim
To implement the Singleton Design Pattern in C++.

## Concepts Used
- Classes and Objects
- Encapsulation
- Private Constructor
- Static Function
- Singleton Design Pattern

## Description
This program demonstrates the Singleton Design Pattern
using an application Settings class.

The Singleton Pattern ensures that only one instance
of a class is created.

The program uses a private constructor and a static
getInstance() function to access the same object.

## Working
1. First call creates the Settings object.
2. Default volume is set to 50.
3. Volume is changed to 80.
4. Second call accesses the same object.
5. Updated volume is displayed.

## Sample Output

First Object:
Volume: 50

Second Object:
Volume: 80

Both are the same object.

## Flow Diagram

main()
   |
   v
getInstance()
   |
   v
Create Object (First Call)
   |
   v
Set Volume = 80
   |
   v
getInstance() Again
   |
   v
Return Same Object
   |
   v
Display Updated Volume

## Benefit
It ensures that only one instance of a class exists.

## Trade-off
It can make testing difficult because the object
is shared globally.

## How to Run

1. Open main.cpp.
2. Compile:

   g++ main.cpp -o main

3. Run:

   .\main.exe

## Result
Successfully implemented the Singleton Design
Pattern in C++.
