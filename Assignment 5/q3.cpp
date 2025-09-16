//Write a program to find the middle of a linked list.

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
  void findMiddle(){
    Node* temp1 = head;
    Node* temp2 = head;
    while(temp2 && temp2->next){
      temp1 = temp1->next;
      temp2 = temp2->next->next;
    }
    cout<<"Middle node is : "<<temp1->data<<endl;
  }
};

int main(){
  LinkedList obj;
  obj.createLinkedList();
  cout<<"Linked list is "<<endl;
  obj.display();
  obj.findMiddle();
  return 0;
}