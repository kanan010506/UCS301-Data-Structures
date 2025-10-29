//Minimum depth of BST p

#include<iostream>
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

class BST{
  public :
  Node* root;
  BST(){
    root = nullptr;
  }
  Node* insert(Node* root, int val){
    if(root == nullptr){
      return new Node(val);
    }
    if(val < root->data){
      root->left = insert(root->left, val);
    }
    else if(val > root->data){
      root->right = insert(root->right, val);
    }
    return root;
  }
  
  int minDepth(Node* root){
    if(root == nullptr){
      return 0;
    }
    if(root->left == nullptr){
      return 1 + minDepth(root->right);
    }
    if(root->right == nullptr){
      return 1 + minDepth(root->left);
    }
    return 1 + min(minDepth(root->left), minDepth(root->right));
  }
  
};

int main(){
  BST t;
  int n;
  cout<<"Enter number of nodes : ";
  cin>>n;
  int x;
  for(int i=0; i<n; i++){
    cout<<"Enter value : ";
    cin>>x;
    t.root = t.insert(t.root, x);
  }
  cout<<"Minimum depth of binary search tree is "<<t.minDepth(t.root);

  return 0;
}