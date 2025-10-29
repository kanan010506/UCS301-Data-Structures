//In-order successor of a given node the BST

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
  Node* findNode(int val){
    Node* curr = root;
    while(curr){
      if(curr->data == val){
        break;
      }
      else if(val < curr->data){
        curr = curr->left;
      }
      else{
        curr = curr->right;
      }
    }
    return curr;
  }
  Node* inorderSuccessor(int val){
    Node* target = findNode(val);
    if(target == nullptr){
      return nullptr;
    }
    //target has right subtree
    if(target->right){
      target = target->right;
      while(target->left){
        target = target->left;
      }
      return target;
    }
    //no right subtree;
    Node* succ = nullptr;
    Node* curr = root;
    while(curr){
      if(val > curr->data){
        curr = curr->right;
      }
      else if(val < curr->data){
        succ = curr;
        curr = curr->left;
      }
      else{
        break;
      }
    }
    return succ;
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
  cout<<"Enter value whoes inorder sucessor you want : ";
  cin>>x;
  Node* ans = t.inorderSuccessor(x);
  Node* target = t.findNode(x);
  if(target == nullptr){
    cout<<"Vaule given by you dont exists in tree"<<endl;
  }
  else if(ans == nullptr){
    cout<<"No inorder successor exists"<<endl;
  }
  else{
    cout<<"Ans : "<<ans->data<<endl;
  }
  return 0;
}