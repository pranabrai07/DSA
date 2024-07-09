#include <iostream>
#include <queue>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Function to perform level order traversal on a binary tree.
void levelOrderTraversal(TreeNode* root) {
    if (root == NULL) {
        return;
    }

    // Create a queue to hold nodes at each level.
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        // Get the current node from the queue.
        TreeNode* current = q.front();
        q.pop();

        // Print the current node's value.
        cout << current->val << " ";

        // Add the left child to the queue if it exists.
        if (current->left != NULL) {
            q.push(current->left);
        }

        // Add the right child to the queue if it exists.
        if (current->right != NULL) {
            q.push(current->right);
        }
    }
}

int main() {
    // Create a sample binary tree.
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(8);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    // Perform level order traversal.
    cout << "Level order traversal of the binary tree: ";
    levelOrderTraversal(root);
    cout << endl;

    // Clean up allocated memory.
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right->left;
    delete root->right->right;
    delete root->right;
    delete root;

    return 0;
}
