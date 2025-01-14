#include <iostream>

using namespace std;

// Define a Node class for the doubly linked list
class Node {
public:
    // Data stored in the node
    int data; 
    // Pointer to the next node in the list
    Node* next; 
    // Pointer to the previous node in the list
    Node* prev; 

    // Constructor to initialize a node
    Node(int data) {
        // Set the data of the node
        this->data = data; 
        // Initialize next and prev pointers to null as it's a single node initially
        this->next = nullptr; 
        this->prev = nullptr; 
    }
};

// Define a Deque class using a doubly linked list
class Deque {
private:
    // Pointer to the front node of the deque
    Node* front; 
    // Pointer to the rear node of the deque
    Node* rear; 

public:
    // Constructor to initialize the deque
    Deque() {
        // Set front and rear pointers to null indicating the deque is empty
        this->front = nullptr; 
        this->rear = nullptr; 
    }

    // Destructor to free memory
    ~Deque() {
        // Loop through the deque and delete all nodes
        while (front != nullptr) { 
            // Store the current front node in a temporary variable
            Node* temp = front; 
            // Move front pointer to the next node
            front = front->next; 
            // Delete the current node to free memory
            delete temp; 
        }
    }

    // Check if the deque is empty
    bool isEmpty() {
        // Return true if front is null, indicating the deque is empty
        return front == nullptr; 
    }

    // Add an element at the front of the deque
    void insertFront(int element) {
        // Create a new node with the given element
        Node* newNode = new Node(element); 
        // If the deque is empty, set both front and rear to the new node
        if (isEmpty()) { 
            front = newNode; 
            rear = newNode; 
        } else {
            // Otherwise, insert the new node at the front
            newNode->next = front; 
            front->prev = newNode; 
            front = newNode; 
        }
    }

    // Add an element at the rear of the deque
    void insertRear(int element) {
        // Create a new node with the given element
        Node* newNode = new Node(element); 
        // If the deque is empty, set both front and rear to the new node
        if (isEmpty()) { 
            front = newNode; 
            rear = newNode; 
        } else {
            // Otherwise, insert the new node at the rear
            rear->next = newNode; 
            newNode->prev = rear; 
            rear = newNode; 
        }
    }

    // Remove an element from the front of the deque
    int removeFront() {
        // Check if the deque is empty before trying to remove from the front
        if (isEmpty()) { 
            // Print an error message if the deque is empty
            cout << "Deque Underflow! Cannot remove element from front" << endl; 
            // Return -1 to indicate an error or failure
            return -1; 
        }
        // Retrieve the data from the front node
        int element = front->data; 
        // Store the front node in a temporary variable
        Node* temp = front; 
        // Move the front pointer to the next node
        front = front->next; 
        // If the deque is now empty, set rear to null
        if (isEmpty()) { 
            rear = nullptr; 
        } else {
            // Set the new front node's previous pointer to null
            front->prev = nullptr; 
        }
        // Delete the old front node to free memory
        delete temp; 
        // Return the removed element
        return element; 
    }

    // Remove an element from the rear of the deque
    int removeRear() {
        // Check if the deque is empty before trying to remove from the rear
        if (isEmpty()) { 
            // Print an error message if the deque is empty
            cout << "Deque Underflow! Cannot remove element from rear" << endl; 
            // Return -1 to indicate an error or failure
            return -1; 
        }
        // Retrieve the data from the rear node
        int element = rear->data; 
        // Store the rear node in a temporary variable
        Node* temp = rear; 
        // Move the rear pointer to the previous node
        rear = rear->prev; 
        // If the deque is now empty, set front to null
        if (isEmpty()) { 
            front = nullptr; 
        } else {
            // Set the new rear node's next pointer to null
            rear->next = nullptr; 
        }
        // Delete the old rear node to free memory
        delete temp; 
        // Return the removed element
        return element; 
    }

    // Get the front element without removing it
    int peekFront() {
        // Check if the deque is empty before trying to peek
        if (isEmpty()) { 
            // Print an error message if the deque is empty
            cout << "Deque is empty! Cannot peek element from front" << endl; 
            // Return -1 to indicate an error or failure
            return -1; 
        }
        // Return the data from the front node without removing it
        return front->data; 
    }

    // Get the rear element without removing it
    int peekRear() {
        // Check if the deque is empty before trying to peek
        if (isEmpty()) { 
            // Print an error message if the deque is empty
            cout << "Deque is empty! Cannot peek element from rear" << endl; 
            // Return -1 to indicate an error or failure
            return -1; 
        }
        // Return the data from the rear node without removing it
        return rear->data; 
    }

    // Print the deque elements
    void printDeque() {
        // Start with the front node and traverse the deque
        Node* temp = front; 
        cout << "Deque elements: "; 
        // Print the data of each node in the deque
        while (temp != nullptr) { 
            cout << temp->data << " "; 
            // Move to the next node
            temp = temp->next; 
        }
        // End the line after printing all elements
        cout << endl; 
    }
};
