//Implement priority queues using heaps.

#include<iostream>
#include<vector>
using namespace std;

class PriorityQueue{
  vector<int>heap;
  void heapifyUp(int index){
    while(index > 0 && heap[index] > heap[(index-1)/2]){
      swap(heap[index], heap[(index-1)/2]);
      index = (index - 1)/2;
    }
  }
  void heapifyDown(int index){
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int n = heap.size();
    if(left < n && heap[left] > heap[largest]){
      largest = left;
    }
    if(right < n && heap[right] > heap[largest]){
      largest = right;
    }
    if(largest != index){
      swap(heap[index], heap[largest]);
      heapifyDown(largest);
    }
  }
  public :
  void push(int x){
    heap.push_back(x);
    int idx = heap.size() - 1;
    heapifyUp(idx);
  }
  void pop(){
    if(heap.empty()){
      cout<<"Priority Queue is empty!"<<endl;
      return;
    }
    heap[0] = heap.back();
    heap.pop_back();
    heapifyDown(0);
  }
  void top(){
    if(heap.empty()){
      cout<<"Priority Queue is empty !"<<endl;
      return;
    }
    cout<<heap[0];
  }
  bool empty(){
    return heap.empty();
  }
  void display(){
    int n = heap.size();
    for(int i = 0; i<n; i++){
      cout<<heap[i]<<" ";
    }
    cout<<endl;
  }
};


int main(){
  PriorityQueue pq;
  int choice, value;
  while(true){
    cout << "\n----- Priority Queue Menu -----\n";
    cout << "1. Insert\n";
    cout << "2. Delete top (pop)\n";
    cout << "3. Show top element\n";
    cout << "4. Check if empty\n";
    cout << "5. Display priority queue\n";
    cout << "6. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;
    switch(choice){
      case 1:
      cout << "Enter value to insert: ";
      cin >> value;
      pq.push(value);
      break;
      case 2:
      pq.pop();
      break;
      case 3:
      pq.top();
      break;
      case 4:
      if(pq.empty())
        cout << "Priority Queue is empty.\n";
      else
        cout << "Priority Queue is NOT empty.\n";
      break;
      case 5:
      pq.display();
      break;
      case 6:
      cout << "Exiting program..." << endl;
      return 0;
      default:
      cout << "Invalid choice! Try again.\n";
    }
  }
  return 0;
}