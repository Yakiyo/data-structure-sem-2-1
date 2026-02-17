#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> adj_list;
vector<vector<int>> adj_matrix;

void insert(int u, int v){
    adj_list[u-1].push_back(v);
    adj_list[v-1].push_back(u);
    adj_matrix[u-1][v-1] = 1;
    adj_matrix[v-1][u-1] = 1;
}

void list_print(int v){
    cout << "Adjacency List:" << endl;
    for(int i=0; i<v; i++){
        cout << i+1 << ": ";
        int size = adj_list[i].size();
        for(int j=0; j<size; j++){
            cout << adj_list[i][j] << " ";
        }
        cout << endl;
    }
}

void mat_print(int v){
    cout << "Adjacency Matrix:" << endl;
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            int temp = (adj_matrix[i][j] == 1) ? 1 : 0;
            cout << temp << " ";
        }
        cout << endl;
    }
}

int main(){
    int vertices, edges;
    cin >> vertices >> edges;

    adj_list.resize(vertices);
    adj_matrix.assign(vertices, vector<int>(vertices, 0));

    int input1, input2;
    for(int i=0; i<edges; i++){
        cin >> input1 >> input2;
        insert(input1, input2);
    }

    list_print(vertices);
    mat_print(vertices);
}