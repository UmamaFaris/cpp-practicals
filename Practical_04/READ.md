# C++ Practicals

## Practical 04: RAII and Smart Pointers

### Aim
To understand how RAII manages resources automatically and how smart pointers reduce memory management errors in C++.

### Concepts Used
- RAII
- Raw Pointers
- Smart Pointers
- unique_ptr
- shared_ptr
- make_unique()
- make_shared()
- Memory Management
- Memory Leak Prevention

### Description
This program demonstrates memory management using raw pointers and smart pointers in C++.

It performs the following operations:

- Allocates memory using a raw pointer.
- Creates a unique_ptr to manage an integer.
- Creates an array using unique_ptr.
- Creates shared_ptr to share ownership.
- Displays the reference count using use_count().
- Releases shared ownership using reset().

### How to Run
1. Open main.cpp.
2. Open the terminal.
3. Compile the program:

```bash
g++ -std=c++14 main.cpp -o main
```

4. Run the executable:

```bash
.\main.exe
```

### Sample Output

```text
Raw Pointer Example:
Value: 10

Unique Pointer Example:
Value: 20

Unique Pointer Array:
10 20 30

Shared Pointer Example:
Value: 50
Reference Count: 2
Both pointers share the same object.
Reference Count After Reset: 1

Program Completed Successfully!
```

### Comparison

| Raw Pointer | unique_ptr | shared_ptr |
|---|---|---|
| Manual memory management | Automatic management | Automatic management |
| Manual delete required | Single ownership | Shared ownership |
| Higher risk of memory leaks | Safer memory handling | Safer memory handling |

### Memory Checking
AddressSanitizer can be used to check memory-related errors.

Compile using:

```bash
g++ -std=c++14 -fsanitize=address -g main.cpp -o main
```

### Conclusion
Successfully implemented RAII and smart pointers in C++. Understood the difference between raw pointers, unique_ptr and shared_ptr, and how smart pointers help manage memory automatically.