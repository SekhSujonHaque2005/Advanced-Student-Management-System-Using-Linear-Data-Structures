# Advanced Student Record Management System Using Linear Data Structures

> A professional, console-based Student Record Management System developed in **C++** implementing linear data structures and algorithms without using STL containers. Uses a robust Object-Oriented Programming (OOP) architecture with a beautiful CLI interface.

## Developer

**Name:** Sekh Sujon Haque

**University:** Lovely Professional University

**Course:** Basic Data Structures and Algorithms (BDSA)

**Language:** C++

## About the Project

The Advanced Student Record Management System is a comprehensive, menu-driven console application designed to manage student records while rigorously implementing the fundamental concepts of data structures and algorithms.

Unlike simple CRUD applications, this project demonstrates real-world application of DSA by implementing structures completely from scratch for educational and architectural purposes.

The project demonstrates:

- Object-Oriented Programming (OOP) & Encapsulation
- Dynamic Memory Allocation
- Pointer Manipulation
- Linked Lists (for Data Storage)
- Stack (for Undo functionality)
- Queue (for Recent Searches)
- Searching Algorithms
- Sorting Algorithms
- File Serialization / Deserialization
- Modern Console UI (ANSI escape colors and ASCII art)

## Project Objectives

- Learn and apply linear data structures practically.
- Implement Linked Lists, Stacks, and Queues without STL.
- Encapsulate logic securely using C++ Classes.
- Provide a robust CLI interface.
- Build a real-world DSA application suitable for academic Viva and resume showcasing.

## Technologies Used

- C++ (OOP Paradigm)
- `<iostream>`, `<iomanip>`, `<fstream>`
- Git
- GitHub

## Data Structures Used

| Data Structure | Purpose |
| --- | --- |
| **Linked List** | Acts as the primary dynamic student database. |
| **Stack** | Stores recently deleted records to allow instantaneous "Undo Last Delete". |
| **Queue** | Maintains a rolling log of the last 5 recently viewed Registration Numbers. |
| **Array/Variables** | Temporary data, metrics, and loop variables. |

## Algorithms Used

### Searching

- **Linear Search**: Used to find specific Registration Numbers in the Linked List.

### Sorting

- **Bubble Sort**: Sorts the Linked List descending by CGPA.
- **Selection Sort**: Sorts the Linked List ascending by Roll Number.

## Features

### Core Operations

- **Register Student:** Adds a new student avoiding duplicate registration numbers.
- **Display Students:** Renders neatly formatted tabular data.
- **Search Student:** Finds a record and logs it in the Recent Searches queue.
- **Update Student:** Modifies existing data.
- **Delete Student:** Removes a student and safely places them in the Undo stack.

### Advanced Operations

- **Undo Last Delete (Stack):** Immediately restores a deleted student record.
- **Recent Searches (Queue):** Displays the last 5 searched registration numbers.
- **Sorting (Bubble/Selection):** Reorders the database based on CGPA or Roll No.
- **Statistics:** Shows total registrations, max, min, and average CGPA.
- **Data Persistence:** Automatically saves to and loads from `students.txt`.

## Project Structure

```text
Student-Management-System/
│
├── src/
│   └── main.cpp          # Main encapsulated C++ logic
│
├── README.md             # Project documentation
├── Learning.md           # Daily journal and concepts learned
├── .gitignore
└── students.txt          # Persistent database (Auto-generated)
```

## Time Complexity

| Operation | Complexity |
| --- | --- |
| Register Student | O(n) |
| Display Students | O(n) |
| Search Student | O(n) |
| Delete Student | O(n) |
| Update Student | O(n) |
| Bubble Sort (Linked List)| O(n²) |
| Selection Sort (Linked List)| O(n²) |
| Undo Delete | O(1) |
| Recent Search | O(1) |

## Development Progress

- [x] Project Planning
- [x] Project Structure
- [x] Student Structure
- [x] Object-Oriented Refactoring & Encapsulation
- [x] Register Student
- [x] Display Students
- [x] Search Student
- [x] Update Student
- [x] Delete Student
- [x] Sorting (Bubble & Selection)
- [x] Stack (Undo Delete)
- [x] Queue (Recent Searches)
- [x] Statistics
- [x] File Handling
- [x] Testing
- [x] Documentation & Doxygen Comments

## Learning Journal

Daily development progress, algorithms, and concepts learned are extensively documented in:

[Learning.md](Learning.md)

## How to Compile & Run

### Clone the Repository

```bash
git clone https://github.com/SekhSujonHaque2005/Advanced-Student-Management-System-Using-Linear-Data-Structures.git
```

### Compile

```bash
g++ src/main.cpp -o src/main
```

### Run

```bash
# Windows
.\src\main.exe

# Linux / Mac
./src/main
```

## License

This project is developed for educational purposes as part of the **Basic Data Structures and Algorithms** course at **Lovely Professional University**.

## Support

If you found this project useful or learned something new about OOP and DSA, consider giving it a ⭐ on GitHub.
