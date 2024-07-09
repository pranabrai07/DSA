#include<iostream>
using namespace std;
struct node{
    int data;
    node*left,*right,*temp;
    node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};
void swapleftright( node* node){
    if (node == NULL) return;
    
    // Swap the left and right children
    node->temp = node->left;
    node->left = node->right;
    node->right =  node->temp;
    
    // Recur for left and right subtrees
    swapleftright(node->left);
    swapleftright(node->right);

}

void inorder(node*root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);//inorder of bst is always  sorted 
}


int main()
{
    node *root=new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    
    
    inorder(root);
    cout<<"inorder traversal before swapping:";
    cout<<endl;
    swapleftright(root);
    cout<<"inorder traversal after swapping:";
    cout<<endl;
    inorder(root);
    return 0;
}
