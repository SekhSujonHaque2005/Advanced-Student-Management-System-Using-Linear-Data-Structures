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
