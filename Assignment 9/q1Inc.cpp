//increasing order
#include<iostream>
#include<vector>
using namespace std;

void heapify(vector<int> &arr, int n, int i){
  int largest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;
  if(left < n && arr[largest] < arr[left]){
    largest = left;
  }
  if(right < n && arr[largest] < arr[right]){
    largest = right;
  }
  if(largest != i){
    swap(arr[largest], arr[i]);
    heapify(arr, n, largest);
  }
}

void heapSort(vector<int> &arr, int n){
  //create max heap
  for(int i = n/2 - 1; i >= 0; i--){
    heapify(arr,n,i);
  }
  //sorting
  for(int i = n-1; i>=0; i--){
    swap(arr[i], arr[0]);
    heapify(arr, i, 0);
  }
}

int main(){
  int n;
  cout<<"Enter number of elements : ";
  cin>>n;
  vector<int> arr(n);
  cout<<"Enter elements : "<<endl;
  for(int i=0; i<n; i++){
    cin>>arr[i];
  }
  cout<<"Initial array : "<<endl;
  for(int i=0; i<n; i++){
    cout<<arr[i]<<" ";
  }
  cout<<endl;

  heapSort(arr,n);
  
  cout<<"Array after sorting : "<<endl;
  for(int i=0; i<n; i++){
    cout<<arr[i]<<" ";
  }
  cout<<endl;
  return 0;
}