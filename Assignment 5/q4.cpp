//Write a program to reverse a linked list.

#include<iostream>
using namespace std;

class Node{
  public:
  int data;
  Node* next;
  Node(int val){
    data = val;
    next = nullptr;
  }
};

class LinkedList{
  private :
  Node* head ;
  public :
  void createLinkedList(){
    cout<<"Enter number of nodes (dont enter 0): ";
    int n;
    cin>>n;
    int val;
    cout<<"Enter node value : ";
    cin>>val;
    head = new Node(val);
    Node * temp = head;
    for(int i=1; i<n; i++){
      cout<<"Enter node value : ";
      cin>>val;
      temp->next = new Node(val);
      temp = temp->next;
    }
  }
  void display(){
    Node * temp = head;
    while(temp){
      cout<<temp->data<<" ";
      temp = temp->next;
    }
    cout<<endl;
  }
  void reverse(){
    Node* temp = head;
    Node* prev = nullptr;
    Node* front ;
    while(temp){
      front = temp->next;
      temp->next = prev;
      prev = temp;
      temp = front;
    }
    head = prev;
  }
};

int main(){
  LinkedList obj;
  obj.createLinkedList();
  cout<<"Linked list is "<<endl;
  obj.display();
  obj.reverse();
  cout<<"Reversed Linked list is "<<endl;
  obj.display();
  return 0;
}