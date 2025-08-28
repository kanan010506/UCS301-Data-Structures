//1. Develop a menu driven program demonstrating the following operations on a Stack using array:
//(i) push(), (ii) pop(), (iii) isEmpty(), (iv) isFull(), (v) display(), and (vi) peek().

#include<iostream>
using namespace std;

int st[100];
int top  = -1;

void push(int val){
  if(top == 99){
    cout<<"Stack is full!";
    return;
  }
  top +=1 ;
  st[top] = val;
}
void pop(){
  if(top == -1){
    cout<<"Stack is empty.";
    return;
  }
  top -= 1;
}

bool isEmpty(){
  if(top == -1){
    return true;
  }
  else{
    return false;
  }
}

bool isFull(){
  if(top == 99){
    return true;
  }
  else{
    return false;
  }
}

void display(){
  if(top == -1){
    cout<<"Stack is empty";
    return;
  }
  cout<<"Elements from top to bottom : "<<endl;
  for(int i=top; i>=0 ; i--){
    cout<<st[i]<<" ";
  }
  cout<<endl;
}

void peek(){
  if(top == -1){
    cout<<"stack is empty !";
    return;
  }
  cout<<"Top elememnt is "<<st[top]<<endl;
}

int main(){
  int choice;
  do{
    cout<<" Menu "<<endl;
    cout<<"1. push()"<<endl;
    cout<<"2. pop()"<<endl;
    cout<<"3. isEmpty()"<<endl;
    cout<<"4. isFull()"<<endl;
    cout<<"5. display()"<<endl;
    cout<<"6. peek()"<<endl;
    cout<<"7. Exit programme"<<endl;
    cin>>choice;
    switch(choice){
      case 1 : cout<<"Enter value to push ";
      int val;
      cin>>val;
      push(val);
      break;
      case 2 : pop();
      break;
      case 3 : if(isEmpty()){
        cout<<"Stack is empty.";
      }
      else{
        cout<<"Stack is not empty.";
      }
      break;
      case 4 : if(isFull()){
        cout<<"Stack is Full.";
      }
      else{
        cout<<"Stack is not Full.";
      }
      break;
      case 5 : display();
      break;
      case 6 : peek();
      break;
      default : cout<<"Reenter choice ";
    }
  }while(choice != 7);
  return 0;
}
