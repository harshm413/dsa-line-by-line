#include <iostream>
using namespace std;

// Define a Node class for the singly linked list
class Node {
public:
    // Data stored in the node
    int data;
    // Priority of the node
    int priority;
    // Pointer to the next node in the list
    Node* next;

    // Constructor to initialize a node
    Node(int data, int priority) {
        // Set the data and priority of the node
        this->data = data;
        this->priority = priority;
        // Initialize the next pointer to null as it's a single node initially
        this->next = nullptr;
    }
};

// Define a PriorityQueue class using a singly linked list
class PriorityQueue {
private:
    // Pointer to the front node of the priority queue
    Node* front;

public:
    // Constructor to initialize the priority queue
    PriorityQueue() {
        // Set front to null indicating the queue is empty
        this->front = nullptr;
    }

    // Destructor to free memory
    ~PriorityQueue() {
        // Loop through the priority queue and delete all nodes
        while (front != nullptr) {
            // Store the current front node in a temporary variable
            Node* temp = front;
            // Move front pointer to the next node
            front = front->next;
            // Delete the current node to free memory
            delete temp;
        }
    }

    // Check if the priority queue is empty
    bool isEmpty() {
        // Return true if front is null, indicating the priority queue is empty
        return front == nullptr;
    }

    // Insert an element into the priority queue based on priority
    void insert(int data, int priority) {
        // Create a new node with the given data and priority
        Node* newNode = new Node(data, priority);

        // If the priority queue is empty, set front to the new node
        if (isEmpty()) {
            front = newNode;
        } else {
            // If the queue is not empty, find the correct position to insert
            Node* current = front;
            Node* previous = nullptr;

            // Traverse the list to find the correct position based on priority
            while (current != nullptr && current->priority >= priority) {
                previous = current;
                current = current->next;
            }

            // If the node is inserted at the beginning (highest priority)
            if (previous == nullptr) {
                newNode->next = front;
                front = newNode;
            }
            // If the node is inserted in the middle or at the end
            else {
                newNode->next = current;
                previous->next = newNode;
            }
        }
    }

    // Remove and return the element with the highest priority (front of the queue)
    int dequeue() {
        // Check if the priority queue is empty before trying to dequeue
        if (isEmpty()) {
            // Print an error message if the queue is empty
            cout << "Priority Queue Underflow! Cannot dequeue element" << endl;
            // Return -1 to indicate an error or failure
            return -1;
        }

        // Retrieve the data from the front node (highest priority element)
        int element = front->data;
        // Store the front node in a temporary variable
        Node* temp = front;
        // Move the front pointer to the next node
        front = front->next;
        // Delete the old front node to free memory
        delete temp;
        // Return the dequeued element
        return element;
    }

    // Get the front element (highest priority) without removing it
    int peek() {
        // Check if the priority queue is empty before trying to peek
        if (isEmpty()) {
            // Print an error message if the priority queue is empty
            cout << "Priority Queue is empty! Cannot peek element" << endl;
            // Return -1 to indicate an error or failure
            return -1;
        }

        // Return the data from the front node without removing it
        return front->data;
    }

    // Print the priority queue elements
    void printQueue() {
        // Start with the front node and traverse the priority queue
        Node* temp = front;
        cout << "Priority Queue elements (from highest priority to lowest): ";
        // Print the data of each node in the priority queue
        while (temp != nullptr) {
            cout << temp->data << "(" << temp->priority << ") ";
            // Move to the next node
            temp = temp->next;
        }
        // End the line after printing all elements
        cout << endl;
    }
};
