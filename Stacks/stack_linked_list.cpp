#include <iostream>

using namespace std;

// Define a Node class for the linked list
class Node {
public:
    // Data field to store the value of the node
    int data; 
    // Pointer to the next node in the linked list
    Node* next; 

    // Constructor to initialize a node
    Node(int data) {
        // Assign the provided value to the data field
        this->data = data; 
        // Initialize the next pointer to nullptr
        this->next = nullptr; 
    }
};

// Define a Stack class using a linked list
class Stack {
private:
    // Pointer to the top node of the stack
    Node* top; 

public:
    // Constructor to initialize the stack
    Stack() {
        // Set the top pointer to nullptr indicating an empty stack
        this->top = nullptr; 
    }

    // Destructor to free memory
    ~Stack() {
        // Loop through the stack and delete all nodes
        while (top != nullptr) { 
            // Temporary pointer to hold the current top node
            Node* temp = top; 
            // Move the top pointer to the next node
            top = top->next; 
            // Delete the old top node
            delete temp; 
        }
    }

    // Check if the stack is empty
    bool isEmpty() {
        // Return true if top is nullptr, indicating the stack is empty
        return top == nullptr; 
    }

    // Push an element onto the stack
    void push(int element) {
        // Create a new node with the provided element
        Node* newNode = new Node(element); 
        // Point the new node's next to the current top node
        newNode->next = top; 
        // Update the top pointer to the new node
        top = newNode; 
    }

    // Pop an element from the stack
    int pop() {
        // Check if the stack is empty before attempting to pop
        if (isEmpty()) { 
            // Print error if the stack is empty
            cout << "Stack Underflow! Cannot pop element" << endl; 
            // Return -1 to indicate failure or throw an exception
            return -1; 
        }
        // Retrieve the data of the top node
        int element = top->data; 
        // Temporary pointer to hold the current top node
        Node* temp = top; 
        // Move the top pointer to the next node
        top = top->next; 
        // Delete the old top node
        delete temp; 
        // Return the popped element
        return element; 
    }

    // Get the top element without removing it
    int peek() {
        // Check if the stack is empty before peeking
        if (isEmpty()) { 
            // Print error if the stack is empty
            cout << "Stack is empty! Cannot peek element" << endl; 
            // Return -1 to indicate failure or throw an exception
            return -1; 
        }
        // Return the data of the top node
        return top->data; 
    }

    // Print the stack elements
    void printStack() {
        // Temporary pointer to iterate through the stack
        Node* temp = top; 
        // Print a header for the stack elements
        cout << "Stack elements: "; 
        // Traverse the stack until the end
        while (temp != nullptr) { 
            // Print the data of the current node
            cout << temp->data << " "; 
            // Move to the next node
            temp = temp->next; 
        }
        // End the line after printing all elements
        cout << endl; 
    }
};
