//find size of Circular Linked List.

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
    cout<<"Enter number of nodes : ";
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
  int sizeCalc(){
    int cnt = 0;
    Node* temp = head;
    while(temp->next != head){
      cnt++;
      temp = temp->next;
    }
    cnt++;
    return cnt;
  }
};

int main(){
  CircularLL list;
  cout<<"Size of Circular linked list is "<<list.sizeCalc();
  
  return 0;
}