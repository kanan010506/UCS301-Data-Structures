//merge sort

#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int> &arr, int l, int m, int h){
  int n1 = m - l + 1;
  int n2 = h - m;
  vector<int> L(n1), R(n2);
  for(int i=0; i<n1; i++){
    L[i] = arr[l+i];
  }
  for(int i=0; i<n2; i++){
    R[i] = arr[m+1+i];
  }
  int i = 0, j = 0, k = l;
  while(i < n1 && j < n2){
    if(L[i] <= R[j]){
      arr[k] = L[i];
      k++, i++;
    }
    else{
      arr[k] = R[j];
      k++, j++;
    }
  }
  while(i < n1){
    arr[k] = L[i];
    k++, i++;
  }
  while(j < n2){
    arr[k] = R[j];
    k++, j++;
  }
}

void mergeSort(vector<int> &arr, int l , int h){
  if(l < h){
    int m = l + (h - l)/2;
    mergeSort(arr, l, m);
    mergeSort(arr, m+1, h);
    merge(arr,l ,m, h);
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

  mergeSort(arr,0, n-1);
  
  cout<<"Array after sorting : "<<endl;
  for(int i=0; i<n; i++){
    cout<<arr[i]<<" ";
  }
  cout<<endl;
  return 0;
}