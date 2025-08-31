#include<iostream>
using namespace std;
struct node{
    int data;
    node*left,*right;
    node(int val){
        data=val;
        left= NULL;
        right=NULL;
    }
};
node*insert(node*root,int val){
    if(root==NULL){
        return new node(val);
    }
    if(val<root->data){
        root->left=insert(root->left,val);
    }else{
        //val>root->data
        root->right=insert(root->right,val);
    }
    return root;
}
void inorder(node*root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);//inorder of bst is always  sorted 
}
bool search(node* root,  int val) {
    if (root == NULL) {
        return false;
    }
    
    if (root->data == val) {
        return true;
    } else if (val < root->data) {
        return search(root->left, val);
    } else {
        return search(root->right, val);
    }
}
node* createUserDefinedBST() {
    node* root = NULL;
    int numElements, val;
    
    std::cout << "Enter the number of elements to insert into the BST: ";
    std::cin >> numElements;
    
    std::cout << "Enter the elements:\n";
    for (int i = 0; i < numElements; ++i) {
        std::cin >> val;
        root = insert(root, val);
    }
    
    return root;
}

int main() {
    node* root = createUserDefinedBST(); // Create BST with user-provided elements
    int choice, val;

    while (true) {
        std::cout << "1. Insert an element\n";
        std::cout << "2. Search for an element\n";
        std::cout << "3. Print in-order traversal\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter value to insert: ";
                std::cin >> val;
                root = insert(root, val);
                break;
            case 2:
                std::cout << "Enter value to search: ";
                std::cin >> val;
                if (search(root, val)) {
                    std::cout << "Value found in the BST.\n";
                } else {
                    std::cout << "Value not found in the BST.\n";
                }
                break;
            case 3:
                std::cout << "In-order traversal of the BST: ";
                inorder(root);
                std::cout << std::endl;
                break;
            case 4:
                return 0;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }
    
    return 0;
}


