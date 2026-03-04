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

    tree[node] = tree[left(node)] + tree[right(node)];
    return;
}

void update(int node, int b, int e, int idx, int val) {
    if (b == e) {
        tree[node] += val;
        return;
    }

    if (idx <= mid(b, e)) {
        update(left(node), b, mid(b, e), idx, val);
    } else {
        update(right(node), mid(b, e) + 1, e, idx, val);
    }

    tree[node] = tree[left(node)] + tree[right(node)];
}

int query_sum(int node, int b, int e, int i, int j) {
    if (i > e || j < b) return 0;  // No overlap

    if (b >= i && e <= j) return tree[node];  // Total overlap

    int p1 = query_sum(left(node), b, mid(b, e), i, j);
    int p2 = query_sum(right(node), mid(b, e) + 1, e, i, j);

    return p1 + p2;
}

int query(int i, int j) {
    return query_sum(0, 0, arr.size() - 1, i, j);
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

    int q, i, j;

    for (int k = 0; k < Q; k++) {
        cin >> q >> i;
        i--; // Convert to 0-based index
        if (q == 1) {
            update(0, 0, N - 1, i, -arr[i]);
            cout << arr[i] << endl;
            arr[i] = 0;
        } else if (q == 2) {
            cin >> j;
            j--;
            update(0, 0, N - 1, i, j);
            for (auto x : arr) cout << x << " ";
            cout << endl;

            arr[i] += j;
        } else {
            cin >> j;
            j--;
            cout << query(i, j) << endl;
        }
    }

    return 0;
}