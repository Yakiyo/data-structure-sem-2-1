#include<iostream>
#include<vector>
using namespace std;

int main() {
    int v, e;
    cin >> v >> e;
    vector<int> gp;
    gp.assign(v, 0);
    
    for (int i = 0; i < e; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        gp[a]++;
        gp[b]++;
    }
    int k = gp.at(0);

    for (int i = 1; i < gp.size(); i++) {
        int j = gp.at(i);
        // cout << i << "(" << j << ") ";
        if (j != k) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES (" << k << "-regular)";
    return 0;
}