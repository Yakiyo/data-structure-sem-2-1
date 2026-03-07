#include <iostream>
#include <vector>

using namespace std;

vector<int> vals;
vector<int> pref;

int main() {
    int n, q;
    cin >> n;
    cin >> q;
    vals.resize(n);
    pref.resize(n);
    pref.at(0) = 0;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        vals[i] = x;
        if (!i) {
            pref[i] = vals[i];
            continue;
        }
        pref[i] = pref[i - 1] + vals[i];
    }

    vector<pair<int, int>> queries;

    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        queries.push_back({l - 1, r - 1});
    }

    for (auto query: queries) {
        int l = query.first;
        int r = query.second;
        int w = r - l + 1;
        if (w % 2 != 0 || w == 0) {
            cout << -1 << endl;
            continue;
        }
        int count = pref[r] - (l > 0 ? pref[l - 1] : 0);
        int target = w / 2;
        int flips = abs(count - target);
        cout << flips << endl;
    }

    // for (int i: vals) {
    //     cout << i << " ";
    // }
    // cout << endl;
    // for (int i: pref) {
    //     cout << i << " ";
    // }
    cout << endl;
    return 0;
}