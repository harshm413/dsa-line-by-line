#include <iostream>
#include <queue>

using namespace std;

// Define a Node class for the BST
class Node {
public:
    // Data stored in the node
    int data; 
    // Pointer to the left child of the node
    Node* left; 
    // Pointer to the right child of the node
    Node* right; 

    // Constructor to initialize a node with a given data value
    Node(int data) {
        // Set the data of the node
        this->data = data; 
        // Initialize left and right pointers to nullptr (no children)
        this->left = nullptr; 
        this->right = nullptr; 
    }
};

// Define a BSTree class
class BSTree {
private:
    // Pointer to the root node of the tree
    Node* root; 

public:
    // Constructor to initialize the BST
    BSTree() {
        // Initialize the root to null, indicating an empty tree
        this->root = nullptr; 
    }

    // Destructor to free memory used by the tree
    ~BSTree() {
        // When the BST object is destroyed, delete the entire tree starting from the root
        deleteTree(root); 
    }

    // Delete tree helper function (recursive)
    void deleteTree(Node* node) {
        // Base case: If the node is null, return (no node to delete)
        if (node == nullptr) {
            return;
        }
        // Recursively delete the left subtree
        deleteTree(node->left); 
        // Recursively delete the right subtree
        deleteTree(node->right); 
        // After the left and right subtrees are deleted, delete the current node
        delete node; 
    }

    // Insert a node into the BST
    void insert(int value) {
        // Start the insertion process from the root node
        root = insert(root, value); 
    }

    // Insert node helper function (recursive)
    Node* insert(Node* node, int value) {
        // Base case: If the node is null, we've found the position to insert the new node
        if (node == nullptr) {
            // Create and return a new node with the given value
            return new Node(value); 
        }

        // If the value is smaller than the current node's data, insert in the left subtree
        if (value < node->data) { 
            node->left = insert(node->left, value); 
        } else { 
            // If the value is greater or equal to the current node's data, insert in the right subtree
            node->right = insert(node->right, value); 
        }
        // Return the unchanged node (because we might be inserting deeper in the tree)
        return node; 
    }

    // Preorder traversal of the tree (root, left, right)
    void preorderTraversal() {
        // Start the traversal from the root node
        preorderTraversalNode(root); 
    }

    // Preorder traversal helper function (recursive)
    void preorderTraversalNode(Node* node) {
        // Base case: If the node is null, do nothing
        if (node == nullptr) {
            return;
        }
        // Print the current node's data
        cout << node->data << " "; 
        // Recursively traverse the left subtree
        preorderTraversalNode(node->left); 
        // Recursively traverse the right subtree
        preorderTraversalNode(node->right); 
    }

    // Level order traversal of the tree (Breadth-first)
    void levelOrderTraversal() {
        // If the tree is empty, there is no traversal to perform
        if (root == nullptr) {
            return; 
        }
        // Create a queue to manage nodes while performing level order traversal
        queue<Node*> q; 
        // Push the root node into the queue to begin the traversal
        q.push(root); 
        // Traverse the tree level by level
        while (!q.empty()) {
            // Pop the front node from the queue
            Node* current = q.front(); 
            // Remove the node from the queue
            q.pop(); 
            // Print the current node's data
            cout << current->data << " "; 
            // If the current node has a left child, add it to the queue
            if (current->left != nullptr) {
                q.push(current->left); 
            }
            // If the current node has a right child, add it to the queue
            if (current->right != nullptr) {
                q.push(current->right); 
            }
        }
    }

    // Function to compute the height of the tree
    int height() {
        // Call the recursive function to compute the height starting from the root
        return heightNode(root); 
    }

    // Helper function to calculate the height of a node (subtree height)
    int heightNode(Node* node) {
        // Base case: If the node is null, its height is 0 (no height for an empty node)
        if (node == nullptr) {
            return 0;
        }
        // The height of the node is 1 plus the maximum of the heights of its left and right subtrees
        return 1 + max(heightNode(node->left), heightNode(node->right)); 
    }

    // Function to compute the depth of a node given its data value
    int depth(int data) {
        // Call the recursive helper function to find the depth of the node
        return depthNode(root, data, 0); 
    }

    // Helper function to calculate the depth of a node recursively
    int depthNode(Node* node, int data, int currentDepth) {
        // Base case: If the node is null, the depth doesn't exist (-1)
        if (node == nullptr) {
            return -1; 
        }
        // If the current node's data matches the search data, return the current depth
        if (node->data == data) {
            return currentDepth; 
        }
        // Recursively search the left subtree and increment the depth
        int leftDepth = depthNode(node->left, data, currentDepth + 1); 
        // If the depth is found in the left subtree, return it
        if (leftDepth != -1) {
            return leftDepth; 
        }
        // Recursively search the right subtree and increment the depth
        return depthNode(node->right, data, currentDepth + 1); 
    }

    // Function to search for a node with a specific data value
    bool search(int data) {
        // Call the recursive function to search for the node
        return searchNode(root, data); 
    }

    // Helper function to search for a node recursively
    bool searchNode(Node* node, int data) {
        // Base case: If the node is null, the data is not found
        if (node == nullptr) {
            return false; 
        }
        // If the current node contains the data, return true (data found)
        if (node->data == data) {
            return true; 
        }
        // If the data is smaller, search in the left subtree
        if (data < node->data) {
            return searchNode(node->left, data); 
        } else { 
            // If the data is greater, search in the right subtree
            return searchNode(node->right, data); 
        }
    }

    // Function to delete a node with a specific data value
    void deleteNode(int data) {
        // Call the recursive function to delete the node from the tree
        root = deleteNodeNode(root, data); 
    }

    // Helper function to delete a node recursively
    Node* deleteNodeNode(Node* node, int data) {
        // Base case: If the node is null, return it (no deletion)
        if (node == nullptr) {
            return node; 
        }
        // If the data is smaller than the current node's data, recurse on the left subtree
        if (data < node->data) {
            node->left = deleteNodeNode(node->left, data); 
        } else if (data > node->data) {
            // If the data is larger than the current node's data, recurse on the right subtree
            node->right = deleteNodeNode(node->right, data); 
        } else { 
            // Case 1: If the node has only one child or no child
            if (node->left == nullptr) {
                // Store the pointer to the right child temporarily
                Node* temp = node->right;
                // Delete the current node
                delete node;
                // Return the right child (it will replace the current node)
                return temp; 
            } else if (node->right == nullptr) {
                // Store the pointer to the left child temporarily
                Node* temp = node->left;
                // Delete the current node
                delete node;
                // Return the left child (it will replace the current node)
                return temp; 
            }
            // Case 2: If the node has two children
            // Find the node with the minimum value in the right subtree (inorder successor)
            Node* temp = minValueNode(node->right); 
            // Copy the inorder successor's data to the current node
            node->data = temp->data; 
            // Delete the inorder successor (recursively delete the node)
            node->right = deleteNodeNode(node->right, temp->data); 
        }
        // Return the updated node (after deletion)
        return node; 
    }

    // Find the node with the minimum value in the tree (leftmost node)
    Node* minValueNode(Node* node) {
        // Traverse to the leftmost child to find the node with the smallest value
        Node* current = node;
        while (current->left != nullptr) {
            current = current->left; 
        }
        // Return the leftmost node (node with the minimum value)
        return current; 
    }
};
