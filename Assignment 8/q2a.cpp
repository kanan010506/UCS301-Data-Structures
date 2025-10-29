//Search a given item (Recursive & Non-Recursive) in Binary Search Tree
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
  bool SearchRecursive(Node* root, int val){
    if(root == nullptr){
      return false;
    }
    if(root->data == val){
      return true;
    }
    if(val < root->data){
      return SearchRecursive(root->left, val);
    }
    else{
      return SearchRecursive(root->right, val);
    }
  }
  bool search(Node* root, int val){
    while(root){
      if(root->data == val){
        return true;
      }
      if(val < root->data){
        root = root->left;
      }
      else{
        root = root->right;
      }
    }
    return false;
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
  cout<<"Enter value you wanna search : ";
  cin>>x;
  if(t.search(t.root,x)){
    cout<<"Value exists";
  }
  else{
    cout<<"Value don't exists";
  }
  cout<<"Enter value you wanna search : ";
  cin>>x;
  if(t.SearchRecursive(t.root,x)){
    cout<<"Value exists";
  }
  else{
    cout<<"Value don't exists";
  }

  return 0;
}