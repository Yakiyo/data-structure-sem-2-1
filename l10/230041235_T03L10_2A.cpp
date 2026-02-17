#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> glist;
vector<vector<int>> gmatx;

void insert(int u, int v){
    glist[u-1].push_back(v);
    glist[v-1].push_back(u);
    gmatx[u-1][v-1] = 1;
    gmatx[v-1][u-1] = 1;
}

void display_list(int v){
    cout << "Adjacency List:" << endl;
    for(int i=0; i<v; i++){
        cout << i+1 << ": ";
        int size = glist[i].size();
        for(int j=0; j<size; j++){
            cout << glist[i][j] << " ";
        }
        cout << endl;
    }
}

void display_matx(int v){
    cout << "Adjacency Matrix:" << endl;
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            int temp = (gmatx[i][j] == 1) ? 1 : 0;
            cout << temp << " ";
        }
        cout << endl;
    }
}

int main(){
    int vn, en;
    cin >> vn >> en;

    glist.resize(vn);
    gmatx.assign(vn, vector<int>(vn, 0));

    int input1, input2;
    for(int i=0; i<en; i++){
        cin >> input1 >> input2;
        insert(input1, input2);
    }

    display_list(vn);
    display_matx(vn);
}