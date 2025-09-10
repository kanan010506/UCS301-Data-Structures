//Develop a menu driven program demonstrating the following operations on Circular Queues:
//enqueue(), dequeue(), isEmpty(), isFull(), display(), and peek().

#include<iostream>
using namespace std;

#define MAX 100
int q[MAX];
int front = 0; 
int back = -1;
int size = 0;

void enqueue(int val){
  if(size == MAX){
    cout<<"Queue is full"<<endl;
    return;
  }
  back = (back + 1) % MAX;
  q[back] = val;
  size++;
}
void dequeue(){
  if(size == 0){
    cout<<"Queue is empty"<<endl;
    return;
  }
  front = (front + 1) % MAX;
  size--;
  if(size == 0){
    front = 0;
    back = -1;
  }
}
bool isEmpty(){
  if(size==0){
    return true;
  }
  else{
    return false;
  }
}
bool isFull(){
  if(size == MAX){
    return true;
  }
  else{
    return false;
  }
}
void display(){
  if(isEmpty()){
    cout<<"Queue is empty !";
    return;
  }
  cout<<"Queue from front to back :"<<endl;
  for(int i=0; i<size; i++){
    cout<<q[(front + i)% MAX]<<" ";
  }
  cout<<endl;
}
void peek(){
  if(size == 0){
    cout<<"Queue is empty!";
  }
  else{
    cout<<q[front]<<endl;
  }
}
int main(){
  int choice;
  do{
    cout<<".   Menu"<<endl;
    cout<<"1. enqueue()"<<endl;
    cout<<"2. dequeue()"<<endl;
    cout<<"3. isEmpty()"<<endl;
    cout<<"4. isFull()"<<endl;
    cout<<"5. display()"<<endl;
    cout<<"6. peek()"<<endl;
    cout<<"7. exit"<<endl;
    cout<<"Enter choice "<<endl;
    cin>>choice;
    switch(choice){
      case 1 : cout<<"Enter value you wanna push in queue";
      int x;
      cin>>x;
      enqueue(x);
      break;
      case 2 : dequeue();
      break;
      case 3 : if(isEmpty()){
        cout<<"Queue is Empty"<<endl;
      }
      else{
        cout<<"Queue is not empty"<<endl;
      }
      break;
      case 4 : if(isFull()){
        cout<<"Queue is full"<<endl;
      }
      else{
        cout<<"Queue is not full"<<endl;
      }
      break;
      case 5 : display();
      break;
      case 6 : peek();
      break;
      case 7: cout<<"Exiting programme "<<endl;
      break;
      default : cout<<"Renter choice : ";
      break;
    }
  }
  while(choice != 7);

  return 0;
}