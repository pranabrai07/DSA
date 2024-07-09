#include <iostream>

// Define a structure for tree nodes
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Function to create a new node
Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->left = NULL; // Change nullptr to NULL
    newNode->right = NULL; // Change nullptr to NULL
    return newNode;
}

// Function to insert a value into the BST
Node* insert(Node* root, int value) {
    if (root == NULL) { // Change nullptr to NULL
        return createNode(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }

    return root;
}

// Function to find the maximum value in the BST
int findMax(Node* root) {
    while (root->right != NULL) { // Change nullptr to NULL
        root = root->right;
    }
    return root->data;
}

int main() {
    // Create an empty BST
    Node* root = NULL; // Change nullptr to NULL
    int numValues;
    std::cout << "Enter the number of values to insert into the BST: ";
    std::cin >> numValues;

    // Insert values into the BST
    std::cout << "Enter " << numValues << " values:" << std::endl;
    int value;
    for (int i = 0; i < numValues; ++i) {
        std::cin >> value;
        root = insert(root, value);
    }

    // Find the maximum value in the BST
    int maxValue = findMax(root);
    std::cout << "Maximum value in the BST: " << maxValue << std::endl;

    return 0;
}

