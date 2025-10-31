//find size of Doubly Linked List.

#include<iostream>
using namespace std;

class Node{
  public :
  int data;
  Node* prev;
  Node* next;
  Node(int val){
    data = val;
    prev = nullptr;
    next = nullptr;
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
    int x;
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
  int sizeCalc(){
    int cnt = 0;
    Node* curr = head;
    while(curr ){
      cnt++;
      curr = curr->next;
    }
    return cnt;
  }
};

int main(){
  DoublyLL list;
  cout<<"Size of Doubly Linked list is "<<list.sizeCalc();
  return 0;
}