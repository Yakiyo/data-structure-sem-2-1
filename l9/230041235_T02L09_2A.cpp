#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

int main() {
    int n;
    vector<int> nums;

    while (true) {
        cin >> n;
        if (n == -1) break;
        nums.push_back(n);
    }

    int target;
    cin >> target;

    unordered_map<int, int> map;
    vector<pair<int, int>> pairs;

    for (int num: nums) {
        // calculate complement
        int comp = target - num;
        // complement is not present in the map
        // or it was previously inserted and consumed
        if (map.count(comp) == 0 || map[comp] == 0) {
            // if num is not in the map, insert it with 0
            if (!map.count(num)) {
                map.insert(make_pair(num, 0));
            }

            // increment frequency of num by 1
            map[num]++;
            continue;
        }

        // complement is in the map. so reduce its frequency by 1 (consume it once)
        map[comp]--;

        pairs.push_back(make_pair(num, comp));
    }

    if (pairs.empty()) {
        cout << "No pairs found" << endl;
        return 0;
    }

    for (int i = 0; i < pairs.size(); i++) {
        auto p = pairs[i];
        cout << "(" << p.first << ", " << p.second << ")";

        if (i != pairs.size() - 1) {
            cout << ", ";
        }
    }

    return 0;
}