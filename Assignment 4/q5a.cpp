//Write a program to implement a stack using (a) Two queues 

#include<iostream>
#include<queue>
using namespace std;

class myStack{
  private :
  queue<int> q1,q2;
  void swapQ(){
    queue<int> temp = q1;
    q1 = q2;
    q2 = temp;
  } 
  public : 
  void push(int val){
    q2.push(val);
    while(!q1.empty()){
      q2.push(q1.front());
      q1.pop();
    }
    swapQ();
  }
  void pop(){
    if(q1.empty()){
      cout<<"Stack is empty!";
      return;
    }
    cout<<"Poping out value is "<<q1.front()<<endl;
    q1.pop();
  }
  void top(){
    if(q1.empty()){
      cout<<"Stack is empty!"<<endl;
      return;
    }
    cout<<"Stack top is "<<q1.front()<<endl;
  }
};

int main(){
  myStack st;
  int choice;
  do{
    cout<<"Menu "<<endl;
    cout<<"1. Push() "<<endl;
    cout<<"2. Pop()"<<endl;
    cout<<"3. Top()"<<endl;
    cout<<"4. Exit "<<endl;
    cout<<"Enter choice : ";
    cin>>choice;
    switch(choice){
      case 1 : cout<<"Enter value to push ";
      int val;
      cin>>val;
      st.push(val);
      break;
      case 2 : st.pop();
      break;
      case 3 : st.top();
      break;
      case 4 : cout<<"Exiting the code ";
      break;
      default: cout<<"Re Enter choice \n";
    }
  }
  while(choice != 4);

  return 0;
}