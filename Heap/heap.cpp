#include <iostream>
#include <vector>
using namespace std;

// Define the Heap class
class Heap {
private:
    // Vector to store heap elements
    vector<int> heap;

    // Helper method to calculate the parent index of a given index
    int parent(int index) { 
        return (index - 1) / 2; 
    }

    // Helper method to calculate the left child index of a given index
    int leftChild(int index) { 
        return (2 * index + 1); 
    }

    // Helper method to calculate the right child index of a given index
    int rightChild(int index) { 
        return (2 * index + 2); 
    }

    // Method to restore heap property after insertion by moving up
    void heapifyUp(int index) {
        // Check if the current node is not the root and the parent node is smaller
        if (index && heap[parent(index)] < heap[index]) {
            // Swap the current node with its parent to maintain max-heap property
            swap(heap[index], heap[parent(index)]);
            // Recursively move up to ensure the entire path satisfies the heap property
            heapifyUp(parent(index));
        }
    }

    // Method to restore heap property after deletion by moving down
    void heapifyDown(int index) {
        // Calculate the indices of the left and right children
        int left = leftChild(index);
        int right = rightChild(index);

        // Assume the largest element is the current node
        int largestChild = index;

        // Check if the left child exists and is larger than the current node
        if (left < size() && heap[left] > heap[index]) 
            largestChild = left;

        // Check if the right child exists and is larger than the largest child found so far
        if (right < size() && heap[right] > heap[largestChild]) 
            largestChild = right;

        // If the largest child is not the current node, perform a swap
        if (largestChild != index) {
            swap(heap[index], heap[largestChild]);
            // Recursively heapify the affected subtree
            heapifyDown(largestChild);
        }
    }

public:
    // Constructor to initialize an empty heap
    Heap() {}

    // Destructor (no dynamic memory to release in this implementation)
    ~Heap() {}

    // Method to get the current size of the heap
    int size() { 
        return heap.size(); 
    }

    // Method to check if the heap is empty
    bool isEmpty() { 
        return size() == 0; 
    }

    // Method to insert a new element into the heap
    void insert(int key) {
        // Add the new element to the end of the vector
        heap.push_back(key);
        // Restore the max-heap property by moving up
        heapifyUp(size() - 1);
    }

    // Method to get the maximum element (root of the heap)
    int getMax() {
        // If the heap is empty, return a message and -1
        if (isEmpty()) {
            cout << "Heap is empty\n";
            return -1;
        }
        // Return the root element (maximum element)
        return heap[0];
    }

    // Method to remove the maximum element (root of the heap)
    void removeMax() {
        // If the heap is empty, print a message and do nothing
        if (isEmpty()) {
            cout << "Heap is empty\n";
            return;
        }

        // If there is only one element, remove it
        if (size() == 1) {
            heap.pop_back();
            return;
        }

        // Replace the root with the last element in the heap
        heap[0] = heap.back();
        // Remove the last element
        heap.pop_back();

        // Restore the max-heap property by heapifying down from the root
        heapifyDown(0);
    }

    // Method to print all elements in the heap
    void printHeap() {
        // Iterate through all elements in the vector
        for (int i = 0; i < size(); i++)
            // Print each element followed by a space
            cout << heap[i] << " ";
        cout << "\n";  // Print a newline at the end
    }

    // Method to build a heap incrementally from an unsorted array
    void buildHeapIncremental(const vector<int>& arr) {
        // Iterate through each element in the input array
        for (int key : arr) {
            // Insert each element into the heap
            insert(key);
        }
    }

    // Method to build a heap optimally from an unsorted array
    void buildHeapOptimal(const vector<int>& arr) {
        // Copy the input array directly into the heap vector
        heap = arr;

        // Calculate the size of the heap
        int n = size();

        // Start from the last non-leaf node and move backward
        for (int i = n / 2 - 1; i >= 0; --i) {
            // Restore the heap property for each subtree
            heapifyDown(i);
        }
    }
};
