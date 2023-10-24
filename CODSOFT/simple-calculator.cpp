//SIMPLE CALCULATOR

/*Developping a calculator program that performs basic arithmetic
operations such as addition, subtraction, multiplication, and
division. Allow the user to input two numbers and choose an
operation to perform.*/


#include <iostream>
#include <cmath>
#include <limits>

// Function prototypes
double add(double a, double b);
double subtract(double a, double b);
double multiply(double a, double b);
double divide(double a, double b);

int main() {
    std::cout << "\033[1;33m==============================================================================================================================================\n";
    std::cout << "\t\t\t\t\t\t🔮 Welcome to the Calculator of Possibilities! 🔮\n";
    std::cout << "\t\t\t\t\t    Where numbers hold the key to unlocking countless outcomes!\n";
    std::cout << "==============================================================================================================================================\033[0m";

    // Main calculator loop
    char repeat;
    do {
        int choice;
        bool validChoice = false; // Flag to track valid choice
        
        // Loop until the user provides a valid choice
        while (!validChoice) {
            // Display operation options 
            std::cout << "\033[1;35m"; 
            std::cout << "\nSelect an operation:\n";
            std::cout << "\033[0m\n";
            std::cout << "1. Addition\n";
            std::cout << "2. Subtraction\n";
            std::cout << "3. Multiplication\n";
            std::cout << "4. Division\n";

            std::cout << "Enter your choice: ";
            std::cin >> choice;

            if (choice >= 1 && choice <= 4) {
                validChoice = true; // Valid choice provided, exit the loop
            } else {
                std::cout << "\033[1;31m"; 
                std::cout << "Invalid choice! Please enter a valid choice (1-4).\n";
                std::cout << "\033[0m";
            }
        }

        double num1, num2, result;
        std::cout << "Enter first number: ";
        std::cin >> num1;
        std::cout << "Enter second number: ";
        std::cin >> num2;

        switch (choice) {
            case 1: // Addition
                result = add(num1, num2);
                break;
            case 2: // Subtraction
                result = subtract(num1, num2);
                break;
            case 3: // Multiplication
                result = multiply(num1, num2);
                break;
            case 4: // Division
                result = divide(num1, num2);
                if (num2 == 0) {
                    std::cout << "\033[1;31m"; 
                    std::cout << "Error: Division by zero is not allowed!\n";
                    std::cout << "\033[0m";
                    continue; // Ask for input again
                }
                break;
        }

        // Display the result 
        std::cout << "\033[1;32m";
        std::cout << "Result: " << result << std::endl;
        std::cout << "\033[0m"; 

        std::cout << "\033[1;31m"; 
        std::cout << "Do you want to perform another calculation? (Y/N): ";
        std::cout << "\033[0m";
        std::cin >> repeat;
    } while (repeat == 'Y' || repeat == 'y');

    std::cout << "\033[1;34m"; 
    std::cout << "\nThank you for using the calculator!\n\n" << std::endl;
    std::cout << "\033[0m"; 

    return 0;
}

// Function implementations (same as in previous responses)
double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

double divide(double a, double b) {
    if (b != 0) {
        return a / b;
    } else {
        return std::numeric_limits<double>::quiet_NaN();
    }
}