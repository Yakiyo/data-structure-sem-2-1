#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

class SparseTable {
   private:
    vector<vector<int>> st;

   public:
    SparseTable(const vector<int>& arr) {
        int n = arr.size();

        st.resize(n, vector<int>(log2(n) + 1));

        for (int i = 0; i < n; i++) {
            st[i][0] = arr[i];
        }

        cout << "2" << endl;
        for (int j = 1; (1 << j) <= n; j++) {
            for (int i = 0; i + (1 << j) - 1 < n; i++) {
                st[i][j] = bor(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
            }
        }
    }

    int query(int l, int r) {
        int w = r - l + 1;
        int j = log2(w);
        return bor(st[l][j], st[r - (1 << j) + 1][j]);
    }

    int bor(int a, int b) {
        return a | b;
    }
};

int main() {
    int n, q;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cin >> q;
    SparseTable st(arr);
    cout << 1 << endl;
    vector<vector<int>> queries(q, vector<int>(3));
    for (int i = 0; i < q; i++) {
        int l, r, x;
        cin >> l >> r >> x;
        queries[i] = {l, r, x};
    }

    for (auto& query : queries) {
        cout << st.query(query[0], query[1]) << " " << arr[query[2]] << endl;
    }
    return 0;
}