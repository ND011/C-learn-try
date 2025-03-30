#include <stdio.h>
#include <stdlib.h> // For system() function to clear the terminal
#include <math.h>   // For pow() function to calculate compound interest

// Function to demonstrate auto conversion and casting of data types
void convert_data_type() {
    int integer;
    float floating;
    
    // Taking inputs
    printf("Enter an integer: ");
    scanf("%d", &integer);
    printf("Enter a float: ");
    scanf("%f", &floating);
    
    // Auto conversion (implicit conversion)
    float auto_conversion = integer;
    printf("Auto conversion of int to float: %f\n", auto_conversion);
    
    // Casting (explicit conversion)
    int casted_value = (int) floating;
    printf("Casted float to int: %d\n", casted_value);
}

// Function to find the maximum and minimum of three numbers
void max_min_of_three() {
    int a, b, c;
    
    // Taking inputs
    printf("Enter three numbers: ");
    scanf("%d %d %d", &a, &b, &c);
    
    // Finding maximum using ternary operator
    int max = (a > b && a > c) ? a : (b > c) ? b : c;
    // Finding minimum using ternary operator
    int min = (a < b && a < c) ? a : (b < c) ? b : c;
    
    printf("Maximum: %d\n", max);
    printf("Minimum: %d\n", min);
}

// Function to calculate both simple and compound interest
void simple_compound_interest() {
    float principal, rate, time;
    
    // Taking inputs
    printf("Enter the principal amount: ");
    scanf("%f", &principal);
    printf("Enter the rate of interest: ");
    scanf("%f", &rate);
    printf("Enter the time in years: ");
    scanf("%f", &time);
    
    // Calculating simple interest
    float simple_interest = (principal * rate * time) / 100;
    printf("Simple Interest = %.2f\n", simple_interest);
    
    // Calculating compound interest
    float compound_interest = principal * pow((1 + rate / 100), time) - principal;
    printf("Compound Interest = %.2f\n", compound_interest);
}

// Function to declare the class awarded based on percentage of marks
void class_awarded() {
    float percentage;
    
    // Taking input
    printf("Enter the percentage of marks: ");
    scanf("%f", &percentage);
    
    // Determining the class based on the percentage
    if (percentage < 40) {
        printf("Failed\n");
    } else if (percentage >= 40 && percentage < 60) {
        printf("Second Class\n");
    } else if (percentage >= 60 && percentage < 70) {
        printf("First Class\n");
    } else if (percentage >= 70) {
        printf("Distinction\n");
    }
}

// Function to print the multiplication table for a given number
void multiplication_table() {
    int num, rows;
    
    // Taking inputs
    printf("Enter the number for multiplication table: ");
    scanf("%d", &num);
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    
    // Generating multiplication table
    for (int i = 1; i <= rows; i++) {
        printf("%d x %d = %d\n", num, i, num * i);
    }
}

// Function to print the binary equivalent of a number (0-255)
void binary_equivalent() {
    int num;
    
    // Taking input
    printf("Enter a number (0-255): ");
    scanf("%d", &num);
    
    // Check if the input is within the valid range
    if (num < 0 || num > 255) {
        printf("Invalid input! Please enter a number between 0 and 255.\n");
        return;
    }
    
    // Printing binary equivalent by shifting bits
    printf("Binary equivalent: ");
    for (int i = 7; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
    }
    printf("\n");
}

// Function to calculate the sum and average of three numbers
void sum_and_average() {
    float num1, num2, num3;
    
    // Taking inputs
    printf("Enter three numbers: ");
    scanf("%f %f %f", &num1, &num2, &num3);
    
    // Calculating sum and average
    float sum = num1 + num2 + num3;
    float average = sum / 3;
    
    // Displaying sum and average
    printf("Sum: %.2f\n", sum);
    printf("Average: %.2f\n", average);
}

// Function to clear the terminal screen
void clear_terminal() {
    #if defined(_WIN32) || defined(_WIN64)
        system("cls");  // Windows command to clear terminal
    #else
        system("clear"); // Unix-based systems command to clear terminal
    #endif
}

int main() {
    int choice;

    // Main menu loop
    do {
        // Displaying the menu
        printf("\n---- Menu ----\n");
        printf("1. Convert Data Type (Auto & Casting)\n");
        printf("2. Find Max and Min from Three Numbers\n");
        printf("3. Calculate Simple and Compound Interest\n");
        printf("4. Class Awarded based on Percentage\n");
        printf("5. Multiplication Table\n");
        printf("6. Binary Equivalent of a Number (0-255)\n");
        printf("7. Find Sum and Average of Three Numbers\n");
        printf("8. Exit\n");
        printf("9. Clear Screen\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Switch case to call the appropriate function based on user's choice
        switch (choice) {
            case 1:
                convert_data_type(); // Call data type conversion function
                break;
            case 2:
                max_min_of_three();  // Call max and min function
                break;
            case 3:
                simple_compound_interest();  // Call interest calculation function
                break;
            case 4:
                class_awarded();  // Call class awarded function
                break;
            case 5:
                multiplication_table();  // Call multiplication table function
                break;
            case 6:
                binary_equivalent();  // Call binary equivalent function
                break;
            case 7:
                sum_and_average();  // Call sum and average calculation function
                break;
            case 8:
                printf("Exiting...\n");  // Exit case
                break;
            case 9:
                clear_terminal();  // Call function to clear terminal
                break;
            default:
                printf("Invalid choice! Please choose a valid option.\n");
                break;
        }
    } while (choice != 8); // Loop until user selects option 8 (Exit)

    return 0;
}
