#include <iostream>

using namespace std;

// Define a Queue class using an array
class Queue {
private:
    // Array to store the elements of the queue
    int *arr; 
    // Index of the front element of the queue
    int front; 
    // Index of the rear element of the queue
    int rear; 
    // Maximum capacity of the queue
    int capacity; 
    // Current size of the queue
    int size; 

public:
    // Constructor to initialize the queue
    Queue(int capacity) {
        // Set the maximum capacity of the queue
        this->capacity = capacity; 
        // Initialize front index to 0
        this->front = 0; 
        // Initialize rear index to 0
        this->rear = 0; 
        // Set the size of the queue to 0 indicating it is empty
        this->size = 0; 
        // Dynamically allocate memory for the queue array
        this->arr = new int[capacity]; 
    }

    // Destructor to free memory
    ~Queue() {
        // Free the memory allocated for the queue array
        delete[] arr; 
    }

    // Check if the queue is empty
    bool isEmpty() {
        // Return true if the size of the queue is 0, indicating it is empty
        return size == 0; 
    }

    // Check if the queue is full
    bool isFull() {
        // Return true if the size of the queue equals the maximum capacity
        return size == capacity; 
    }

    // Enqueue an element into the queue
    void enqueue(int element) {
        // Check if the queue is full before adding a new element
        if (isFull()) { 
            // Print error message if the queue is full
            cout << "Queue Overflow! Cannot enqueue element " << element << endl; 
            // Exit the function without adding the element
            return; 
        }
        // Add the element at the rear position
        arr[rear] = element; 
        // Increment the rear index
        rear++; 
        // Increment the size of the queue
        size++; 
    }

    // Dequeue an element from the queue
    int dequeue() {
        // Check if the queue is empty before attempting to dequeue
        if (isEmpty()) { 
            // Print error message if the queue is empty
            cout << "Queue Underflow! Cannot dequeue element" << endl; 
            // Return -1 to indicate failure or throw an exception
            return -1; 
        }
        // Retrieve the element at the front of the queue
        int element = arr[front]; 
        // Shift all elements to the left by one position to maintain the order
        for (int i = 0; i < size - 1; i++) { 
            arr[i] = arr[i + 1]; 
        }
        // Decrement the rear index
        rear--; 
        // Decrement the size of the queue
        size--; 
        // Return the dequeued element
        return element; 
    }

    // Get the front element without removing it
    int peek() {
        // Check if the queue is empty before peeking
        if (isEmpty()) { 
            // Print error message if the queue is empty
            cout << "Queue is empty! Cannot peek element" << endl; 
            // Return -1 to indicate failure or throw an exception
            return -1; 
        }
        // Return the element at the front of the queue
        return arr[front]; 
    }

    // Print the queue elements
    void printQueue() {
        // Print a header for the queue elements
        cout << "Queue elements: "; 
        // Loop through the queue and print each element
        for (int i = 0; i < size; i++) { 
            cout << arr[i] << " "; 
        }
        // End the line after printing all elements
        cout << endl; 
    }
};
