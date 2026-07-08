/*
------------------------------------------------------------
Project Name : Advanced Student Record Management System
Course       : Basic Data Structures and Algorithms
Language     : C++
Developed By : Sekh Sujon Haque
------------------------------------------------------------
Description:
A console-based Student Record Management System implementing
Linear Data Structures including Linked List, Stack, Queue,
Searching, and Sorting Algorithms.
------------------------------------------------------------
*/

#include <iostream>
#include <string>

using namespace std;

struct Student
{
    string registrationNo;     // Primary Key
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


Student* head = nullptr;
void displayTitle();
void displayMenu();

int main()
{
    int choice;

    do
    {
        displayTitle();
        displayMenu();

        cout << "\nEnter Your Choice : ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                cout << "\n[ Register Student Module ]\n";
                break;

            case 2:
                cout << "\n[ Display Students Module ]\n";
                break;

            case 3:
                cout << "\n[ Search Student Module ]\n";
                break;

            case 4:
                cout << "\n[ Update Student Module ]\n";
                break;

            case 5:
                cout << "\n[ Delete Student Module ]\n";
                break;

            case 6:
                cout << "\n[ Sorting Module ]\n";
                break;

            case 7:
                cout << "\n[ Undo Delete Module ]\n";
                break;

            case 8:
                cout << "\n[ Recent Searches Module ]\n";
                break;

            case 9:
                cout << "\n[ Statistics Module ]\n";
                break;

            case 10:
                cout << "\nThank You!\n";
                break;

            default:
                cout << "\nInvalid Choice!\n";
        }

    } while(choice != 10);

    return 0;
}

void displayTitle()
{
    cout << "\n==============================================================\n";
    cout << "      ADVANCED STUDENT RECORD MANAGEMENT SYSTEM\n";
    cout << "==============================================================\n";
    cout << "Course : Basic Data Structures and Algorithms\n";
    cout << "Developer : Sekh Sujon Haque\n";
    cout << "==============================================================\n";
}

void displayMenu()
{
    cout << "\n1. Register New Student";
    cout << "\n2. Display All Students";
    cout << "\n3. Search Student";
    cout << "\n4. Update Student";
    cout << "\n5. Delete Student";
    cout << "\n6. Sort Students";
    cout << "\n7. Undo Last Delete";
    cout << "\n8. Recent Searches";
    cout << "\n9. Statistics";
    cout << "\n10. Exit";
}