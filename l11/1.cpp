#include <iostream>
#include <vector>
using namespace std;

int find(int arr[], int i) {
    if (arr[i] == i) {
        return i;
    }
    return find(arr, arr[i]);
}

void unionSet(int arr[], int i, int j) {
    int a = find(arr, i);
    int b = find(arr, j);
    arr[b] = a;
}

void display(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void printGroups(int arr[], int n) {
    vector<vector<int>> groups(n);

    for (int i = 0; i < n; i++) {
        int groupId = find(arr, i);
        groups[groupId].push_back(i + 1);  // Store 1-based index
    }
    for (int i = 0; i < n; i++) {
        if (groups[i].empty()) continue;

        cout << "{ ";
        for (int member : groups[i]) {
            cout << member << " ";
        }
        cout << "} ";
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    int arr[n];
    // initialize the list
    for (int i = 0; i < n; i++) {
        arr[i] = i;
    }

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        unionSet(arr, a - 1, b - 1);
        printGroups(arr, n);
        cout << endl;
    }
    return 0;
}