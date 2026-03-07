#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

vector<int> vals;

class SparseTable {
   public:
    vector<vector<int>> st;

    SparseTable(vector<int>& arr) {
        int n = arr.size();
        st.resize(n, vector<int>(log2(n) + 1));
        for (int i = 0; i < n; i++) {
            st[i][0] = arr[i];
        }
        for (int j = 1; j < log2(n) + 1; j++) {
            for (int i = 0; i + (1 << j) - 1 < n; i++) {
                st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
            }
        }
    }

    void display() {
        for (int i = 0; i < st.size(); i++) {
            for (int j = 0; j < st[i].size(); j++) {
                cout << st[i][j] << " ";
            }
            cout << endl;
        }
    }

    int query(int l, int r) {
        int w = r - l + 1;
        int j = log2(w);
        return max(st[l][j], st[r - (1 << j) + 1][j]);
    }
};

int main() {
    int n, q;
    cin >> n;
    cin >> q;
    vals.resize(n);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        vals[i] = x;
    }

    SparseTable st(vals);

    // cout << "Sparse Table:" << endl;
    // st.display();
    // cout << endl;

    vector<pair<int, int>> queries;
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        queries.push_back({l - 1, r - 2});
    }
    int count = 0;

    cout << endl;
    for (auto& query : queries) {
        int mx = st.query(query.first, query.second);
        // cout << "A: " << vals[query.first] << " Max: " << mx;
        if (mx <= vals[query.first]) {
            // cout << " +1";
            count++;
        }
        // cout << endl;
    }

    cout << count << endl;
    return 0;
}