#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

const int MAXN = 100005;
const int MAXLOG = 20; // ceil(log2(MAXN))

int st[MAXN][MAXLOG + 1];
int log_table[MAXN];

// Preprocessing (Build the Sparse Table)
void build_sparse_table(int n, const vector<int>& arr) {
    // Precompute logarithms for fast lookups
    log_table[1] = 0;
    for (int i = 2; i <= n; i++) {
        log_table[i] = log_table[i / 2] + 1;
    }

    // Initialize for ranges of length 2^0 = 1
    for (int i = 0; i < n; i++) {
        st[i][0] = arr[i];
    }

    // Fill the table using dynamic programming
    for (int j = 1; j <= MAXLOG; j++) {
        for (int i = 0; i + (1 << j) <= n; i++) {
            st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }
}

// Query (Find minimum in range [l, r])
int query_min(int l, int r) {
    if (l > r) return INT_MAX;
    int k = log_table[r - l + 1]; // Find largest k such that 2^k <= length
    return min(st[l][k], st[r - (1 << k) + 1][k]);
}

// Driver program example
int main() {
    vector<int> arr = {7, 2, 3, 0, 5, 10, 3, 12, 18};
    int n = arr.size();
    build_sparse_table(n, arr);

    // Example queries
    cout << "Minimum in [4, 7]: " << query_min(4, 7) << endl; // Expected: 3
    cout << "Minimum in [0, 8]: " << query_min(0, 8) << endl; // Expected: 0
    
    return 0;
}
