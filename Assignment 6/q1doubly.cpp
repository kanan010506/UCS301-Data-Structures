#include<iostream>
using namespace std;

class Node{
  public :
  int data;
  Node* next;
  Node* prev;
  Node(int val){
    data = val;
    next = nullptr;
    prev = nullptr;
  }
};

class DoublyLL{
  Node* head;
  public :
  DoublyLL(){
    head = nullptr;
  }
  void insertPosition(){
    int pos, val;
    cout<<"Enter a position : ";
    cin>>pos;
    cout<<"Enter a value : ";
    cin>>val;
    Node* newNode = new Node(val);
    if(pos == 1){
      newNode->next = head;
      if(head) head->prev = newNode;
      head = newNode;
      return;
    }
    Node* curr = head;
    int cnt = 1 ;
    while(curr && cnt < pos - 1){
      curr = curr->next;
      cnt++;
    }
    if(curr == nullptr){
      cout<<"Invalid position! "<<endl;
      return;
    }
    //end pos 
    else if(curr->next == nullptr){
      curr->next = newNode;
      newNode->prev = curr;
    }
    //middle pos
    else{
      Node* forward = curr->next;
      curr->next = newNode;
      newNode->prev = curr;
      newNode->next = forward;
      forward->prev = newNode;
    }
  }
  void insertAfter(){
    int node, val;
    cout<<"Enter a node value after which you wanna insert  : ";
    cin>>node;
    cout<<"Enter a value : ";
    cin>>val;
    Node* newNode = new Node(val);
    Node* curr = head;
    while(curr){
      if(curr->data == node){
        break;
      }
      curr = curr->next;
    }
    if(curr == nullptr){
      cout<<node<<" doesnot exists "<<endl;
      return;
    }
    if(curr->next == nullptr){
      curr->next = newNode;
      newNode->prev = curr;
    }
    else{
      Node* forward = curr->next;
      curr->next = newNode;
      newNode->prev = curr;
      newNode->next = forward;
      forward->prev = newNode;
    }
  }
  void insertBefore(){
    int node, val;
    cout<<"Enter a node value before which you wanna insert  : ";
    cin>>node;
    cout<<"Enter a value : ";
    cin>>val;
    Node* newNode = new Node(val);
    Node* curr = head;
    while(curr){
      if(curr->data == node){
        break;
      }
      curr = curr->next;
    }
    if(curr == nullptr){
      cout<<node<<" doesnot exists "<<endl;
      return;
    }
    if(curr->prev == nullptr){
      curr->prev = newNode;
      newNode->next = curr;
      head = newNode;
    }
    else{
      Node* back = curr->prev;
      back->next = newNode;
      newNode->prev = back;
      newNode->next = curr;
      curr->prev = newNode;
    }
  }
  void deleteNode(){
    if(head == nullptr){
      cout<<"List is empty cannot delete"<<endl;
      return;
    }
    cout<<"enter a value you wanna delete : ";
    int val;
    cin>>val;
    Node* curr = head;
    while(curr){
      if(curr->data == val){
        break;
      }
      curr = curr->next;
    }
    if(curr == nullptr){
      cout<<"Node doesn't exists"<<endl;
      return;
    }
    //head 
    if(head->data == val){
      curr = head;
      head = head->next;
      cout<<curr->data<<" has been successfully deleted"<<endl;
      delete curr;
      if(head){
        head->prev = nullptr;
      }
    }
    //end
    else if(curr->next == nullptr){
      Node* back = curr->prev;
      cout<<curr->data<<" has been successfully deleted"<<endl;
      delete curr;
      back->next = nullptr;
    }
    //middle
    else{
      Node* forward = curr->next;
      Node* backward = curr->prev;
      cout<<curr->data<<" has been successfully deleted"<<endl;
      delete curr;
      forward->prev = backward;
      backward->next = forward;
    }
  }
  void search(){
    int val;
    bool flag = false;
    cout<<"Enter a value you wanna search : ";
    cin>>val;
    Node* curr = head;
    while(curr){
      if(curr->data == val){
        flag =  true;
        break;
      }
      curr = curr->next;
    }
    if(flag){
      cout<<"Value exists "<<endl;
    }
    else{
      cout<<"Value don't exists "<<endl;
    }
  }
};

int main(){
  DoublyLL list;
  int choice;
  do{
    cout<<"---Menu---"<<endl;
    cout<<"1. Insert at a specific position."<<endl;
    cout<<"2. Insert after specific node."<<endl;
    cout<<"3. Insert before specific node."<<endl;
    cout<<"4. Delete a specific node."<<endl;
    cout<<"5. Search for a node."<<endl;
    cout<<"6. Exit"<<endl;
    cout<<"Enter choice : ";
    cin>>choice;
    switch(choice){
      case 1: list.insertPosition();
      break;
      case 2: list.insertAfter();
      break;
      case 3: list.insertBefore();
      break;
      case 4: list.deleteNode();
      break;
      case 5: list.search();
      break;
      case 6: cout<<"Exiting the programme "<<endl;
      break;
      default : cout<<"Re enter choice "<<endl;
    }
  }
  while(choice != 6);

  return 0;
}