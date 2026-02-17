#include <iostream>

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

int main() {
    int n;
    cin >> n;
    int arr[n];
    // initialize the list
    for (int i = 0; i < n; i++) {
        arr[i] = i;
    }

    int q;
    // consume first 1
    cin >> q;

    while (cin >> q) {
        if (q == 2) {
            int i;
            cin >> i;
            cout << find(arr, i) << endl;
            continue;
        }

        if (q == 3) {
            int i, j;
            cin >> i >> j;
            unionSet(arr, i, j);
            display(arr, n);
            continue;
        }

        break;
    }

    return 0;
}