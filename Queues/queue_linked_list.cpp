#include <iostream>

using namespace std;

// Define a Node class for the linked list
class Node {
public:
    // Data stored in the node
    int data; 
    // Pointer to the next node in the list
    Node* next; 

    // Constructor to initialize a node
    Node(int data) {
        // Set the data of the node
        this->data = data; 
        // Initialize next pointer to null as it's the last node initially
        this->next = nullptr; 
    }
};

// Define a Queue class using a linked list
class Queue {
private:
    // Pointer to the front node of the queue
    Node* front; 
    // Pointer to the rear node of the queue
    Node* rear; 

public:
    // Constructor to initialize the queue
    Queue() {
        // Set front and rear pointers to null indicating the queue is empty
        this->front = nullptr; 
        this->rear = nullptr; 
    }

    // Destructor to free memory
    ~Queue() {
        // Loop through the queue and delete all nodes
        while (front != nullptr) { 
            // Store the current front node in a temporary variable
            Node* temp = front; 
            // Move front pointer to the next node
            front = front->next; 
            // Delete the current node to free memory
            delete temp; 
        }
    }

    // Check if the queue is empty
    bool isEmpty() {
        // Return true if front is null, indicating the queue is empty
        return front == nullptr; 
    }

    // Enqueue an element into the queue
    void enqueue(int element) {
        // Create a new node with the given element
        Node* newNode = new Node(element); 
        // If the queue is empty, set both front and rear to the new node
        if (isEmpty()) { 
            front = newNode; 
            rear = newNode; 
        } else {
            // Otherwise, add the new node to the end of the queue
            rear->next = newNode; 
            // Update rear to point to the new node
            rear = newNode; 
        }
    }

    // Dequeue an element from the queue
    int dequeue() {
        // Check if the queue is empty before trying to dequeue
        if (isEmpty()) { 
            // Print an error message if the queue is empty
            cout << "Queue Underflow! Cannot dequeue element" << endl; 
            // Return -1 to indicate an error or failure
            return -1; 
        }
        // Retrieve the data from the front node
        int element = front->data; 
        // Store the front node in a temporary variable
        Node* temp = front; 
        // Move the front pointer to the next node
        front = front->next; 
        // If the queue is now empty, set rear to null
        if (isEmpty()) { 
            rear = nullptr; 
        }
        // Delete the old front node to free memory
        delete temp; 
        // Return the dequeued element
        return element; 
    }

    // Get the front element without removing it
    int peek() {
        // Check if the queue is empty before trying to peek
        if (isEmpty()) { 
            // Print an error message if the queue is empty
            cout << "Queue is empty! Cannot peek element" << endl; 
            // Return -1 to indicate an error or failure
            return -1; 
        }
        // Return the data from the front node without removing it
        return front->data; 
    }

    // Print the queue elements
    void printQueue() {
        // Start with the front node and traverse the queue
        Node* temp = front; 
        cout << "Queue elements: "; 
        // Print the data of each node in the queue
        while (temp != nullptr) { 
            cout << temp->data << " "; 
            // Move to the next node
            temp = temp->next; 
        }
        // End the line after printing all elements
        cout << endl; 
    }
};
