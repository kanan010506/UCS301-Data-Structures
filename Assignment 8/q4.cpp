//Write a program to determine whether a given binary tree is a BST or not.

#include<iostream>
#include<queue>
#include<climits>
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

  
  bool check(Node* root, int minVal, int maxVal){
    if(root == nullptr){
      return true;
    }
    if(root->data <= minVal || root->data >= maxVal){
      return false;
    }
    return check(root->left, minVal, root->data)  && check(root->right, root->data, maxVal);
  }
  
};

int main(){
  Tree t;
  if(t.check(t.root, INT_MIN, INT_MAX)){
    cout<<"It is a valid binary search tree"<<endl;
  }
  else{
    cout<<"It is not a valid binary search tree"<<endl;
  }

  return 0;
}