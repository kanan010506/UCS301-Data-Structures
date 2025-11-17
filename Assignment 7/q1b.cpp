//insertion sort

#include<iostream>
#include<vector>
using namespace std;

void insertionSort(vector<int> &arr, int n){
  for(int i=1; i<n; i++){
    int j = i - 1;
    int key = arr[i];
    while(j >= 0 && arr[j] > key){
      arr[j+1] = arr[j];
      j--;
    }
    arr[j+1]  = key;
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

  insertionSort(arr, n);
  
  cout<<"Array after sorting : "<<endl;
  for(int i=0; i<n; i++){
    cout<<arr[i]<<" ";
  }
  cout<<endl;
  return 0;
}