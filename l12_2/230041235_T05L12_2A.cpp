```C++
//task 5
#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<algorithm>

using namespace std;

class Graph{
    int V;
    vector<vector<int>> adj;
public:
    Graph(int V) : V(V), adj(V) {}

    void addEdge(int u, int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int dfsRec(int u, vector<bool>&visited, int dest, vector<int>&path){
        if(u==dest){
            path.push_back(u);
            return 1;
        }

        visited[u] = true;

        for(int v : adj[u]){
            if(!visited[v]){
                int res = dfsRec(v,visited,dest,path);

                if(res == 1){
                    path.push_back(u);
                    return 1;
                }
            }
        }
        return 0;
    }

    vector<int> dfs(int start, int end, int jump){
        vector<int> ans;
        vector<bool>visited(V, false);
        vector<int>path;
        int possible = dfsRec(start, visited, end, path);
        reverse(path.begin(),path.end());
        if(possible){
            if((path.size()-1)%jump == 0){
                for(int i=0;i<path.size();i++){
                    if(i%jump==0){
                        ans.push_back(path[i]);
                    }
                }
                return ans;
            } else {
                return ans;
            }
        } else{
            return ans;
        }
    }
};

int main(){
    int V, E, Q;
    cin>>V>>E>>Q;
    vector<string> name(V);
    unordered_map<string, int> id;
    Graph g(V);

    for(int i=0;i<V;i++){
        cin>>name[i];
        id[name[i]] = i;
    }

    for(int i=0;i<E;i++){
        string a,b;
        cin>>a>>b;

        int u = id[a];
        int v = id[b];
        g.addEdge(u,v);
    }

    for(int i=0;i<Q;i++){
        int k;
        string a,b;
        cin>>a>>b>>k;

        int u = id[a];
        int v = id[b];
        vector<int> ans = g.dfs(u,v,k);
        if(ans.size()==0){
            cout<<"NO"<<endl;
        } else{
            for(int i=0;i<ans.size();i++){
                cout<<name[ans[i]]<<" ";
            }
            cout<<endl;
        }
    }
}
```