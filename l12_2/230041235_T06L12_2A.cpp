//task 6
#include<iostream>
#include<vector>
using namespace std;

class Graph{
    int V;
    vector<vector<int>> adj;

public:
    Graph(int V) : V(V+1), adj(V) {}

    void addEdge(int u, int v){
        adj[u].push_back(v);
    }

    void dfsRec(int u, vector<bool> &visited){
        visited[u] = true;
        for(int v : adj[u]){
            if(!visited[v]){ 
                dfsRec(v, visited);
            }
        }
    }

    char dfs(int startNode, int m, int n){
        vector<bool> visited(V, false);
        dfsRec(startNode, visited); 

        bool green = false;
        bool red = false;

        for(int i=0;i<m*n;i++){
            if(visited[i]){
                int r = i/n; 
                int c = i%n; 
                
                if(r==0 || c==0) green=true;
                if(r==m-1 || c==n-1) red=true;
            }
        }

        if(green && red) return 'O'; 
        else return 'X';
    }

};

bool valid(int x, int y, int m, int n){
    return x >= 0 && x < m && y >= 0 && y < n;
}



int main(){
    int m, n;
    cin>>m>>n;
    Graph g(m*n);
    vector<vector<int>> v(m, vector<int>(n));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>v[i][j];
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            int curr_node = i*n+j;
            if(valid(i+1,j,m,n) && v[i][j]>= v[i+1][j]){
                int neigh_node = (i+1)*n +j;
                g.addEdge(curr_node,neigh_node);
            }
            if(valid(i-1,j,m,n) && v[i][j]>= v[i-1][j]){
                int neigh_node = (i-1)*n +j;
                g.addEdge(curr_node,neigh_node);
            }
            if(valid(i,j+1,m,n) && v[i][j]>= v[i][j+1]){
                int neigh_node = i*n +(j+1);
                g.addEdge(curr_node,neigh_node);
            }
            if(valid(i,j-1,m,n) && v[i][j]>= v[i][j-1]){
                int neigh_node = i*n +(j-1);
                g.addEdge(curr_node,neigh_node);
            }
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            int startNode = i*n + j;
            cout<<g.dfs(startNode, m,n)<<" ";
        }
        cout<<endl;
    }
}