//Write program using functions for binary tree traversals: Pre-order, In-order and Post-order using recursive approach.
#include<iostream>
#include<queue>
using namespace std;

class Node{
  public :
  int data;
  Node* left;
  Node* right;
  Node(int val){
    data = val;
    left = nullptr;
    right = nullptr;
  }
  Node(){
    data = 0;
    left = nullptr;
    right = nullptr;
  }
};

class Tree{
  public :
  Node* root;
  Tree(){
    cout<<"Enter value of root : ";
    int x, leftVal, rightVal;
    cin>>x;
    root = new Node(x);
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
      cout<<"Enter the left child of "<<q.front()->data<<" (-1 for null) : ";
      cin>>leftVal;
      cout<<"Enter the right child of "<<q.front()->data<<" (-1 for null) : ";
      cin>>rightVal;
      if(leftVal == -1 && rightVal == -1){
        q.front()->left = nullptr;
        q.front()->right = nullptr;
      }
      else if(leftVal == -1){
        q.front()->left = nullptr;
        q.front()->right = new Node(rightVal);
        q.push(q.front()->right);
      }
      else if(rightVal == -1){
        q.front()->right = nullptr;
        q.front()->left = new Node(leftVal);
        q.push(q.front()->left);
      }
      else{
        q.front()->left = new Node(leftVal);
        q.front()->right = new Node(rightVal);
        q.push(q.front()->left);
        q.push(q.front()->right);
      }
      q.pop();
    }
  }

  void preorder(Node* root){
    if(root == nullptr){
      return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
  }
  void inorder(Node* root){
    if(root == nullptr){
      return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
  }
  void postorder(Node* root){
    if(root == nullptr){
      return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
  }
};

int main(){
  Tree t;
  cout<<"Preorder Travesel : "<<endl;
  t.preorder(t.root);
  cout<<endl;
  cout<<"Inorder Travesel : "<<endl;
  t.inorder(t.root);
  cout<<endl;
  cout<<"Postorder Travesel : "<<endl;
  t.postorder(t.root);
  cout<<endl;

  return 0;
}