#include <iostream>
#include <queue>
using namespace std;

vector<vector<int>> adjList;
vector<vector<int>> edges;

void BFS(int vertices, int root, vector<int> &dist, vector<int> &predecessor){

    vector<int> col(vertices,0); // 1 white, 2 gray, 3 black

    for(int i=0;i<vertices;i++){
        if(i==root-1){
            col[i]=2;
            dist[i]=0;
            predecessor[i]=-1;
            continue;
        }
        
            col[i]=1;
            dist[i]=-1;
            predecessor[i]=-1;
        
    }

    queue<int> Q;
    Q.push(root);

    while(!Q.empty()){

        int u = Q.front()-1;
        Q.pop();

        for(int j=0;j<adjList[u].size();j++){

            if(col[adjList[u][j]-1]==1){

                col[adjList[u][j]-1]=2;
                dist[adjList[u][j]-1]=dist[u]+1;
                predecessor[adjList[u][j]-1]=u+1;

                Q.push(adjList[u][j]);
                edges[u].push_back(adjList[u][j]);
            }
        }

        col[u]=3;
    }
}


int main(){


    int n,m;
    cin>>n>>m;
    
    vector<vector<int>> grid(n,vector<int>(m));

    string s;

    for(int i=0;i<n;i++){
        cin >> s;
    
        for(int j=0;j<m;j++){
            grid[i][j] = s[j] - '0';
        }
    }

    int vertices = n*m;
    adjList.resize(vertices);
    edges.resize(vertices);

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){

            if(grid[i][j]==1){

                int u = i*m + j + 1;

                if(i>0 && grid[i-1][j]==1){
                    adjList[u-1].push_back((i-1)*m+j+1);
                }
                if(i<n-1 && grid[i+1][j]==1){
                    adjList[u-1].push_back((i+1)*m+j+1);
                }
                if(j>0 && grid[i][j-1]==1){
                    adjList[u-1].push_back(i*m+j);
                }
                if(j<m-1 && grid[i][j+1]==1){
                    adjList[u-1].push_back(i*m+j+2);
                }
            }
        }
    }

    vector<int> dist(vertices);
    vector<int> pred(vertices);
    vector<int> visited(vertices,0);

    int islands = 0;

    for(int i=0;i<vertices;i++){

        int r = i/m;
        int c = i%m;

        if(grid[r][c]==1 && visited[i]==0){

            BFS(vertices,i+1,dist,pred);

            for(int j=0;j<vertices;j++){
                if(dist[j]!=-1)
                    visited[j]=1;
            }

            islands++;
        }
    }

 
    cout<<islands<<endl;
    return 0;

}