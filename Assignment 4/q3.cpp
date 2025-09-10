//Write a program interleave the first half of the queue with second half.Sample I/P: 4 7 11 20 5 9 Sample O/P: 4 20 7 5 11 9

#include<iostream>
using namespace std;

void display(queue<int> q){
  cout<<"Queue from front to back : "<<endl;
  while(!q.empty()){
    cout<<q.front()<<" ";
    q.pop();
  }
  cout<<endl;
}

int main(){
  queue<int> q;
  int n;
  cout<<"Enter number of elements in queue : ";
  cin>>n;
  cout<<"Enter elements in queue one by one "<<endl;
  int x;
  for(int i=1; i<=n; i++){
    cin>>x;
    q.push(x);
  }
  display(q);
  queue<int> q2;
  for(int i=0; i<n/2; i++){
    q2.push(q.front());;
    q.pop();
  }
  while(!q2.empty()){
    q.push(q2.front());
    q2.pop();
    q.push(q.front());
    q.pop();
  }
  display(q);
  return 0;
}