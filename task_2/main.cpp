#include <iostream>
using namespace std;

// Task 1: Circle Class
class Circle {
private:
    double radius;

public:
    // Setter for radius
    void setRadius(double r) {
        radius = r;
    }

    // Getter for radius
    double getRadius() const {
        return radius;
    }

    // Overload the + operator
    Circle operator+(const Circle &other) {
        Circle temp;
        temp.radius = this->radius + other.radius;
        return temp;
    }
};

// Task 2: Complex Class
class Complex {
private:
    double real;
    double imaginary;

public:
    // Constructor
    Complex() : real(0), imaginary(0) {
    }

    // Overload the extraction operator >>
    friend istream &operator>>(istream &input, Complex &c) {
        cout << "Enter real part: ";
        input >> c.real;
        cout << "Enter imaginary part: ";
        input >> c.imaginary;
        return input;
    }

    // Overload the insertion operator <<
    friend ostream &operator<<(ostream &output, const Complex &c) {
        output << c.real << " + " << c.imaginary << "i";
        return output;
    }
};

void task1() {
    Circle c1, c2, c3;

    // Set radius for c1 and c2
    double radius1, radius2;
    cout << "Enter radius for Circle 1: ";
    cin >> radius1;
    c1.setRadius(radius1);

    cout << "Enter radius for Circle 2: ";
    cin >> radius2;
    c2.setRadius(radius2);

    // Add c1 and c2 and assign to c3
    c3 = c1 + c2;

    // Display the radius of c3
    cout << "Radius of resulting Circle (c3): " << c3.getRadius() << endl;
}

void task2() {
    Complex com1;

    // Take input using stream extraction operator
    cin >> com1;

    // Display output using stream insertion operator
    cout << "The complex number is: " << com1 << endl;
}

int main() {
    int choice;

    do {
        cout << "\n================= Menu ====================\n";
        cout << "|         1. Task 1: Circle Class         |\n";
        cout << "|         2. Task 2: Complex Class        |\n";
        cout << "|               3. Exit                   |\n";
        cout << "===========================================\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "\n-- Task 1: Circle Class --\n";
                task1();
                break;
            case 2:
                cout << "\n-- Task 2: Complex Class --\n";
                task2();
                break;
            case 3:
                cout << "Exiting program. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 3);

    return 0;
}
