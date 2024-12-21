#include <iostream>
#include <string>
using namespace std;

// Class representing a Student Node in the stack
class Student {
public:
    string name;
    int marks;
    Student* next;

    // Constructor
    Student(string n, int m) : name(n), marks(m), next(nullptr) {}
};

// Stack class using linked list
class Stack {
private:
    Student* top;

public:
    // Constructor
    Stack() : top(nullptr) {}

    // Check if the stack is empty
    bool isEmpty() {
        return top == nullptr;
    }

    // Push a student onto the stack
    void push(string name, int marks) {
        Student* newStudent = new Student(name, marks);
        newStudent->next = top;
        top = newStudent;
        cout << "Student " << name << " added to the stack.\n";
    }

    // Pop a student from the stack
    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty. No student to remove.\n";
            return;
        }
        Student* temp = top;
        cout << "Removing student " << top->name << " with marks " << top->marks << ".\n";
        top = top->next;
        delete temp;
    }

    // Display all students in the stack
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty. No students to display.\n";
            return;
        }
        cout << "Students in the stack:\n";
        Student* temp = top;
        while (temp != nullptr) {
            cout << "Name: " << temp->name << ", Marks: " << temp->marks << endl;
            temp = temp->next;
        }
    }

    // Display top 3 students based on marks
    void displayTop3() {
        if (isEmpty()) {
            cout << "Stack is empty. No students to display.\n";
            return;
        }

        Stack tempStack;
        Student* temp = top;

        // Transfer all students to the temporary stack
        while (temp != nullptr) {
            tempStack.push(temp->name, temp->marks);
            temp = temp->next;
        }

        // Sort temporary stack for top 3 positions
        Stack top3Stack;
        while (!tempStack.isEmpty()) {
            Student* currentTop = tempStack.top;
            tempStack.pop();

            // Insert into the sorted stack
            Stack tempSortStack;
            while (!top3Stack.isEmpty() && top3Stack.top->marks < currentTop->marks) {
                tempSortStack.push(top3Stack.top->name, top3Stack.top->marks);
                top3Stack.pop();
            }

            top3Stack.push(currentTop->name, currentTop->marks);

            // Move back from tempSortStack
            while (!tempSortStack.isEmpty()) {
                top3Stack.push(tempSortStack.top->name, tempSortStack.top->marks);
                tempSortStack.pop();
            }
        }

        // Display top 3 students
        cout << "Top 3 Students:\n";
        int count = 0;
        while (!top3Stack.isEmpty() && count < 3) {
            cout << "Name: " << top3Stack.top->name << ", Marks: " << top3Stack.top->marks << endl;
            top3Stack.pop();
            count++;
        }
    }
};

// Main function
int main() {
    Stack mainStack;
    int choice;

    do {
        cout << "\n--- Menu ---\n";
        cout << "1. Add a student to the stack\n";
        cout << "2. Remove a student from the stack\n";
        cout << "3. Display all students in the stack\n";
        cout << "4. Display top 3 students\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            string name;
            int marks;
            cout << "Enter student name: ";
            cin >> name;
            cout << "Enter student marks: ";
            cin >> marks;
            mainStack.push(name, marks);
            break;
        }
        case 2:
            mainStack.pop();
            break;
        case 3:
            mainStack.display();
            break;
        case 4:
            mainStack.displayTop3();
            break;
        case 5:
            cout << "Exiting program. Goodbye!\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
