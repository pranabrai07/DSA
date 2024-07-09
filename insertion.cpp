#include <iostream>
#include <vector>

using namespace std;

// Function to perform insertion sort
void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
        
        // Move elements of arr[0..i-1], that are greater than key, to one position ahead of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Function to print an array
void printArray(const vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Main function
int main() {
    int size;
    cout << "Enter the number of elements: ";
    cin >> size;
    
    vector<int> arr(size);
    
    cout << "Enter " << size << " integers:\n";
    for (int i = 0; i < size; ++i) {
        cin >> arr[i];
    }
    
    cout << "Original array: ";
    printArray(arr);
    
    insertionSort(arr);
    
    cout << "Sorted array: ";
    printArray(arr);
    
    return 0;
}

