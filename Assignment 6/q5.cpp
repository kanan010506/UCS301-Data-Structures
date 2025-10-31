//Write a program to check if a linked list is Circular Linked List or not.

#include<iostream>
using namespace std;

class Node {
public:
  int data;
  Node* next;
  Node(int val) {
    data = val;
    next = nullptr;
  }
};

class LinkedList{
  Node* head;
  public :
  LinkedList(){
    int n;
    head = nullptr;
    cout<<"Enter number of nodes : ";
    cin>>n;
    cout<<"Enter values : ";
    int x;
    cin>>x;
    head = new Node(x);
    Node* temp = head;
    for(int i=2; i<=n; i++){
      cin>>x;
      temp->next = new Node(x);
      temp = temp->next;
    }
    cout<<"Wanna  create it circular  (0, 1)";
    cin>>x;
    if(x){
      temp->next = head;
    }
  }
  bool check(){
    Node* temp = head;
    while(temp && temp->next != head){
      temp = temp->next;
    }
    if(temp == nullptr){
      return false;
    }
    return temp->next == head;
  }
};

int main(){
  LinkedList l;
  if(l.check()){
    cout<<"Linked list is circular"<<endl;
  }
  else{
    cout<<"Linked list is not circular"<<endl;
  }
  return 0;
}