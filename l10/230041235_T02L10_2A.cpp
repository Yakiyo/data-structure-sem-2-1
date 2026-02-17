#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> parent;
vector<int> setrank;

void init(int size){
    for(int i=0; i<size; i++){
        parent.push_back(i);
        setrank.push_back(0);
    }
}

int find(int u){
    if(parent[u] == u) return u;
    return parent[u] = find(parent[u]);
}

int find(int u, queue<int> &q){
    q.push(u);
    if(parent[u] == u) return u;
    return parent[u] = find(parent[u], q);
}

void setunion(int i, int j){
    int ri = find(i);
    int rj = find(j);

    if(ri != rj){
        if(setrank[ri] <= setrank[rj]) parent[ri] = rj;
        else parent[rj] = ri;

        if(setrank[ri] == setrank[rj]) setrank[rj]++;
    }
}

void printparents(){
    int size = parent.size();
    for(int i=0; i<size; i++){
        cout << parent[i] << "(" << setrank[i] << ") ";
    }
    cout << endl;
}

int main(){
    int elements;
    cin >> elements;

    int input, input1;
    queue<int> q;
    while(cin >> input and input != -1)
    {
        switch (input)
        {
        case 1:
            init(elements);
            printparents();    
            break;
        case 2:
            cin >> input1;
            cout << find(input1, q) << endl;
            while(!q.empty()){
                cout << "f(" << q.front() << ") ";
                q.pop();
            }
            cout << endl;
            break;
        
        case 3:
            cin >> input >> input1;
            setunion(input, input1);
            printparents();
            break;
        
        case 4:
            printparents();
            break;
        default:
            break;
        }
    }
    
}