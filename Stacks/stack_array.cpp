#include <iostream>

using namespace std;

// Define a Stack class
class Stack {
private:
    // Pointer to dynamically allocate memory for storing stack elements
    int *arr; 
    // Variable to keep track of the index of the top element in the stack
    int top; 
    // Maximum number of elements that the stack can hold
    int capacity; 

public:
    // Constructor to initialize the stack with the specified capacity
    Stack(int capacity) {
        // Set the capacity to the provided value
        this->capacity = capacity; 
        // Initialize the top index to -1 indicating an empty stack
        this->top = -1; 
        // Dynamically allocate memory for the stack array
        this->arr = new int[capacity]; 
    }

    // Destructor to release dynamically allocated memory when the object is destroyed
    ~Stack() {
        // Free the memory allocated for the stack array
        delete[] arr; 
    }

    // Function to check if the stack is empty
    bool isEmpty() {
        // Return true if top is -1, indicating the stack is empty
        return top == -1; 
    }

    // Function to check if the stack is full
    bool isFull() {
        // Return true if top index reaches the maximum capacity - 1
        return top == capacity - 1; 
    }

    // Function to add an element onto the stack
    void push(int element) {
        // Check if the stack is full before adding a new element
        if (isFull()) { 
            // Print error if stack is full
            cout << "Stack Overflow! Cannot push element " << element << endl; 
            // Exit the function without adding the element
            return; 
        }
        // Increment the top index and store the element at the new top position
        arr[++top] = element; 
    }

    // Function to remove and return the top element from the stack
    int pop() {
        // Check if the stack is empty before attempting to pop
        if (isEmpty()) { 
            // Print error if stack is empty
            cout << "Stack Underflow! Cannot pop element" << endl; 
            // Return -1 to indicate failure or throw an exception
            return -1; 
        }
        // Return the top element and decrement the top index
        return arr[top--]; 
    }

    // Function to retrieve the top element without removing it
    int peek() {
        // Check if the stack is empty before peeking
        if (isEmpty()) { 
            // Print error if stack is empty
            cout << "Stack is empty! Cannot peek element" << endl; 
            // Return -1 to indicate failure or throw an exception
            return -1; 
        }
        // Return the element at the top index without modifying the stack
        return arr[top]; 
    }

    // Function to print all elements in the stack
    void printStack() {
        // Print a header for the stack elements
        cout << "Stack elements: "; 
        // Iterate through the stack from bottom to top
        for (int i = 0; i <= top; i++) { 
            // Print each element in the stack
            cout << arr[i] << " "; 
        }
        // End the line after printing all elements
        cout << endl; 
    }
};
