#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<vector<int>> adj_list;
vector<int> indeg;


void insert(int u, int v){
    adj_list[u].push_back(v);
    adj_list[v].push_back(u);
    indeg[v]++;
}

vector<int> topo_sort(int vertices){

    vector<int> Ans;
    queue<int> Que;
    for(int i=0; i<vertices; i++){
        if(indeg[i] == 0){ Que.push(i);}
    }
    if(Que.empty()){
        cout << "[ ]" << endl;
        return vector<int> (0);
    }

    while(!Que.empty()){
        int curr;
        curr = Que.front();
        Que.pop();
        Ans.push_back(curr);
        
        int temp = adj_list[curr].size();
        for(int i=0; i<temp; i++){
            int ind = adj_list[curr][i];
            indeg[ind]--;
            if(indeg[ind] == 0) Que.push(ind);
        }

    }

    if(Ans.size() != vertices){
        cout << "[ ]" << endl;
        return vector<int> (0);
    }
    return Ans;
}

int main(){
    int vertices, edges;
    cin >> vertices >> edges;

    adj_list.resize(vertices);
    indeg.assign(vertices, 0);


    int input1, input2;
    for(int i=0; i<edges; i++){
        cin >> input1 >> input2;
        insert(input1, input2);
    }

    vector<int> Ans = topo_sort(vertices);
    if(!Ans.empty()){
        for(int i=0; i<vertices; i++){cout << Ans[i] << " ";}
        cout << endl;
    }
}