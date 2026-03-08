//task 8
#include<iostream>
#include<vector>
using namespace std;

class Graph{
    int V;
    vector<vector<int>> adj;

public:
    Graph(int V) : V(V), adj(V+1) {}

    void addEdge(int u, int v){
        adj[u].push_back(v);
    }

    int dfsRec(int u, vector<bool>&visited, int dest){
        if(u==dest){
            return 1;
        }
        int res=0;
        visited[u] = true;

        for(int v : adj[u]){
            if(!visited[v]){
                res = dfsRec(v,visited, dest);
                if(res ==1) return 1;
            }
        }

        return res;
    }

    void dfs(int startNode, int destNode){
        vector<bool> visited(V+1, false);
        int possible =dfsRec(startNode,visited, destNode);
        if(possible) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
};

int main(){
    int N,M;
    cin>>N>>M;
    Graph g(N);

    while(M--){
        int u,v;
        cin>>u>>v;
        g.addEdge(u,v);
    }
    int src,dst;
    cin>>src>>dst;
    g.dfs(src,dst);
}