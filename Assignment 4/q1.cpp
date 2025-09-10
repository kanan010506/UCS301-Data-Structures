// Develop a menu driven program demonstrating the following operations on simple
//Queues: enqueue(), dequeue(), isEmpty(), isFull(), display(), and peek().

#include<iostream>
using namespace std;

#define MAX 100
int q[MAX];
int front = 0; 
int back = -1;

void enqueue(int val){
  if(back == MAX-1){
    cout<<"Queue is full";
    return;
  }
  back += 1;
  q[back] = val;
}
void dequeue(){
  if(front > back){
    cout<<"Queue is empty";
    front = 0;
    back = -1;
    return;
  }
  cout<<"Element removed was "<<q[front]<<endl;
  if(front == back){
    front = 0;
    back = -1;
  }
  else{
    front += 1;
  }
}
bool isEmpty(){
  if(front > back || back == -1 ){
    return true;
  }
  else{
    return false;
  }
}
bool isFull(){
  if(back == MAX-1){
    return true;
  }
  else{
    return false;
  }
}
void display(){
  if(isEmpty()){
    cout<<"Queue is empty"<<endl;
    return;
  }
  cout<<"Queue from front to back : ";
  for(int i=front ; i<=back; i++){
    cout<<q[i]<<" ";
  }
  cout<<endl;
}
void peek(){
  if(isEmpty()){
    cout<<"Queue is empty";
    return;
  }
  cout<<q[front]<<endl;
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