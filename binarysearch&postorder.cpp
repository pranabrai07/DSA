#include<iostream>
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
/*         2
		/	  \
		1	   7
		  \
		  3
		/	\
		2	4 
*/


void postorder(node*root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    ;
    postorder(root->right);//inorder of bst is always  sorted 
    cout<<root->data<<" ";
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
    postorder(root);
    cout<<endl;
    return 0;
}

