//Write a program to count the number of occurrences of a given key in a singly linked list and then delete all the occurrences.

#include<iostream>
using namespace std;

class Node{
  public :
  int data;
  Node* next;
  Node(int val){
    data = val;
    next = nullptr;
  }
};

class LinkedList{
  Node* head = nullptr;
  public :
  void createLL(){\
    int n;
    cout<<"Enter number of nodes :";
    cin>>n;
    if(n<=0){
      cout<<"Linked List cant be created "<<endl;
      return;
    }
    cout<<"Enter value at node : ";
    int x;
    cin>>x;
    head = new Node(x);
    Node* temp = head;
    for(int i=2; i<=n; i++){
      cout<<"Enter value at node : ";
      cin>>x;
      temp->next = new  Node(x);
      temp = temp->next;
    }
  }

  void display(){
    if(head == nullptr){
      cout<<"Linked List is empty"<<endl;
      return;
    }
    Node* temp = head;
    while(temp){
      cout<<temp->data<<" ";
      temp = temp->next;
    }
    cout<<endl;
  }

  void deleteKey(){
    int key, cnt = 0;
    cout<<"Entr the key you wanna delete : ";
    cin>>key;
    if(head == nullptr){
      return;
    }
    while(head && head->data == key){
      Node* todelete = head;
      head = head->next;
      cnt++;
      delete todelete;
    }
    Node* temp = head;
    while(temp && temp->next){
      if(temp->next->data == key){
        Node* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
        cnt++;
      }
      temp = temp->next;
    }
    cout<<"Number of occurences of that key were "<<cnt<<endl;
  }
};

int main(){

  LinkedList l;
  l.createLL();
  l.display();
  l.deleteKey();
  l.display();

  return 0;
}