//bubble sort

#include<iostream>
using namespace std;

void bubbleSort(vector<int> &arr, int n){
  for(int i=0; i<n-1; i++){
    for(int j=0; j<n-1-i; j++){
      if(arr[j] > arr[j+1]){
        swap(arr[j], arr[j+1]);
      }
    }
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

  bubbleSort(arr, n);
  
  cout<<"Array after sorting : "<<endl;
  for(int i=0; i<n; i++){
    cout<<arr[i]<<" ";
  }
  cout<<endl;
  return 0;
}