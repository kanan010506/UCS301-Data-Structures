//Display all the node values in a circular linked list, repeating value of head node at the end too. For example, if elements present in the circular linked list starting from head are 20 → 100 → 40 → 80 → 60, then output should be displayed as 20 100 40 80 60 20.

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
class CircularLL{
  public :
  Node* head;
  CircularLL(){
    int n;
    cout<<"Enter number of nodes (greater than zero): ";
    cin>>n;
    cout<<"Enter nodes value one by one : ";
    int x;
    cin>>x;
    head = new Node(x);
    Node* temp = head;
    for(int i=2; i<=n; i++){
      cin>>x;
      temp->next = new Node(x);
      temp = temp->next;
    }
    temp->next = head;
  }
  void travesel(){
    Node* temp = head;
    while(temp->next != head){
      cout<<temp->data<<" ";
      temp = temp->next;
    }
    cout<<temp->data<<" ";
    cout<<head->data;
  }
  
};

int main(){
  CircularLL list;
  list.travesel();
  
  return 0;
}