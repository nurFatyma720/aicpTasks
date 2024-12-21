#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// Base class: Person
class Person {
protected:
    string name;
    int age;
    string gender;
    string address;
    string phone;

public:
    // Default constructor
    Person() :
    name(""),
    age(0),
    gender(""),
    address(""),
    phone("") {}

    // Setter functions
    void setName(string n) { name = n; }
    void setAge(int a) { age = a; }
    void setGender(string g) { gender = g; }
    void setAddress(string addr) { address = addr; }
    void setPhone(string ph) { phone = ph; }

    // Virtual function to save information
    virtual void Save_Information() {
        cout << "Enter Name: ";
        getline(cin, name);
        cout << "Enter Age: ";
        cin >> age;
        cin.ignore();
        cout << "Enter Gender: ";
        getline(cin, gender);
        cout << "Enter Address: ";
        getline(cin, address);
        cout << "Enter Phone: ";
        getline(cin, phone);
    }

    // Virtual function to display information
    virtual void Display_Information() const {
        cout << "\n----------- Person Information -----------" << endl;
        cout << "| Name: " << setw(31) << left << name << " |" << endl;
        cout << "| Age: " << setw(32) << left << age << " |" << endl;
        cout << "| Gender: " << setw(29) << left << gender << " |" << endl;
        cout << "| Address: " << setw(28) << left << address << " |" << endl;
        cout << "| Phone: " << setw(30) << left << phone << " |" << endl;
        cout << "-------------------------------------------" << endl;
    }

    // Virtual destructor
    virtual ~Person() {}
};

// Derived class: Teacher
class Teacher : public Person {
private:
    string qualification;
    double salary;

public:
    // Default constructor
    Teacher() : qualification(""), salary(0.0) {}

    // Function to save teacher information
    void Save_Information() override {
        Person::Save_Information();
        cout << "Enter Qualification: ";
        getline(cin, qualification);
        cout << "Enter Salary: ";
        cin >> salary;
        cin.ignore();
    }

    // Function to display teacher information
    void Display_Information() const override {
        Person::Display_Information();
        cout << "\n------- Qualification Information -------" << endl;
        cout << "| Qualification: " << setw(23) << left << qualification << " |" << endl;
        cout << "| Salary: " << setw(30) << left << salary << " |" << endl;
        cout << "-------------------------------------------" << endl;
    }
};

// Derived class: Student
class Student : public Person {
private:
    string previousEducation;
    int obtainedMarks;
    int totalMarks;

public:
    // Default constructor
    Student() : previousEducation(""), obtainedMarks(0), totalMarks(0) {}

    // Function to save student information
    void Save_Information() override {
        Person::Save_Information();
        cout << "Enter Previous Education: ";
        getline(cin, previousEducation);
        cout << "Enter Obtained Marks: ";
        cin >> obtainedMarks;
        cout << "Enter Total Marks: ";
        cin >> totalMarks;
        cin.ignore();
    }

    // Function to display student information
    void Display_Information() const override {
        Person::Display_Information();
        cout << "\n------ Qualification Information ------" << endl;
        cout << "| Previous Education: " << setw(21) << left << previousEducation << " |" << endl;
        cout << "| Obtained Marks: " << setw(24) << left << obtainedMarks << " |" << endl;
        cout << "| Total Marks: " << setw(27) << left << totalMarks << " |" << endl;
        cout << "----------------------------------------" << endl;
    }
};

// Main function
int main() {
    int choice;
    Person* personPtr = nullptr;

    cout << "______________________________________" << endl;
    cout << "|                                    |" << endl;
    cout << "|         Select the option:         |" << endl;
    cout << "|            1. Teacher              |" << endl;
    cout << "|            2. Student              |" << endl;
    cout << "______________________________________" << endl;
    cout << "            Your choose: ";
    cin >> choice;
    cin.ignore(); // Clear the input buffer

    if (choice == 1) {
        personPtr = new Teacher();
    } else if (choice == 2) {
        personPtr = new Student();
    } else {
        cout << "Invalid choice!" << endl;
        return 1;
    }

    personPtr->Save_Information();
    personPtr->Display_Information();

    delete personPtr;
    return 0;
}
