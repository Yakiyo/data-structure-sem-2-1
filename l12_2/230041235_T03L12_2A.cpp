#include <math.h>

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

// gcd sparse table
class SparseTable {
   private:
    vector<vector<int>> st;

   public:
    SparseTable(const vector<int>& arr) {
        int n = arr.size();
        st.assign(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            st[i][0] = arr[i];
        }

        for (int j = 1; (1 << j) <= n; j++) {
            for (int i = 0; i + (1 << j) - 1 < n; i++) {
                st[i][j] = __gcd(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
            }
        }
    }

    void ranges() {
        cout << "Ranges covered by the sparse table:" << endl;
        int n = st.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; i + (1 << j) - 1 < n; j++) {
                cout << "(" << i << ", " << i + (1 << j) - 1 << ") ";
            }
            cout << endl;
        }
    }

    void display() const {
        cout << "Sparse Table:" << endl;
        for (auto vec : st) {
            for (auto val : vec) {
                if (!val) continue;
                cout << left << setw(3) << val << " ";
            }
            cout << endl;
        }
    }

    int query(int l, int r) {
        int w = r - l + 1;
        int j = log2(w);
        return __gcd(st[l][j], st[r - (1 << j) + 1][j]);
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

    vector<pair<int, int>> queries;

    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        queries.emplace_back(l, r);
    }

    SparseTable st(arr);
    st.ranges();

    st.display();

    for (auto query : queries) {
        int l = query.first;
        int r = query.second;
        cout << "GCD of range (" << l << ", " << r << ") is: " << st.query(l, r) << endl;
    }
    return 0;
}