#include <iostream>
#include <fstream>

// populates dynamic array from file
void populateArray(int* array, int size) {
    std::ifstream inputFile("input.txt"); // file is replaceable, or just edit the file
    if (!inputFile.is_open()) {
        std::cerr << "Error opening file\n";
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < size && inputFile >> array[i]; ++i) {
        // Read no more than array's max size
    }

    inputFile.close();
}

// print contents of array
void printArray(const int* array, int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << array[i] << " ";
    }
    std::cout << "\n";
}

// calculates average of array
float calculateAverage(const int* array, int size) {
    if (size == 0) {
        return 0.0; // Stop dividing by zero
    }

    int sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += array[i];
    }

    return static_cast<float>(sum) / size;
}

int main() {
    int arraySize;

    // prompt size of array from user
    std::cout << "Enter the size of the array: ";
    std::cin >> arraySize;

    // dynamic allocation of array
    int* myArray = new int[arraySize];

    // Ppopulate dynamic array from file
    populateArray(myArray, arraySize);

    // print array
    std::cout << "Array Contents:\n";
    printArray(myArray, arraySize);

    // calculate and print average
    float avg = calculateAverage(myArray, arraySize);
    std::cout << "Average: " << avg << "\n";

    // deallocate memory for dynamic array
    delete[] myArray;

    return 0;
}
