//decreasing order
#include<iostream>
#include<vector>
using namespace std;

void heapify(vector<int> &arr, int n, int i){
  int smallest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;
  if(left < n && arr[smallest] > arr[left]){
    smallest = left;
  }
  if(right < n && arr[smallest] > arr[right]){
    smallest = right;
  }
  if(smallest != i){
    swap(arr[smallest], arr[i]);
    heapify(arr, n, smallest);
  }
}

void heapSort(vector<int> &arr, int n){
  //create min heap
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