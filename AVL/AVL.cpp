#include <iostream>

using namespace std;

// Define the Node class for the AVL Tree
class Node {
public:
    // Data field: Stores the actual value of the node
    int data; 

    // Pointer to the left child node
    Node* left; 

    // Pointer to the right child node
    Node* right; 

    // Height field: Used for balancing the AVL tree, stores the height of the node
    int height; 

    // Constructor for initializing the node with a given value
    Node(int data) {
        // Assign the given data to the node's data field
        this->data = data; 
        // Initialize both left and right pointers to nullptr (no children initially)
        this->left = nullptr; 
        this->right = nullptr; 
        // Initialize the height to 1, as it's a leaf node initially
        this->height = 1; 
    }
};

// Define the AVLTree class, which manages the AVL tree operations
class AVLTree {
private:
    // Pointer to the root node of the AVL tree
    Node* root; 

public:
    // Constructor to initialize the AVL Tree with an empty root
    AVLTree() {
        // Initially, the tree is empty, so root is set to nullptr
        this->root = nullptr; 
    }

    // Helper function to get the height of a node (used to calculate balance factors)
    int getHeight(Node* node) {
        // If the node is nullptr, it has no height, so return 0
        if (node == nullptr) {
            return 0; 
        }
        // Otherwise, return the height of the node
        return node->height; 
    }

    // Helper function to update the height of a given node
    void updateHeight(Node* node) {
        // Update the height of the node to 1 plus the maximum height of its left and right subtrees
        node->height = 1 + max(getHeight(node->left), getHeight(node->right)); 
    }

    // Helper function to calculate the balance factor of a node
    int getBalance(Node* node) {
        // If the node is nullptr, it is balanced, so return 0
        if (node == nullptr) {
            return 0; 
        }
        // Calculate and return the balance factor as the difference between the left and right subtree heights
        return getHeight(node->left) - getHeight(node->right); 
    }

    // Function for performing a left rotation to balance a right-heavy node
    Node* leftRotate(Node* node) {
        // Temporary node to hold the right child of the current node
        Node* temp = node->right; 
        
        // Make the left child of the right node the new right child of the current node
        node->right = temp->left; 
        
        // Move the current node to the left child of the right node
        temp->left = node; 
        
        // After rotation, update the heights of the affected nodes
        updateHeight(node); 
        updateHeight(temp); 

        // Return the new root of the subtree (which is the temp node)
        return temp; 
    }

    // Function for performing a right rotation to balance a left-heavy node
    Node* rightRotate(Node* node) {
        // Temporary node to hold the left child of the current node
        Node* temp = node->left; 
        
        // Make the right child of the left node the new left child of the current node
        node->left = temp->right; 
        
        // Move the current node to the right child of the left node
        temp->right = node; 
        
        // After rotation, update the heights of the affected nodes
        updateHeight(node); 
        updateHeight(temp); 

        // Return the new root of the subtree (which is the temp node)
        return temp; 
    }

    // Recursive function to insert a new node into the AVL tree
    Node* insertNode(Node* node, int data) {
        // If the node is nullptr, it means we have found an empty spot for the new node
        if (node == nullptr) {
            return new Node(data); 
        }

        // If the data is smaller than the current node's data, insert it into the left subtree
        if (data < node->data) {
            node->left = insertNode(node->left, data); 
        } 
        // If the data is larger than the current node's data, insert it into the right subtree
        else if (data > node->data) {
            node->right = insertNode(node->right, data); 
        } 
        // If the data is equal to the current node's data, return the node (no duplicates allowed)
        else {
            return node; 
        }

        // Update the height of the current node after insertion
        updateHeight(node); 

        // Calculate the balance factor of the current node
        int balance = getBalance(node); 

        // If the balance factor is greater than 1, it indicates that the left subtree is too heavy
        if (balance > 1) {
            // If the data is less than the left child's data, perform a right rotation (Left-Left case)
            if (data < node->left->data) {
                return rightRotate(node); 
            } 
            // If the data is greater than the left child's data, perform a left-right rotation (Left-Right case)
            else {
                node->left = leftRotate(node->left); 
                return rightRotate(node); 
            }
        }

        // If the balance factor is less than -1, it indicates that the right subtree is too heavy
        if (balance < -1) {
            // If the data is greater than the right child's data, perform a left rotation (Right-Right case)
            if (data > node->right->data) {
                return leftRotate(node); 
            } 
            // If the data is less than the right child's data, perform a right-left rotation (Right-Left case)
            else {
                node->right = rightRotate(node->right); 
                return leftRotate(node); 
            }
        }

        // If the tree is balanced, return the node
        return node; 
    }

    // Recursive function to delete a node from the AVL tree
    Node* deleteNode(Node* node, int data) {
        // Base case: If the node is nullptr, return nullptr (no node to delete)
        if (node == nullptr) {
            return node; 
        }

        // If the data is smaller than the current node's data, recurse into the left subtree
        if (data < node->data) {
            node->left = deleteNode(node->left, data); 
        } 
        // If the data is larger than the current node's data, recurse into the right subtree
        else if (data > node->data) {
            node->right = deleteNode(node->right, data); 
        } 
        // If the current node contains the data to be deleted
        else {
            // If the node has no left child, replace it with its right child
            if (node->left == nullptr) {
                Node* temp = node->right; 
                delete node; 
                return temp; 
            } 
            // If the node has no right child, replace it with its left child
            else if (node->right == nullptr) {
                Node* temp = node->left; 
                delete node; 
                return temp; 
            }

            // If the node has both left and right children, find the inorder successor (smallest node in the right subtree)
            Node* temp = node->right; 
            while (temp->left != nullptr) {
                temp = temp->left; 
            }

            // Copy the inorder successor's data to the current node
            node->data = temp->data; 
            // Delete the inorder successor from the right subtree
            node->right = deleteNode(node->right, temp->data); 
        }

        // If the node is null (after deletion), return null
        if (node == nullptr) {
            return node; 
        }

        // Update the height of the current node after deletion
        updateHeight(node); 

        // Calculate the balance factor of the current node
        int balance = getBalance(node); 

        // If the balance factor is greater than 1, it indicates that the left subtree is too heavy
        if (balance > 1) {
            // If the left child is left-heavy, perform a right rotation (Left-Left case)
            if (getBalance(node->left) >= 0) {
                return rightRotate(node); 
            } 
            // If the left child is right-heavy, perform a left-right rotation (Left-Right case)
            else {
                node->left = leftRotate(node->left); 
                return rightRotate(node); 
            }
        }

        // If the balance factor is less than -1, it indicates that the right subtree is too heavy
        if (balance < -1) {
            // If the right child is right-heavy, perform a left rotation (Right-Right case)
            if (getBalance(node->right) <= 0) {
                return leftRotate(node); 
            } 
            // If the right child is left-heavy, perform a right-left rotation (Right-Left case)
            else {
                node->right = rightRotate(node->right); 
                return leftRotate(node); 
            }
        }

        // If the tree is balanced, return the node
        return node; 
    }

    // Public function to insert a new node into the AVL tree
    void insert(int data) {
        // Insert the new data into the tree, and update the root pointer
        root = insertNode(root, data); 
    }

    // Public function to delete a node from the AVL tree
    void deleteNode(int data) {
        // Delete the node from the tree, and update the root pointer
        root = deleteNode(root, data); 
    }
};
