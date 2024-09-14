// Write a program that dynamically allocates a two-dimensional array using pointers.
// Prompt the user to enter the number of rows and columns, allocate memory dynamically, and
// then prompt the user to enter the elements of the array. Display the sum of all elements

#include <iostream>

int main() {
    int rows, cols;
    std::cout << "Enter the number of rows: ";
    std::cin >> rows;
    std::cout << "Enter the number of columns: ";
    std::cin >> cols;

    // Dynamically allocate memory for the 2D array
    int** arr = new int*[rows];
    for (int i = 0; i < rows; ++i) {
        arr[i] = new int[cols];
    }

    // Prompt the user to enter the elements
    std::cout << "Enter the elements of the array:" << std::endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << "Enter element at position (" << i << ", " << j << "): ";
            std::cin >> arr[i][j];
        }
    }

    // Calculate the sum of all elements
    int sum = 0;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            sum += arr[i][j];
        }
    }

    // Display the sum
    std::cout << "Sum of all elements: " << sum << std::endl;

    // Deallocate the dynamically allocated memory
    for (int i = 0; i < rows; ++i) {
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}
