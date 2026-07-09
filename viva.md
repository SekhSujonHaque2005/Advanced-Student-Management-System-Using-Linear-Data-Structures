# Comprehensive Viva Preparation Guide
**Advanced Student Record Management System**

This document contains every possible question an examiner might ask during your viva. Study these answers carefully. They are written in a simple, easy-to-explain way.

---

## 🟢 Category 1: C++ Basics & Object-Oriented Programming (OOP)

**Q1: Why did you use C++ for this project instead of C?**
> **Answer:** C++ supports Object-Oriented Programming (OOP). It allowed me to encapsulate the entire project inside a `StudentManagementSystem` class, making the code much more organized, secure, and easier to manage than global C structures.

**Q2: What is Encapsulation and how did you use it?**
> **Answer:** Encapsulation means hiding data from the outside world. I made the `head` pointer of the linked list `private` inside my class. This means no one outside the class can accidentally mess up or delete the linked list.

**Q3: What are `public` and `private` access specifiers?**
> **Answer:** 
> - **Private:** Data/functions that can only be accessed from *inside* the class. (Example: `head`, `topStack`, `pushUndo()`).
> - **Public:** Data/functions that can be accessed from *outside* the class. (Example: `run()`, `registerStudent()`).

**Q4: What is a Constructor?**
> **Answer:** A constructor is a special function that runs automatically when an object is created. In my project, `StudentManagementSystem()` is the constructor. It initializes `head` to `nullptr` and automatically calls `loadFromFile()` to load old data.

**Q5: What is the `new` keyword doing?**
> **Answer:** `new` is used for **Dynamic Memory Allocation**. It creates memory for a new Student node on the "Heap" during runtime. For example: `Student* newStudent = new Student;`.

**Q6: What is the `delete` keyword doing?**
> **Answer:** `delete` frees up memory that was allocated using `new`. I use it when I permanently delete a student from the undo stack, or when I close the program, to prevent **memory leaks**.

---

## 🔵 Category 2: Linked Lists

**Q7: Why did you use a Linked List instead of an Array for the Student Database?**
> **Answer:** Arrays have a fixed size. If I used an array, I would have to guess how many students there will be. A linked list grows dynamically. I can add as many students as I want without wasting memory. Also, deleting a student in a linked list is faster because I don't have to shift elements like I would in an array.

**Q8: What is the `head` pointer?**
> **Answer:** The `head` pointer stores the memory address of the very first node (student) in the linked list. If `head` is `nullptr`, it means the list is completely empty.

**Q9: How do you insert a new student at the end of the list?**
> **Answer:** 
> 1. If `head` is `nullptr`, I make `head` point to the new student.
> 2. Otherwise, I create a temporary pointer (`current`) and traverse the list using a `while(current->next != nullptr)` loop until I reach the last node.
> 3. Then, I set the last node's `next` to point to the new student.

**Q10: How does your delete function work?**
> **Answer:** 
> 1. I traverse the list to find the student with the matching registration number.
> 2. I keep track of the `prev` (previous) node.
> 3. To delete, I bypass the node by setting `prev->next = current->next`.
> 4. Instead of destroying it immediately, I push `current` into my Undo Stack.

---

## 🟠 Category 3: Stacks (Undo Feature)

**Q11: What is a Stack?**
> **Answer:** A stack is a linear data structure that follows **LIFO** (Last In, First Out). The last item added is the first item removed.

**Q12: How did you implement the Stack without STL?**
> **Answer:** I created a `StackNode` struct that holds a `Student*`. I maintain a `topStack` pointer. When I push, I add the node to the top. When I pop, I remove from the top.

**Q13: Explain your "Undo Delete" feature.**
> **Answer:** When a user deletes a student from the linked list, I don't use the `delete` keyword immediately. Instead, I pass that node to `pushUndo()`. If the user chooses "Undo", I call `popUndo()` to get the node back and re-insert it into the linked list.

---

## 🟣 Category 4: Queues (Recent Searches Feature)

**Q14: What is a Queue?**
> **Answer:** A queue is a linear data structure that follows **FIFO** (First In, First Out). The first item added is the first item removed.

**Q15: Why did you use a Queue for Recent Searches?**
> **Answer:** Because recent searches work like a queue! If I limit it to 5 searches, and I search for a 6th person, the oldest search (the first one) needs to be pushed out to make room. FIFO handles this perfectly.

**Q16: How did you implement the Queue without STL?**
> **Answer:** I used a Linked List-based queue. I maintain a `frontQueue` pointer (for dequeuing/removing) and a `rearQueue` pointer (for enqueuing/adding). When `queueSize` hits 5, I call `dequeueSearch()` before adding a new one.

---

## 🔴 Category 5: Algorithms (Sorting & Searching)

**Q17: Which sorting algorithms did you use and why?**
> **Answer:** I used **Bubble Sort** (to sort by CGPA descending) and **Selection Sort** (to sort by Roll Number ascending). I used two different algorithms to demonstrate my knowledge of multiple DSA sorting techniques.

**Q18: What is the Time Complexity of Bubble Sort and Selection Sort?**
> **Answer:** Both have a time complexity of **O(N²)** in the worst case, because they both use two nested loops to compare elements.

**Q19: How did you sort a Linked List? Didn't pointers get messy?**
> **Answer:** Instead of swapping the physical node pointers (which is very complex and prone to breaking the list), I simply swapped the **data inside the nodes** using a helper function `swapStudentData()`. This makes the logic identical to sorting an array and is much safer.

**Q20: What is the Time Complexity of your Search function?**
> **Answer:** **O(N)**. Since it's an unsorted linked list, I use **Linear Search**. In the worst case, I have to traverse the entire list to find the student.

---

## 🟤 Category 6: File Handling

**Q21: How are you saving data permanently?**
> **Answer:** I am using the `<fstream>` library. Specifically, `ofstream` to save (write) and `ifstream` to load (read).

**Q22: Why do you use the `|` (pipe) symbol when saving to the text file?**
> **Answer:** It acts as a **delimiter**. A student's name might have spaces (e.g., "John Doe"). If I used spaces to separate data in the text file, reading it back would be very difficult because `cin >>` stops at a space. By using `|`, I can use `getline(ss, str, '|')` to read the entire name at once until it hits the pipe symbol.

**Q23: What does `stringstream` do in your `loadFromFile()` function?**
> **Answer:** It takes a single line of text from the file and treats it like an input stream (like `cin`). It allows me to easily chop up that string into smaller pieces every time it sees the `|` symbol.

---

## 🟡 Typical "Tricky" Examiner Questions

**Q24: What happens if I try to register a student with a Registration Number that already exists?**
> **Answer:** My system prevents it! Before inserting, the `registerStudent()` function calls `isDuplicateRegistration()`, which scans the list. If it finds a match, it displays an error and deletes the newly created temporary node to prevent memory leaks.

**Q25: What happens to the Undo Stack when you close the program?**
> **Answer:** When the program closes, the operating system reclaims memory, but to be a good programmer, I should ideally write a Destructor `~StudentManagementSystem()` that loops through the stack and linked list and calls `delete` on every remaining node. *(Note: Our code handles simple exit, but you can explain memory cleanup if asked).*

**Q26: If your Queue holds 5 items, and I search 6 times, what happens?**
> **Answer:** The `enqueueSearch()` function checks if `queueSize == MAX_QUEUE` (which is 5). If it is, it calls `dequeueSearch()` to delete the oldest item at the `frontQueue`, making room to add the 6th item at the `rearQueue`.

**Q27: Can you explain `cin.ignore()`?**
> **Answer:** When we use `cin >>` to read an integer, it leaves the "Enter" key (`\n`) in the input buffer. If we immediately use `getline()` for a string after that, `getline` will read that leftover `\n` and skip the input! `cin.ignore()` flushes that leftover `\n` out of the buffer so `getline` works correctly.
