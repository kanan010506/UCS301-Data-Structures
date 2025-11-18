//1. Program: Graph representation (Adjacency Matrix/List) + Basic operations

#include<iostream>
#include<vector>
using namespace std;

class Graph{
  vector<vector<int>> adjmat;
  vector<vector<int>> adjlist;
  vector<int> indegree;
  vector<int> outdegree;
  int n;
public:
  Graph(){
    cout << "Enter number of nodes: ";
    cin >> n;
    adjmat.resize(n, vector<int>(n, 0));
    adjlist.resize(n);
    indegree.resize(n, 0);
    outdegree.resize(n, 0);
  }
  void addEdge(){
    int u, v;
    cout << "Enter edge (u v): ";
    cin >> u >> v;
    if(u < 0 || v < 0 || u >= n || v >= n){
      cout << "Invalid nodes!\n";
      return;
    }
    // Avoid duplicate entries in matrix
    if(adjmat[u][v] == 0){
      adjmat[u][v] = 1;
      adjlist[u].push_back(v);
      outdegree[u]++;
      indegree[v]++;
    }
  }
  void printAdjMatrix(){
    cout << "\nAdjacency Matrix:\n";
    for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
        cout << adjmat[i][j] << " ";
      }
      cout << endl;
    }
  }

  void printAdjList(){
    cout << "\nAdjacency List:\n";
    for(int i = 0; i < n; i++){
      cout << i << " -> ";
      for(auto v : adjlist[i]){
        cout << v << " ";
      }
      cout << endl;
    }
  }
  void printDegrees(){
    int v;
    cout<<"Enter vertex : ";
    cin>>v;
    if(v < 0 || v >= n){
      cout << "Invalid vertex!\n";
      return;
    }
    cout << "In-degree of " << v << " = " << indegree[v] << endl;
    cout << "Out-degree of " << v << " = " << outdegree[v] << endl;
  }

  void printAdjacent(){
    int v;
    cout<<"Enter vertex : ";
    cin>>v;
    if(v < 0 || v >= n){
      cout << "Invalid vertex!\n";
      return;
    }
    cout << "Adjacent vertices of " << v << ": ";
    for(auto x : adjlist[v]){
      cout << x << " ";
    }
    cout << endl;
  }
};

int main(){
  Graph g;
    
  int choice;
  do{
    cout << "\n--- MENU ---\n";
    cout << "1. Add Edge\n";
    cout << "2. Print Adjacency Matrix\n";
    cout << "3. Print Adjacency List\n";
    cout << "4. Degree of a Vertex\n";
    cout << "5. Adjacent Vertices\n";
    cout << "6. Exit\n";
    cout << "Enter choice: ";
    cin >> choice;
    switch(choice){
      case 1 : g.addEdge();
      break;
      case 2 : g.printAdjMatrix();
      break;
      case 3 : g.printAdjList();
      break;
      case 4 : g.printDegrees();
      break;
      case 5 : g.printAdjacent();
      break;
      case 6 : cout<<"Exiting programme ";
      break;
      default : 
    }
  }while(choice != 6);

    return 0;
}
