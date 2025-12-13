#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void max_heapify(vector<int>& arr, int i, int size) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left <= size && arr[left] > arr[largest]) {
        largest = left;
    } 
    
    if (right <= size && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        int tmp = arr[largest];
        arr[largest] = arr[i];
        arr[i] = tmp;
        max_heapify(arr, largest, size);
    }
}

void build_max_heap(vector<int>& arr) {
    int len = arr.size();

    int start = len / 2 - 1;

    for (int i = start; i >= 0; i--) {
        max_heapify(arr, i, arr.size());
    }
}

void print_vec(vector<int>& arr) {
    for (int i: arr) {
        cout << i << " ";
    }
    cout << endl;
}

void heap_sort(vector<int>& arr) {
    for (int i = arr.size() - 1; i >= 0;) {
        // swap arr[0] and arr[i]
        swap(arr[0], arr[i]);
        i--;
        max_heapify(arr, 0, i);
    }
    
}

int main() {
    vector<int> arr;

    int n;
    while (true) {
        cin >> n;
        if (n == -1) break;

        arr.push_back(n);
    }

    build_max_heap(arr);
    print_vec(arr);
    cout << endl;

    heap_sort(arr);
    reverse(arr.begin(), arr.end());
    // max_heapify(arr, 0);
    print_vec(arr);
}