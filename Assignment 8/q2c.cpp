//Minimum element of the BST

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
  
  int minElement(){
    if (root == nullptr) {
      cout << "Tree is empty!" << endl;
      return -1;
    }
    Node* curr = root;
    while(curr->left){
      curr = curr->left;
    }
    return curr->data;
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
  x = t.minElement();
  if(x != -1 ){
    cout<<"Minimum data : "<<x;
  }

  return 0;
}