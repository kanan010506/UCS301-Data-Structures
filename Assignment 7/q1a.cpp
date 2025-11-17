//selection sort

#include<iostream>
#include<vector>
using namespace std;

void selectionSort(vector<int> &arr, int n){
  for(int i=0; i<n-1; i++){
    int min = i;
    for(int j = i+1; j<n; j++){
      if(arr[j] < arr[min]){
        min = j;
      }
    }
    if(i!= min){
      swap(arr[i], arr[min]);
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

  selectionSort(arr, n);
  
  cout<<"Array after sorting : "<<endl;
  for(int i=0; i<n; i++){
    cout<<arr[i]<<" ";
  }
  cout<<endl;
  return 0;
}