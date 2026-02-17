#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<vector<int>> glist;
vector<int> indeg;

void insert(int u, int v) {
    glist[u].push_back(v);
    glist[v].push_back(u);
    indeg[v]++;
}

vector<int> topo_sort(int vertices) {
    vector<int> Ans;
    queue<int> Que;
    for (int i = 0; i < vertices; i++) {
        if (indeg[i] == 0) {
            Que.push(i);
        }
    }
    if (Que.empty()) {
        cout << "[ ]" << endl;
        return vector<int>(0);
    }

    while (!Que.empty()) {
        int curr = Que.front();
        Que.pop();
        Ans.push_back(curr);

        int temp = glist[curr].size();
        for (int i = 0; i < temp; i++) {
            int ind = glist[curr][i];
            indeg[ind]--;
            if (indeg[ind] == 0) Que.push(ind);
        }
    }

    if (Ans.size() != vertices) {
        cout << "[ ]" << endl;
        return vector<int>(0);
    }
    return Ans;
}

int main() {
    int vertices, edges;
    cin >> vertices >> edges;

    glist.resize(vertices);
    indeg.assign(vertices, 0);

    int a, b;
    for (int i = 0; i < edges; i++) {
        cin >> a >> b;
        insert(a, b);
    }

    vector<int> Ans = topo_sort(vertices);
    if (!Ans.empty()) {
        for (int i = 0; i < vertices; i++) {
            cout << Ans[i] << " ";
        }
        cout << endl;
    }
}