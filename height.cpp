#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Function to find the height of the binary tree.
int findHeight(TreeNode* root) {
    // If the tree is empty, return 0.
    if (root == NULL) {
        return 0;
    }
    // Recursively find the height of the left and right subtrees.
    int leftHeight = findHeight(root->left);
    int rightHeight = findHeight(root->right);
    
    // The height of the current node is the maximum of the heights of its subtrees, plus 1.
    return max(leftHeight, rightHeight) + 1;
}

int main() {
    // Create a sample binary tree.
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);
    
    // Find the height of the binary tree.
    int height = findHeight(root);
    cout << "Height of the binary tree: " << height << endl;
    
    // Clean up allocated memory (not strictly necessary in this small example,
    // but good practice in real applications).
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right->right;
    delete root->right;
    delete root;
    
    return 0;
}
