////Write a program to implement a stack using (a) One queue

#include<iostream>
#include<queue>
using namespace std;

class myStack{
  private :
  queue<int> q; 
  public : 
  void push(int val){
    int size = q.size();
    q.push(val);
    while(size--){
      q.push(q.front());
      q.pop();
    }
  }
  void pop(){
    if(q.size() == 0){
      cout<<"Stack is empty"<<endl;
      return;
    }
    cout<<"Poped value is "<<q.front()<<endl;
    q.pop();
  }
  void top(){
    if(q.empty()){
      cout<<"Stack is empty!"<<endl;
      return;
    }
    cout<<"Stack top is "<<q.front()<<endl;
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