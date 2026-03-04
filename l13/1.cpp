#include <iostream>
#include <vector>
using namespace std;

vector<int> arr;
vector<int> tree;

int left(int i) {
    return 2 * i + 1;
}

int right(int i) {
    return 2 * i + 2;
}

int parent(int i) {
    return (i - 1) / 2;
}

int mid(int l, int r) {
    return (l + r) / 2;
}

void init(int node, int begin, int end) {
    if (begin == end) {
        tree[node] = arr[begin];
        return;
    }

    init(left(node), begin, mid(begin, end));
    init(right(node), mid(begin, end) + 1, end);

    tree[node] = min(tree[left(node)], tree[right(node)]);
    return;
}

int query_min(int node, int b, int e, int i, int j) {
    if (i > e || j < b) return INT_MAX;  // No overlap

    if (b >= i && e <= j) return tree[node];  // Total overlap

    int p1 = query_min(left(node), b, mid(b, e), i, j);
    int p2 = query_min(right(node), mid(b, e) + 1, e, i, j);

    return min(p1, p2);
}

int query(int i, int j) {
    return query_min(0, 0, arr.size() - 1, i, j);
}

int main() {
    int Q, N;
    cin >> N >> Q;

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        arr.push_back(x);
    }

    // arr = {4, -1, 3, 7, 1, 0, 2};
    
    tree.resize(4 * N);  // Allocate enough space for the segment tree
    init(0, 0, N - 1);

    vector<pair<int, int>> queries(Q);
    for (int i = 0; i < Q; i++) {
        int l, r;
        cin >> l >> r;
        queries[i] = {l - 1, r - 1};
    }

    for (const auto& q : queries) {
        int l = q.first;
        int r = q.second;
        cout << query(l, r) << endl;
    }

    return 0;
}