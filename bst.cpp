#include <iostream>
#include <stdio.h>
#define EMPTY_TREE 1;
using namespace std;
struct node{
    node *left;
     int data;
      node *right;
};
class bst{
    private :
     node *root;
     public:
     bst();
     void insert(int);
     node* inorder();
     void inorder_traversal(node *);
     bool is_empty();
    node* preorder();
     void preorder_traversal(node *);
    node* postorder();
     void postorder_traversal(node *);
    bool search(int);
};
bool bst::is_empty(){
    return root==NULL;
}
bst::bst(){
    root=NULL;
}
void bst::insert(int data){
   node *ptr;
   
   if(root==NULL){
     node *n=new node;
    n->left=NULL;
    n->data=data;
    n->right=NULL;
    root=n;
   }
   else
   {

    ptr=root;
    int flag=1;
    while(flag){
   if(data>ptr->data){
    if(ptr->right==NULL){   //right subtree
         node *n=new node;
    n->left=NULL;
    n->data=data;
    n->right=NULL;
    ptr->right=n;
    flag=0;
    }
    else
        ptr=ptr->right;
       
   }
   else{               //left subtree
    if(ptr->left==NULL){
         node *n=new node;
    n->left=NULL;
    n->data=data;
    n->right=NULL;
    ptr->left=n;
    flag=0;
    }
    else
        ptr=ptr->left;
       }
   }
   }
 }

 node* bst::inorder(){
    inorder_traversal(root);
}
void bst::inorder_traversal(node *root){

        if(root){
            inorder_traversal(root->left);
            cout<<root->data<<" ";
            inorder_traversal(root->right);
        }
        // else
        // throw EMPTY_TREE;
}

node* bst::preorder(){
    preorder_traversal(root);
}
void bst::preorder_traversal(node *root){

        if(root){
             cout<<root->data<<" ";
           preorder_traversal(root->left);
            preorder_traversal(root->right);
        }
        // else
        // throw EMPTY_TREE;
}

node* bst::postorder(){
    postorder_traversal(root);
}
void bst::postorder_traversal(node *root){

        if(root){
            postorder_traversal(root->left);
            postorder_traversal(root->right);
             cout<<root->data<<" ";
        }
        // else
        // throw EMPTY_TREE;
}

bool bst::search(int data){
    node *ptr;
    ptr=root;
    while(ptr){
        if(data==ptr->data)
        return 1;
        else if(data>ptr->data)
        ptr=ptr->right;
        else
        ptr=ptr->left;
    }
    return 0;
}
int main(){
    bst t;
    t.insert(50);
    t.insert(40);
    t.insert(70);
    t.insert(30);
    t.insert(47);
    t.insert(65);
    t.insert(90);
  t.inorder();
  cout<<endl;
   t.preorder();
   cout<<endl;
   t.postorder();
   cout<<endl;
    cout<<t.is_empty();
     cout<<endl;
     int x=t.search(65);
    if(x==1)
    cout<<"element is found";
    else
    cout<<"element not found";
     return 0;
}