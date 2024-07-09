#include <iostream>
using namespace std;

int main() {
    int rows, cols;

    // Taking dimensions as input
    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "Enter the number of columns: ";
    cin >> cols;

    // Creating a 1D array to store the 2D array elements in column-major order
    int* array = new int[rows * cols];

    // Taking user input for the 2D array
    cout << "Enter the elements of the 2D array:" << endl;
    for (int j = 0; j < cols; ++j) {
        for (int i = 0; i < rows; ++i) {
            cout << "Element [" << i << "][" << j << "]: ";
            cin >> array[i + j * rows];
        }
    }

    // Displaying the 2D array in matrix form using the 1D array
    cout << "The 2D array in matrix form is:" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << array[i + j * rows] << " ";
        }
        cout << endl;
    }

    // Freeing the allocated memory
    delete[] array;

    return 0;
}

