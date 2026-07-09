# Advanced Student Record Management System Using Linear Data Structures

## Developer

- **Name:** Sekh Sujon Haque
- **University:** Lovely Professional University
- **Course:** Basic Data Structures and Algorithms (BDSA)
- **Language:** C++

## About This Project

This project is developed as part of the Basic Data Structures and Algorithms course.

The objective is to build a Student Record Management System while implementing linear data structures from scratch without using STL containers such as `vector`, `list`, `stack`, or `queue`.

The project focuses on understanding data structures rather than simply creating CRUD operations.

## Learning Objectives

Throughout this project, I will learn:

- Arrays
- Linked List
- Stack
- Queue
- Searching Algorithms
- Sorting Algorithms
- Dynamic Memory Allocation
- Pointer Manipulation
- Time Complexity Analysis
- File Handling

## Technologies Used

- C++
- Visual Studio Code
- Git
- GitHub

## Daily Learning Journal

### Day 1

#### Topics Learned

- Project Planning
- Project Structure
- Linked List Overview
- Student Structure
- Function Prototypes
- Menu-Driven Program
- `do-while` Loop
- Head Pointer

#### What I Learned

Today I initialized the project and designed the overall architecture of the Student Record Management System.

Instead of jumping directly into coding, I first understood the requirements, selected appropriate data structures, and designed the student node that will be used throughout the project.

I also learned why a linked list is more suitable than an array for this educational project.

#### New Concepts

1. **Function Prototype**

    A function prototype informs the compiler about the existence of a function before it is called.

    Example:

    ```cpp
    void displayMenu();
    ```

2. **Why use `do-while`?**

    A menu-driven application must execute at least once.

    Therefore:

    ```cpp
    do
    {
         // menu
    }
    while(choice != 10);
    ```

    is preferred over `while`.

3. **Head Pointer**

    Initially:

    ```text
    head
     ↓
    NULL
    ```

    After first insertion:

    ```text
    head
     ↓
    Student1 → NULL
    ```

    The head pointer always stores the address of the first node.

#### DSA Concepts Covered

- Structure
- Pointer
- Linked List
- Dynamic Memory
- Function Prototype
- Menu-Driven Programming

#### Time Complexity

| Operation | Complexity |
| --- | --- |
| Menu Display | O(1) |
| Structure Creation | O(1) |
| Head Initialization | O(1) |

#### Problems Faced

- Understanding why function prototypes are required.
- Difference between `while` and `do-while`.

#### Solutions

- Learned that C++ reads code from top to bottom.
- Learned that `do-while` executes at least once, making it ideal for menus.

#### Files Created

- `main.cpp`
- `Learning.md`
- `.gitignore`

#### Git Commit

```text
Initial project setup with menu system and student structure
```

#### Next Day Goals

- Create Student Node
- Dynamic Memory Allocation
- Register Student
- Insert into Linked List
- Display Student Records

---

### Day 2

#### Topics Learned

- Object-Oriented Programming (OOP)
- Encapsulation
- Stack (Undo Last Delete)
- Queue (Recent Searches)
- Bubble Sort and Selection Sort on Linked Lists
- File Handling in C++ (`fstream`)
- ANSI Escape Codes for Console Colors
- Formatting Console Output using `<iomanip>`

#### What I Learned

Today, I fundamentally refactored the project's architecture from a procedural approach (global variables and functions) to an Object-Oriented approach. I encapsulated the entire system logic inside a `StudentManagementSystem` class and made the `head` pointer `private`.

I successfully completed the remaining 80% of the project by implementing Stack, Queue, Searching, Sorting, and File Handling functionalities from scratch, avoiding STL.

#### New Concepts

1. **Encapsulation (OOP)**
    By placing the `head` pointer as a `private` member of the `StudentManagementSystem` class, I restricted external access, preventing accidental modification. The outside world interacts with the linked list strictly via public methods.

2. **Stack (LIFO Structure)**
    To implement the **Undo Delete** feature, I created a Stack. When a node is deleted from the linked list, it's not immediately destroyed; instead, its pointer is pushed onto the `Stack`. When the user chooses to undo, the `Stack` pops the node and re-inserts it.
    
3. **Queue (FIFO Structure)**
    To track **Recent Searches**, I used a Queue with a maximum capacity of 5. Each successful search enqueues the registration number. If the queue hits its limit, the oldest search is dequeued.

4. **File Serialization and Deserialization**
    Using `<fstream>`, the system can now persist data. 
    - `saveToFile()`: Iterates through the linked list and writes each record to `students.txt` using `|` as a delimiter.
    - `loadFromFile()`: Reads from `students.txt`, parsing the string stream, creating student nodes, and rebuilding the linked list during the class constructor call.

5. **Sorting Linked Lists**
    Implementing algorithms like Bubble Sort and Selection Sort on linked lists is trickier than on arrays due to node traversal. Instead of swapping physical nodes (which requires complex pointer manipulation), I swapped the *data* within the nodes for simplicity.

6. **ANSI Coloring and `<iomanip>`**
    I learned how to make terminal output look professional. `\033[32m` turns text green for success messages, while `<iomanip>`'s `setw()` aligns text in table columns.

#### DSA Concepts Covered

- Classes and Objects
- Access Modifiers (Private, Public)
- Stack (Push, Pop)
- Queue (Enqueue, Dequeue)
- Bubble Sort
- Selection Sort
- File I/O (`ifstream`, `ofstream`)
- Data Swapping in Nodes

#### Time Complexity Updates

| Operation | Complexity |
| --- | --- |
| Undo Delete (Stack Push/Pop) | O(1) |
| Recent Search (Queue Enqueue/Dequeue) | O(1) |
| Bubble Sort (Linked List) | O(n²) |
| Selection Sort (Linked List) | O(n²) |
| File Save / Load | O(n) |

#### Problems Faced

- Figuring out how to sort nodes in a linked list without breaking connections.
- Parsing strings containing spaces when reading from the text file.

#### Solutions

- Swapped the node's internal data fields instead of swapping the actual pointer connections for sorting.
- Used a custom delimiter `|` instead of space so `getline()` could parse multi-word strings easily during file reading.

#### Files Modified

- `src/main.cpp`
- `Learning.md`
- `README.md`
- `students.txt` (generated automatically)

#### Git Commit

```text
Refactored to OOP, Implemented Stack, Queue, File Handling, Sorting and UI Polish
```
