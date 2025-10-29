// Delete an existing element in Binary Search tree

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
    if(root->data == val){
      cout<<val<<"Already exists can't insert"<<endl;
      return root;
    }
    if(val < root->data){
      root->left = insert(root->left, val);
    }
    else if(val > root->data){
      root->right = insert(root->right, val);
    }
    return root;
  }

  Node* findMin(Node* root) {
    while (root && root->left)
      root = root->left;
    return root;
  }
  
  Node* deleteNode(Node* root, int val){
    if(root == nullptr){
      return nullptr;
    }
    if(val < root->data){
      root->left = deleteNode(root->left, val);
    }
    else if(val > root->data){
      root->right = deleteNode(root->right, val);
    }
    else{
      // no or one child;
      if(root->left == nullptr){
        Node* temp = root->right;
        delete root;
        return temp;
      }
      else if(root->right == nullptr){
        Node* temp = root->left;
        delete root;
        return temp;
      }
      // two children
      else{
        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
      }
    }
    return root;
  }
  void inorder(Node* root){
    if(root == nullptr){
      return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
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
  cout<<"Enter value you wanna delete :";
  cin>>x;
  t.root = t.deleteNode(t.root, x);
  t.inorder(t.root);

  return 0;
}