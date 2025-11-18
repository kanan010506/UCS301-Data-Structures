//6. Write a program to implement Dijkstra's shortest path algorithm.

#include<iostream>
#include<vector>
using namespace std;

void dijkstra(int n, vector<pair<int, int>> adj[], int src){
  vector<int> dis(n, INT_MAX);
  dis[src] = 0;
  //min heap : {distance, node};
  priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int, int>>> pq;
  pq.push(make_pair(0,src));
  while(!pq.empty()){
    int d = pq.top().first;
    int u = pq.top().second;
    pq.pop();
    if(d > dis[u]){
      continue;
    }
    //check neighbours
    for(int i = 0; i < adj[u].size(); i++){
      int v = adj[u][i].first;
      int w = adj[u][i].second;
      if(dis[u] + w < dis[v]){
        dis[v] = dis[u] + w;
        pq.push(make_pair(dis[v],v));
      }
    }
  }

  cout<<"Shortest distance from source  "<<src<<endl;
  for(int i=0; i<n; i++){
    cout<<"Node : "<<i<<" : "<<dis[i]<<endl;
  }
}

int main(){
  int n, m;
  cout<<"Enter number of nodes : ";
  cin>>n;
  cout<<"Enter number of edges : ";
  cin>>m;
  vector<pair<int, int>> adj[n];
  cout<<"Enter edges (u v weight) : ";
  for(int i=0; i < m; i++){
    int u, v, w;
    cin>>u>>v>>w;
    adj[u].push_back({v,w});
  }
  int src; 
  cout<<"Enter source node :";
  cin>>src;
  dijkstra(n, adj, src);


  return 0;
}