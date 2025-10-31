// Write a program to check if a doubly linked list of characters is palindrome or not.

#include<iostream>
using namespace std;

class Node{
  public :
  char data;
  Node* next;
  Node* prev;
  Node(char val){
    data = val;
    next = nullptr;
    prev = nullptr;
  }
};

class DoublyLL{
  Node* head;
  public :
  DoublyLL(){
    int n;
    cout<<"enter number of nodes : ";
    cin>>n;
    cout<<"Enter node values : ";
    char x;
    cin>>x;
    head = new Node(x);
    Node* prev;
    Node* temp = head;
    for(int i=2; i<=n; i++){
      cin>>x;
      temp->next = new Node(x);
      prev = temp;
      temp = temp->next;
      temp->prev = prev;
    }
  }

  bool checkPalindrome(){
    Node* start = head;
    Node* end = head;
    while(end->next != nullptr){
      end = end->next;
    }
    while(start != end  && start->prev != end){
      if(start->data != end->data){
        return false;
      }
      start = start->next;
      end = end->prev;
    }
    return true;
  }
};

int main(){
  DoublyLL list;
  if(list.checkPalindrome()){
    cout<<"It is a palindrome "<<endl;
  }
  else{
    cout<<"It is not a palindrome"<<endl;
  }
  return 0;
}