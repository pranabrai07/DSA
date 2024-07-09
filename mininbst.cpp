#include <iostream>
using namespace std;
struct node{
    int data;
    node*left,*right;
    node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};
node* insertbst(node*root,int val){
    if(root==NULL){
        return new node(val);
    }
    if(val<root->data){
        root->left=insertbst(root->left,val);
    }else{
        //val>root->data
        root->right=insertbst(root->right,val);
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
bool findMin(node* root, int& minElement) {
    if (root == NULL) {
        return false; // Tree is empty
    }
    
    node* current = root;
    while (current->left != NULL) {
        current = current->left;
    }
    
    minElement = current->data;
    return true;
}
int main()
{
    node *root=NULL;
    root=insertbst(root,5);
    root=insertbst(root,1);
    root=insertbst(root,3);
    root=insertbst(root,4);
    root=insertbst(root,2);
    root=insertbst(root,7);
    inorder(root);
    cout<<endl;
    int minElement;
    bool success = findMin(root, minElement);
    
    if (success) {
        cout << "Minimum element in the BST: " << minElement << endl;
    } else {
        cerr << "Tree is empty" << endl;
    }
    
    return 0;
}

