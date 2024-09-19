//Develop a calculator program that performs basic arithmetic operations such as addition, subtraction, multiplication, and division. Allow the user to input two numbers and choose an operation to perform. In C++

#include <iostream>
using namespace std;

int main() {
    double num1, num2;
    char operation;

    // User input the number
    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter second number: ";
    cin >> num2;

    // Choose the operation
    cout << "Choose an operation (+, -, *, /): ";
    cin >> operation;

    // Calculation based on the chosen operation
    switch (operation) {
        case '+':
            cout << "Result: " << num1 + num2 << endl;
            break;
        case '-':
            cout << "Result: " << num1 - num2 << endl;
            break;
        case '*':
            cout << "Result: " << num1 * num2 << endl;
            break;
        case '/':
            // If second number is zero
            if (num2 != 0)
                cout << "Result: " << num1 / num2 << endl;
            else
                cout << "Not Defined" << endl;
            break;
        default:
            cout << "Not Defined" << endl;
    }

    return 0;
}