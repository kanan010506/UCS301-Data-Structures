//5. Write a program to implement prim's minimum spanning tree algorithm.

#include<iostream>
using namespace std;

int minKey(vector<int> &key, vector<bool> &mstSet, int n){
  int min = INT_MAX, minIndex = -1;
  for(int i=0; i < n; i++){
    if(!mstSet[i] && key[i] < min){
      min = key[i];
      minIndex = i;
    }
  }
  return minIndex;
}

int spanningTree(int n, vector<vector<int>> &graph){
  vector<bool> mstSet(n, false);
  vector<int> key(n, INT_MAX);
  key[0] = 0;
  int result = 0;
  for(int i = 0; i<n; i++){
    int u = minKey(key, mstSet, n);
    mstSet[u] = true;
    result += key[u];
    for(int v= 0; v < n; v++){
      if(graph[u][v] && !mstSet[v] && graph[u][v] < key[v]){
        key[v] = graph[u][v];
      }
    }
  }
  return result;
}

int main(){
  int n, m;
  cout<<"Enter number of node : ";
  cin>>n;
  cout<<"Enter number of edges : ";
  cin>>m;
  vector<vector<int>> adj(n, vector<int> (n,0));
  cout<<"Enter edges (u v weight)"<<endl;
  for(int i=0; i<m; i++){
    int u, v, w;
    cin>>u>>v>>w;
    adj[u][v] = w;
    adj[v][u] = w;
  }
  int ans = spanningTree(n,adj);
  cout<<ans;
  return 0;
}