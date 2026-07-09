#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <sstream>

using namespace std;

struct Student {
    string registrationNo;
    int rollNo;
    string name;
    string gender;
    int age;
    string department;
    int semester;
    float cgpa;
    string phone;
    string email;
    Student* next;
};

struct StackNode {
    Student* studentData;
    StackNode* next;
};

struct QueueNode {
    string registrationNo;
    QueueNode* next;
};

class StudentManagementSystem {
private:
    Student* head;
    StackNode* topStack;
    QueueNode* frontQueue;
    QueueNode* rearQueue;
    
    int queueSize;
    const int MAX_QUEUE = 5;

    void pushUndo(Student* student);
    Student* popUndo();
    void enqueueSearch(string regNo);
    void dequeueSearch();
    void swapStudentData(Student* a, Student* b);

public:
    StudentManagementSystem() {
        head = nullptr;
        topStack = nullptr;
        frontQueue = nullptr;
        rearQueue = nullptr;
        queueSize = 0;
        loadFromFile();
    }

    void run();
    void displayTitle();
    void displayMenu();

    Student* createStudentNode();
    void inputStudentData(Student* student);
    bool isDuplicateRegistration(string registrationNo);
    void insertAtEnd(Student* newStudent);

    void registerStudent();
    void displayStudents();
    void searchStudent();
    void updateStudent();
    void deleteStudent();
    
    void sortStudents();
    void bubbleSortByCGPA();
    void selectionSortByRollNo();

    void undoLastDelete();
    void displayRecentSearches();
    void statistics();
    
    void saveToFile();
    void loadFromFile();
};

void StudentManagementSystem::pushUndo(Student* student) {
    StackNode* newNode = new StackNode;
    newNode->studentData = student;
    newNode->next = topStack;
    topStack = newNode;
}

Student* StudentManagementSystem::popUndo() {
    if (topStack == nullptr) return nullptr;
    
    StackNode* temp = topStack;
    Student* restoredStudent = temp->studentData;
    topStack = topStack->next;
    delete temp;
    
    return restoredStudent;
}

void StudentManagementSystem::enqueueSearch(string regNo) {
    if (queueSize == MAX_QUEUE) {
        dequeueSearch();
    }

    QueueNode* newNode = new QueueNode;
    newNode->registrationNo = regNo;
    newNode->next = nullptr;

    if (rearQueue == nullptr) {
        frontQueue = rearQueue = newNode;
    } else {
        rearQueue->next = newNode;
        rearQueue = newNode;
    }
    queueSize++;
}

void StudentManagementSystem::dequeueSearch() {
    if (frontQueue == nullptr) return;

    QueueNode* temp = frontQueue;
    frontQueue = frontQueue->next;

    if (frontQueue == nullptr) {
        rearQueue = nullptr;
    }

    delete temp;
    queueSize--;
}

void StudentManagementSystem::swapStudentData(Student* a, Student* b) {
    swap(a->registrationNo, b->registrationNo);
    swap(a->rollNo, b->rollNo);
    swap(a->name, b->name);
    swap(a->gender, b->gender);
    swap(a->age, b->age);
    swap(a->department, b->department);
    swap(a->semester, b->semester);
    swap(a->cgpa, b->cgpa);
    swap(a->phone, b->phone);
    swap(a->email, b->email);
}

Student* StudentManagementSystem::createStudentNode() {
    Student* newStudent = new Student;
    newStudent->next = nullptr;
    return newStudent;
}

bool StudentManagementSystem::isDuplicateRegistration(string registrationNo) {
    Student* current = head;
    while (current != nullptr) {
        if (current->registrationNo == registrationNo) {
            return true;
        }
        current = current->next;
    }
    return false;
}

void StudentManagementSystem::insertAtEnd(Student* newStudent) {
    if (head == nullptr) {
        head = newStudent;
        return;
    }

    Student* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }
    current->next = newStudent;
}

void StudentManagementSystem::inputStudentData(Student* student) {
    cout << "\nRegistration Number : ";
    cin >> student->registrationNo;

    cout << "Roll Number         : ";
    cin >> student->rollNo;
    cin.ignore(); 

    cout << "Student Name        : ";
    getline(cin, student->name);

    cout << "Gender              : ";
    getline(cin, student->gender);

    cout << "Age                 : ";
    cin >> student->age;
    cin.ignore();

    cout << "Department          : ";
    getline(cin, student->department);

    cout << "Semester            : ";
    cin >> student->semester;

    cout << "CGPA                : ";
    cin >> student->cgpa;
    cin.ignore();

    cout << "Phone Number        : ";
    getline(cin, student->phone);

    cout << "Email Address       : ";
    getline(cin, student->email);
}

void StudentManagementSystem::registerStudent() {
    Student* newStudent = createStudentNode();
    inputStudentData(newStudent);

    if (isDuplicateRegistration(newStudent->registrationNo)) {
        cout << "\nError: Registration Number already exists!\n";
        delete newStudent;
        return;
    }

    insertAtEnd(newStudent);
    cout << "\nStudent Registered Successfully!\n";
}

void StudentManagementSystem::displayStudents() {
    if (head == nullptr) {
        cout << "\nNo student records available.\n";
        return;
    }

    cout << left 
         << setw(15) << "Reg No" 
         << setw(10) << "Roll No" 
         << setw(20) << "Name" 
         << setw(15) << "Dept" 
         << setw(8)  << "CGPA" 
         << setw(25) << "Email\n";
    cout << "-----------------------------------------------------------------------------------------\n";

    Student* current = head;
    while (current != nullptr) {
        cout << left 
             << setw(15) << current->registrationNo 
             << setw(10) << current->rollNo 
             << setw(20) << current->name.substr(0, 19) 
             << setw(15) << current->department.substr(0, 14) 
             << setw(8)  << fixed << setprecision(2) << current->cgpa 
             << setw(25) << current->email.substr(0, 24) 
             << "\n";
        current = current->next;
    }
}

void StudentManagementSystem::searchStudent() {
    if (head == nullptr) {
        cout << "\nNo records available.\n";
        return;
    }

    string regNo;
    cout << "\nEnter Registration Number to Search: ";
    cin >> regNo;

    Student* current = head;
    while (current != nullptr) {
        if (current->registrationNo == regNo) {
            cout << "\nStudent Found!\n";
            cout << "Name: " << current->name << " | Dept: " << current->department << " | CGPA: " << current->cgpa << "\n";
            
            enqueueSearch(regNo);
            return;
        }
        current = current->next;
    }

    cout << "\nStudent not found.\n";
}

void StudentManagementSystem::updateStudent() {
    if (head == nullptr) {
        cout << "\nNo records available to update.\n";
        return;
    }

    string regNo;
    cout << "\nEnter Registration Number of Student to Update: ";
    cin >> regNo;

    Student* current = head;
    while (current != nullptr) {
        if (current->registrationNo == regNo) {
            cout << "Semester (" << current->semester << "): ";
            cin >> current->semester;

            cout << "CGPA (" << current->cgpa << "): ";
            cin >> current->cgpa;
            cin.ignore();

            cout << "Phone Number (" << current->phone << "): ";
            getline(cin, current->phone);

            cout << "\nStudent Record Updated Successfully!\n";
            return;
        }
        current = current->next;
    }

    cout << "\nStudent not found.\n";
}

void StudentManagementSystem::deleteStudent() {
    if (head == nullptr) {
        cout << "\nNo records available to delete.\n";
        return;
    }

    string regNo;
    cout << "\nEnter Registration Number of Student to Delete: ";
    cin >> regNo;

    Student* current = head;
    Student* prev = nullptr;

    while (current != nullptr && current->registrationNo != regNo) {
        prev = current;
        current = current->next;
    }

    if (current == nullptr) {
        cout << "\nStudent not found.\n";
        return;
    }

    if (prev == nullptr) {
        head = current->next;
    } else {
        prev->next = current->next;
    }
    
    current->next = nullptr; 
    
    pushUndo(current);
    cout << "\nStudent Deleted Successfully! (Can be undone)\n";
}

void StudentManagementSystem::undoLastDelete() {
    Student* restored = popUndo();
    
    if (restored == nullptr) {
        cout << "\nUndo Stack is empty.\n";
        return;
    }

    insertAtEnd(restored);
    cout << "\nUndo Successful! Student restored.\n";
}

void StudentManagementSystem::displayRecentSearches() {
    if (frontQueue == nullptr) {
        cout << "\nNo recent searches found.\n";
        return;
    }

    QueueNode* current = frontQueue;
    int i = 1;
    while (current != nullptr) {
        cout << i << ". " << current->registrationNo << "\n";
        current = current->next;
        i++;
    }
}

void StudentManagementSystem::statistics() {
    if (head == nullptr) {
        cout << "\nNo records available.\n";
        return;
    }

    int totalStudents = 0;
    float maxCGPA = 0.0f;
    float minCGPA = 10.0f;
    float sumCGPA = 0.0f;

    Student* current = head;
    while (current != nullptr) {
        totalStudents++;
        sumCGPA += current->cgpa;
        if (current->cgpa > maxCGPA) maxCGPA = current->cgpa;
        if (current->cgpa < minCGPA) minCGPA = current->cgpa;
        current = current->next;
    }

    cout << "Total Students : " << totalStudents << "\n";
    cout << "Highest CGPA   : " << maxCGPA << "\n";
    cout << "Lowest CGPA    : " << minCGPA << "\n";
    cout << "Average CGPA   : " << (sumCGPA / totalStudents) << "\n";
}

void StudentManagementSystem::bubbleSortByCGPA() {
    if (head == nullptr || head->next == nullptr) return;

    bool swapped;
    Student* current;
    Student* lastSorted = nullptr;

    do {
        swapped = false;
        current = head;

        while (current->next != lastSorted) {
            if (current->cgpa < current->next->cgpa) { 
                swapStudentData(current, current->next);
                swapped = true;
            }
            current = current->next;
        }
        lastSorted = current;
    } while (swapped);
}

void StudentManagementSystem::selectionSortByRollNo() {
    if (head == nullptr) return;

    Student* current = head;
    while (current != nullptr) {
        Student* minNode = current;
        Student* temp = current->next;

        while (temp != nullptr) {
            if (temp->rollNo < minNode->rollNo) { 
                minNode = temp;
            }
            temp = temp->next;
        }

        if (minNode != current) {
            swapStudentData(current, minNode);
        }
        current = current->next;
    }
}

void StudentManagementSystem::sortStudents() {
    cout << "\n1. Sort by CGPA (Bubble Sort)\n2. Sort by Roll Number (Selection Sort)\nEnter Choice: ";
    
    int choice;
    cin >> choice;

    if (choice == 1) {
        bubbleSortByCGPA();
        cout << "\nStudents sorted by CGPA!\n";
        displayStudents();
    } else if (choice == 2) {
        selectionSortByRollNo();
        cout << "\nStudents sorted by Roll Number!\n";
        displayStudents();
    } else {
        cout << "\nInvalid choice!\n";
    }
}

void StudentManagementSystem::saveToFile() {
    ofstream outFile("students.txt");
    if (!outFile) return;

    Student* current = head;
    while (current != nullptr) {
        outFile << current->registrationNo << "|"
                << current->rollNo << "|"
                << current->name << "|"
                << current->gender << "|"
                << current->age << "|"
                << current->department << "|"
                << current->semester << "|"
                << current->cgpa << "|"
                << current->phone << "|"
                << current->email << "\n";
        current = current->next;
    }
    outFile.close();
}

void StudentManagementSystem::loadFromFile() {
    ifstream inFile("students.txt");
    if (!inFile) return;

    string line;
    while (getline(inFile, line)) {
        if (line.empty()) continue;

        Student* newStudent = createStudentNode();
        stringstream ss(line);
        string token;

        getline(ss, newStudent->registrationNo, '|');
        
        getline(ss, token, '|');
        newStudent->rollNo = stoi(token);

        getline(ss, newStudent->name, '|');
        getline(ss, newStudent->gender, '|');
        
        getline(ss, token, '|');
        newStudent->age = stoi(token);

        getline(ss, newStudent->department, '|');
        
        getline(ss, token, '|');
        newStudent->semester = stoi(token);

        getline(ss, token, '|');
        newStudent->cgpa = stof(token);

        getline(ss, newStudent->phone, '|');
        getline(ss, newStudent->email, '|');

        insertAtEnd(newStudent);
    }
    inFile.close();
}

void StudentManagementSystem::displayTitle() {
    cout << "\n--- ADVANCED STUDENT RECORD MANAGEMENT SYSTEM ---\n";
}

void StudentManagementSystem::displayMenu() {
    cout << "\n1. Register New Student";
    cout << "\n2. Display All Students";
    cout << "\n3. Search Student";
    cout << "\n4. Update Student";
    cout << "\n5. Delete Student";
    cout << "\n6. Sort Students";
    cout << "\n7. Undo Last Delete";
    cout << "\n8. Recent Searches";
    cout << "\n9. Statistics";
    cout << "\n10. Save and Exit\n";
}

void StudentManagementSystem::run() {
    int choice;
    do {
        displayTitle();
        displayMenu();

        cout << "\nEnter Your Choice : ";
        cin >> choice;

        switch(choice) {
            case 1:  registerStudent(); break;
            case 2:  displayStudents(); break;
            case 3:  searchStudent(); break;
            case 4:  updateStudent(); break;
            case 5:  deleteStudent(); break;
            case 6:  sortStudents(); break;
            case 7:  undoLastDelete(); break;
            case 8:  displayRecentSearches(); break;
            case 9:  statistics(); break;
            case 10: 
                saveToFile();
                cout << "\nRecords Saved. Thank You!\n";
                break;
            default: cout << "\nInvalid Choice! Try again.\n";
        }
    } while (choice != 10);
}

int main() {
    StudentManagementSystem sms;
    sms.run();
    return 0;
}
