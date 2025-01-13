#include <iostream>
#include <queue>
#include <vector>
#include <cmath>

using namespace std;

// Define the Node class for the Binary Tree
class Node {
public:
    int data;  // The value stored in the node
    Node* left;  // Pointer to the left child node
    Node* right;  // Pointer to the right child node

    // Constructor for initializing a node with a given value
    Node(int data) {
        this->data = data;  // Assign value to the node
        this->left = nullptr;  // Initialize left child as nullptr
        this->right = nullptr;  // Initialize right child as nullptr
    }
};

// Define the BinaryTree class
class BinaryTree {
private:
    Node* root;  // Pointer to the root of the tree

public:
    // Constructor to initialize an empty Binary Tree
    BinaryTree() {
        root = nullptr;  // Initially, the root is null
    }

    // Function to insert a node in level-order (from a vector)
    void buildFromLevelOrder(const vector<int>& arr) {
        if (arr.empty()) {
            return;  // If the array is empty, return without doing anything
        }

        // Call recursive function to build the tree from the array
        root = buildFromLevelOrderHelper(arr, 0);
    }

    // Recursive function to build the tree from level-order array
    Node* buildFromLevelOrderHelper(const vector<int>& arr, int index) {
        if (index >= arr.size() || arr[index] == -1) {
            return nullptr;  // If the index is out of bounds or the value is -1 (no node)
        }

        // Create a new node with the current element in the array
        Node* newNode = new Node(arr[index]);

        // Recursively build left and right subtrees
        newNode->left = buildFromLevelOrderHelper(arr, 2 * index + 1);  // Left child index
        newNode->right = buildFromLevelOrderHelper(arr, 2 * index + 2);  // Right child index

        return newNode;  // Return the created node
    }

    // Function to build a binary tree manually by taking user input
    void buildManually() {
        root = buildManuallyHelper();  // Call recursive helper function to build the tree
    }

    // Recursive helper function for manually building the tree
    Node* buildManuallyHelper() {
        int data;
        cout << "Enter node value (-1 for no node): ";
        cin >> data;

        if (data == -1) {
            return nullptr;  // If -1 is entered, return nullptr (no node)
        }

        Node* newNode = new Node(data);  // Create a new node with the input data

        // Recursively create left and right subtrees
        cout << "Enter left child of " << data << ": " << endl;
        newNode->left = buildManuallyHelper();  // Build left subtree

        cout << "Enter right child of " << data << ": " << endl;
        newNode->right = buildManuallyHelper();  // Build right subtree

        return newNode;  // Return the created node
    }

    // Function to perform inorder traversal (left, root, right)
    void inorder() {
        inorderHelper(root);  // Call recursive helper function
        cout << endl;  // Print newline at the end of traversal
    }

    // Recursive helper function for inorder traversal
    void inorderHelper(Node* node) {
        if (node == nullptr) {
            return;  // If the node is null, return (base case)
        }

        inorderHelper(node->left);  // Traverse left subtree
        cout << node->data << " ";  // Visit current node
        inorderHelper(node->right);  // Traverse right subtree
    }

    // Function to perform preorder traversal (root, left, right)
    void preorder() {
        preorderHelper(root);  // Call recursive helper function
        cout << endl;  // Print newline at the end of traversal
    }

    // Recursive helper function for preorder traversal
    void preorderHelper(Node* node) {
        if (node == nullptr) {
            return;  // If the node is null, return (base case)
        }

        cout << node->data << " ";  // Visit current node
        preorderHelper(node->left);  // Traverse left subtree
        preorderHelper(node->right);  // Traverse right subtree
    }

    // Function to perform postorder traversal (left, right, root)
    void postorder() {
        postorderHelper(root);  // Call recursive helper function
        cout << endl;  // Print newline at the end of traversal
    }

    // Recursive helper function for postorder traversal
    void postorderHelper(Node* node) {
        if (node == nullptr) {
            return;  // If the node is null, return (base case)
        }

        postorderHelper(node->left);  // Traverse left subtree
        postorderHelper(node->right);  // Traverse right subtree
        cout << node->data << " ";  // Visit current node
    }

    // Function to get the height of the binary tree
    int getHeight() {
        return getHeightHelper(root);  // Call recursive helper function
    }

    // Recursive helper function for getting the height of the tree
    int getHeightHelper(Node* node) {
        if (node == nullptr) {
            return 0;  // If the node is null, height is 0
        }

        // Recursively get the height of left and right subtrees, and return the maximum
        return 1 + max(getHeightHelper(node->left), getHeightHelper(node->right));
    }

    // Function to count the number of nodes in the binary tree
    int countNodes() {
        return countNodesHelper(root);  // Call recursive helper function
    }

    // Recursive helper function to count nodes in the tree
    int countNodesHelper(Node* node) {
        if (node == nullptr) {
            return 0;  // If the node is null, count is 0
        }

        // Count the current node plus nodes in the left and right subtrees
        return 1 + countNodesHelper(node->left) + countNodesHelper(node->right);
    }

    // Function to check if the binary tree is balanced (difference of heights between subtrees ≤ 1)
    bool isBalanced() {
        return isBalancedHelper(root);  // Call recursive helper function
    }

    // Recursive helper function to check if the tree is balanced
    bool isBalancedHelper(Node* node) {
        if (node == nullptr) {
            return true;  // If the node is null, it's considered balanced
        }

        // Get the heights of left and right subtrees
        int leftHeight = getHeightHelper(node->left);
        int rightHeight = getHeightHelper(node->right);

        // Check if the height difference is ≤ 1, and recursively check balance of left and right subtrees
        return abs(leftHeight - rightHeight) <= 1 && isBalancedHelper(node->left) && isBalancedHelper(node->right);
    }

    // Function to print nodes at a specific distance from the root
    void printNodesAtDistance(int distance) {
        printNodesAtDistanceHelper(root, distance);  // Call recursive helper function
    }

    // Recursive helper function to print nodes at a specific distance
    void printNodesAtDistanceHelper(Node* node, int distance) {
        if (node == nullptr) {
            return;  // If the node is null, return (base case)
        }

        if (distance == 0) {
            cout << node->data << " ";  // If the distance is 0, print the node's data
        } else {
            printNodesAtDistanceHelper(node->left, distance - 1);  // Go left
            printNodesAtDistanceHelper(node->right, distance - 1);  // Go right
        }
    }

    // Function to check if the tree is a Binary Search Tree (BST)
    bool isBST() {
        return isBSTHelper(root, INT_MIN, INT_MAX);  // Call recursive helper function
    }

    // Recursive helper function to check if the tree is a BST
    bool isBSTHelper(Node* node, int minValue, int maxValue) {
        if (node == nullptr) {
            return true;  // If the node is null, return true (base case)
        }

        // Check if the current node's value is within the valid range
        if (node->data < minValue || node->data > maxValue) {
            return false;  // If the value is out of the range, it's not a BST
        }

        // Recursively check the left and right subtrees with updated ranges
        return isBSTHelper(node->left, minValue, node->data - 1) && 
               isBSTHelper(node->right, node->data + 1, maxValue);
    }

    // Function to print level-order traversal of the tree
    void levelOrder() {
        if (root == nullptr) {
            cout << "Tree is empty!" << endl;
            return;  // If the tree is empty, print message and return
        }

        // Queue to perform level-order traversal
        queue<Node*> q;
        q.push(root);  // Push the root node to the queue

        while (!q.empty()) {
            // Dequeue the current node
            Node* current = q.front();
            q.pop();

            cout << current->data << " ";  // Print the node's data

            // Enqueue the left and right children of the current node (if they exist)
            if (current->left != nullptr) {
                q.push(current->left);
            }
            if (current->right != nullptr) {
                q.push(current->right);
            }
        }
        cout << endl;  // Print newline after the level-order traversal
    }
};

/*
List of Native Methods for Binary Trees
----------------------------------------

1. Traversal Methods:
   a. inorder() - Performs an in-order traversal (left, root, right).
   b. preorder() - Performs a pre-order traversal (root, left, right).
   c. postorder() - Performs a post-order traversal (left, right, root).
   d. levelOrder() - Performs a level-order traversal (breadth-first traversal).

2. Tree Construction:
   a. buildManually() - Builds the tree interactively by taking input from the user.
   b. buildFromLevelOrder() - Builds the tree using a level-order array (vector).

3. Height and Depth:
   a. getHeight() - Returns the height of the binary tree.
   b. getDepth(Node* target) - Computes the depth of a specific node from the root.

4. Node Count:
   a. countNodes() - Counts the total number of nodes in the binary tree.
   b. countLeafNodes() - Counts the number of leaf nodes in the tree.
   c. countNonLeafNodes() - Counts the number of non-leaf nodes.

5. Distance and Path:
   a. printNodesAtDistance(int distance) - Prints all nodes at a specific distance from the root.
   b. printRootToLeafPaths() - Prints all root-to-leaf paths in the tree.

6. Tree Properties:
   a. isBalanced() - Checks if the tree is balanced (difference in subtree heights ≤ 1).
   b. isComplete() - Checks if the tree is a complete binary tree.
   c. isFull() - Checks if the tree is a full binary tree.
   d. isPerfect() - Checks if the tree is a perfect binary tree.

7. Node Relationships:
   a. findLCA(Node* a, Node* b) - Finds the lowest common ancestor of two nodes.
   b. getParent(Node* target) - Finds the parent of a given node.

8. Mirror and Symmetry:
   a. isSymmetric() - Checks if the tree is symmetric (a mirror image of itself).
   b. makeMirror() - Converts the tree into its mirror image.

9. Path Sum and Ancestors:
   a. hasPathSum(int sum) - Checks if there exists a root-to-leaf path with a given sum.
   b. findAncestors(Node* target) - Prints or returns all ancestors of a given node.

10. Tree Validations:
    a. isBST() - Checks if the tree satisfies the Binary Search Tree property.
    b. isSubtree(Node* subRoot) - Checks if one tree is a subtree of another.

11. Diameter and Width:
    a. getDiameter() - Computes the diameter (longest path between any two nodes).
    b. getWidth() - Computes the maximum width of the tree.

12. Deletion and Cleanup:
    a. deleteTree() - Deletes all nodes in the binary tree and frees memory.

13. Miscellaneous:
    a. getNodeLevel(Node* target) - Determines the level of a specific node.
    b. printLeftView() - Prints the left view of the tree.
    c. printRightView() - Prints the right view of the tree.
    d. printTopView() - Prints the top view of the tree.
    e. printBottomView() - Prints the bottom view of the tree.

These methods are general and apply to all binary tree structures, such as Binary Search Trees (BST), AVL trees, and generic Binary Trees. They can be implemented without reliance on properties unique to specific tree types.
*/
