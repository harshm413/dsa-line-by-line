#include <iostream>
using namespace std;

// Node class to represent a single node in the linked list
class Node {
public:
    int data;       // Data stored in the node
    Node* next;     // Pointer to the next node in the list

    // Constructor to initialize a node with given data and null next pointer
    Node(int data) {
        this->data = data;  // Initialize the data of the node
        this->next = nullptr;  // Set the next pointer to null (no next node yet)
    }
};

// LinkedList class to manage the operations on the list
class LinkedList {
private:
    Node* head;  // Pointer to the head (first node) of the list

public:
    // Constructor to initialize an empty linked list
    LinkedList() {
        head = nullptr;  // Set the head to nullptr indicating the list is empty
    }

    // Destructor to free all allocated memory when the list is destroyed
    ~LinkedList() {
        Node* current = head;  // Start from the head node
        // Iterate through all nodes and delete them
        while (current != nullptr) {
            Node* temp = current->next;  // Store the next node before deleting the current one
            delete current;  // Delete the current node to free memory
            current = temp;  // Move to the next node
        }
    }

    // Method to insert a new node at the beginning of the list
    void insertAtHead(int data) {
        // Create a new node with the given data
        Node* newNode = new Node(data);
        // Point the new node's next to the current head
        newNode->next = head;
        // Update the head to the new node
        head = newNode;
    }

    // Method to insert a new node at the end of the list
    void insertAtTail(int data) {
        // Create a new node with the given data
        Node* newNode = new Node(data);
        // If the list is empty, set the head to the new node
        if (head == nullptr) {
            head = newNode;  // Set the new node as the head of the list
            return;  // Exit the function as no further action is needed
        }

        // Traverse to the last node in the list
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;  // Move to the next node
        }
        // Set the next of the last node to the new node
        current->next = newNode;
    }

    // Method to insert a new node at a specific position
    void insertAtPosition(int position, int data) {
        // If the position is the beginning, use insertAtHead
        if (position == 0) {
            insertAtHead(data);  // Insert the node at the beginning
            return;
        }

        // Create a new node with the given data
        Node* newNode = new Node(data);
        Node* current = head;  // Start from the head
        int currentIndex = 0;  // Initialize the current index

        // Traverse to the node just before the desired position
        while (current != nullptr && currentIndex < position - 1) {
            current = current->next;  // Move to the next node
            currentIndex++;  // Increment the index
        }

        // If position is invalid (out of bounds), print a message and return
        if (current == nullptr) {
            cout << "Position out of bounds\n";  // Print an error message
            delete newNode;  // Delete the new node as it will not be used
            return;
        }

        // Insert the new node by updating the next pointers
        newNode->next = current->next;  // Set the new node's next to the current node's next
        current->next = newNode;  // Set the current node's next to the new node
    }

    // Method to delete a node by value
    void deleteByValue(int value) {
        // If the list is empty, print a message and return
        if (head == nullptr) {
            cout << "List is empty\n";  // Print an error message
            return;  // Exit the function
        }

        // If the value is at the head, update the head pointer and delete the node
        if (head->data == value) {
            Node* temp = head;  // Store the current head in temp
            head = head->next;  // Update the head to the next node
            delete temp;  // Delete the old head node
            return;  // Exit the function
        }

        // Traverse the list to find the node with the given value
        Node* current = head;
        while (current->next != nullptr && current->next->data != value) {
            current = current->next;  // Move to the next node
        }

        // If the value is not found, print a message and return
        if (current->next == nullptr) {
            cout << "Value not found in the list\n";  // Print an error message
            return;  // Exit the function
        }

        // Delete the node by updating the next pointer of the previous node
        Node* temp = current->next;  // Store the node to be deleted
        current->next = temp->next;  // Bypass the node to be deleted
        delete temp;  // Delete the node
    }

    // Method to delete a node at a specific position
    void deleteAtPosition(int position) {
        // If the list is empty, print a message and return
        if (head == nullptr) {
            cout << "List is empty\n";  // Print an error message
            return;  // Exit the function
        }

        // If the position is the beginning, update the head and delete the node
        if (position == 0) {
            Node* temp = head;  // Store the current head node in temp
            head = head->next;  // Update the head to the next node
            delete temp;  // Delete the old head node
            return;  // Exit the function
        }

        Node* current = head;  // Start from the head node
        int currentIndex = 0;  // Initialize the current index

        // Traverse to the node just before the desired position
        while (current != nullptr && currentIndex < position - 1) {
            current = current->next;  // Move to the next node
            currentIndex++;  // Increment the index
        }

        // If position is invalid (out of bounds), print a message and return
        if (current == nullptr || current->next == nullptr) {
            cout << "Position out of bounds\n";  // Print an error message
            return;  // Exit the function
        }

        // Delete the node by updating the next pointer of the previous node
        Node* temp = current->next;  // Store the node to be deleted
        current->next = temp->next;  // Bypass the node to be deleted
        delete temp;  // Delete the node
    }

    // Method to delete a node from the beginning (head)
    void deleteFromBeginning() {
        // If the list is empty, print a message and return
        if (head == nullptr) {
            cout << "List is empty\n";  // Print an error message
            return;  // Exit the function
        }

        Node* temp = head;  // Store the current head node in temp
        head = head->next;  // Update the head to the next node
        delete temp;  // Delete the old head node
    }

    // Method to delete a node from the end (tail)
    void deleteFromEnd() {
        // If the list is empty, print a message and return
        if (head == nullptr) {
            cout << "List is empty\n";  // Print an error message
            return;  // Exit the function
        }

        // If the list has only one node, delete it
        if (head->next == nullptr) {
            delete head;  // Delete the only node in the list
            head = nullptr;  // Set the head to null as the list is now empty
            return;  // Exit the function
        }

        // Traverse to the second last node in the list
        Node* current = head;
        while (current->next->next != nullptr) {
            current = current->next;  // Move to the next node
        }

        // Delete the last node (current->next is the last node)
        Node* temp = current->next;  // Store the last node in temp
        current->next = nullptr;  // Set the second last node's next to null
        delete temp;  // Delete the last node
    }

    // Method to search for a value in the list
    bool search(int value) {
        // Traverse the list to look for the value
        Node* current = head;
        while (current != nullptr) {
            // If the value is found, return true
            if (current->data == value) {
                return true;  // Value found
            }
            current = current->next;  // Move to the next node
        }
        // If the value is not found, return false
        return false;  // Value not found
    }

    // Method to print all elements in the list
    void printList() {
        // Start from the head and traverse the list
        Node* current = head;
        while (current != nullptr) {
            // Print the data of the current node
            cout << current->data << " -> ";  // Display the current node's data
            current = current->next;  // Move to the next node
        }
        // Print null to indicate the end of the list
        cout << "null\n";  // Indicate the end of the list
    }
};