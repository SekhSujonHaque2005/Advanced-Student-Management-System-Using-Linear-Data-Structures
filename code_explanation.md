# Line-by-Line Code Explanation & Customization Guide

This document breaks down the core concepts of `main.cpp` keyword by keyword. It also shows you exactly what lines to change if your teacher asks you to modify the project during the viva.

---

## 1. Headers and Namespaces

```cpp
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <sstream>

using namespace std;
```
- `#include`: Tells the compiler to bring in pre-written libraries.
- `<iostream>`: For `cin` (input) and `cout` (output).
- `<string>`: Allows us to use the `string` data type for names/emails.
- `<iomanip>`: Stands for input/output manipulation. We use it for `setw()` to make tables look neat.
- `<fstream>`: File stream. Used to read (`ifstream`) and write (`ofstream`) to `students.txt`.
- `<sstream>`: String stream. Used to chop up the text file lines into individual variables.
- `using namespace std;`: Prevents us from having to type `std::cout` and `std::string` every single time.

---

## 2. Structures (Data Models)

```cpp
struct Student {
    string registrationNo;
    ...
    Student* next;
};
```
- `struct`: A custom data type that groups related variables together.
- `Student* next`: This makes the struct a **Node**. It holds a pointer (memory address) to the *next* student in the linked list.

```cpp
struct StackNode {
    Student* studentData;
    StackNode* next;
};
```
- `StackNode`: The node used for the Undo Stack. It holds a pointer to the deleted `Student`.

---

## 3. The Class

```cpp
class StudentManagementSystem {
private:
    Student* head;
...
```
- `class`: A blueprint for creating objects. It binds data and the functions that manipulate that data together (Encapsulation).
- `private:`: These variables cannot be touched by `main()`. They are completely hidden and safe.
- `Student* head`: The starting point of the linked list.

---

## 4. The Constructor

```cpp
    StudentManagementSystem() {
        head = nullptr;
        topStack = nullptr;
        ...
        loadFromFile();
    }
```
- **Constructor:** It has the exact same name as the class. It runs automatically when `StudentManagementSystem sms;` is called in `main()`.
- `nullptr`: A modern C++ keyword meaning "Point to nothing". It is safer than the old `NULL`.

---

## 5. Memory Allocation (`new` and `delete`)

```cpp
Student* newStudent = new Student;
```
- `Student*`: Creates a pointer variable.
- `new`: Asks the operating system for a chunk of memory during runtime (Dynamic Memory Allocation).

```cpp
delete temp;
```
- `delete`: Gives the memory back to the operating system.

---

## 6. String Parsing (`stringstream`)

```cpp
getline(ss, newStudent->registrationNo, '|');
```
- `getline()`: Usually reads until the end of the line.
- `ss`: The stringstream (the line we are reading from the text file).
- `newStudent->registrationNo`: Where we want to store the text.
- `'|'`: The **delimiter**. It tells `getline` to stop reading when it hits the pipe symbol.

---

## 💡 "What if the Teacher asks me to change something?"

During vivas, teachers love to ask you to modify the code on the spot to prove you wrote it. Here is exactly what to change if they ask:

### Change 1: "Make the Queue hold 10 recent searches instead of 5"
**Where to go:** Line 41 in `main.cpp`
**Change:**
```cpp
const int MAX_QUEUE = 5;
```
to
```cpp
const int MAX_QUEUE = 10;
```

### Change 2: "Sort the CGPA in Ascending order (lowest to highest) instead of Descending"
**Where to go:** Line 357 inside `bubbleSortByCGPA()`
**Change:**
```cpp
if (current->cgpa < current->next->cgpa) { // Descending
```
to
```cpp
if (current->cgpa > current->next->cgpa) { // Ascending
```

### Change 3: "Add a 'Blood Group' field to the Student"
**Where to go:** 
1. **Line 18 (Struct):** Add `string bloodGroup;` inside `struct Student`.
2. **Line 160 (Input):** Inside `inputStudentData()`, add:
   ```cpp
   cout << "Blood Group         : ";
   getline(cin, student->bloodGroup);
   ```
3. **Line 115 (Swap):** Inside `swapStudentData()`, add:
   ```cpp
   swap(a->bloodGroup, b->bloodGroup);
   ```

### Change 4: "Make the table spacing wider for Names"
**Where to go:** Line 206 and Line 212 in `displayStudents()`
**Change:**
```cpp
<< setw(20) << "Name" 
```
to
```cpp
<< setw(30) << "Name"
```
*(Also remember to change `name.substr(0, 19)` to `name.substr(0, 29)` inside the loop!)*

### Change 5: "Don't load from the text file when the program starts"
**Where to go:** Line 55 inside the `StudentManagementSystem()` constructor.
**Change:** Simply delete or comment out the line:
```cpp
// loadFromFile();
```

---

By studying this document, you will know exactly how the C++ keywords function in your specific project and will be able to perform live modifications flawlessly!
