#include <iostream>
using namespace std;
#define MAX_SIZE 15 // Maximum size of stack
class Stack {
private:
    int top; // Index of top element
    int arr[MAX_SIZE]; // Array to store elements
public:
    Stack() {
        top = -1; // Initialize top index to -1 (empty stack)
    }
    bool push(int x) {
        if (isFull()) {
            cout << "Stack overflow" << endl; // Display message if stack is full
            return false; // Return false to indicate failure in pushing element
        }
        // Increment top index and add element to array
        arr[++top] = x; 
        return true; // Return true to indicate successful element addition
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack underflow" << endl; // Display message if stack is empty
            return 0; // Return 0 to indicate failure in popping element
        }
        // Return top element and decrement top index
        return arr[top--]; 
    }

    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl; // Display message if stack is empty
            return 0; // Return 0 to indicate failure in peeking element
        }
        // Return top element without modifying top index
        return arr[top]; 
    }

    bool isEmpty() {
	// Stack is empty if top index is -1
        return (top < 0); 
    }

    bool isFull() {
	// Stack is full if top index is equal to MAX_SIZE - 1
        return (top >= MAX_SIZE - 1); 
    }
    void display() {
        if (top < 0) {
            cout << "Stack is empty" << endl; // Display message if stack is empty
            return;
        }
        cout << "\nStack elements: ";
        for (int i = top; i >= 0; i--)
            cout << arr[i] << " "; // Display elements of the stack
        cout << endl;
    }

    void reverse() {
        int n = top + 1; // Get the number of elements in the stack
        int* tmp = new int[n]; // Create a temporary array to store the reversed elements
        for (int i = 0; i < n; i++) {
            tmp[i] = arr[top--]; // Pop elements from the original stack and store them in the temporary array
        }
        for (int i = 0; i < n; i++) {
            push(tmp[i]); // Push the reversed elements back onto the original stack
        }
        delete[] tmp; // Free the temporary array
    }
};

int main() {
    Stack stk; // Initialize the stack stk
    int a,b,i;
    cout << "How many elements do you want in stack:";
    cin>> a;
    for (i=0; i<a; i++)
    {
       cout <<"enter the elements:  ";
       cin>> b;
       stk.push(b);
    }
    stk.display(); // Display the elements of the stack
    cout << "\n";
    stk.reverse();
    cout << "the reversed elements of the stack:  ";
    stk.display(); // Display the reversed elements of the stack
    return 0;
}

