#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class MinHeap {
   private:
    vector<int> arr;

    void buildMinHeap(vector<int>& arr) {
        int len = arr.size();
        int start = len / 2 - 1;

        for (int i = start; i >= 0; i--) {
            minHeapify(arr, i, arr.size() - 1);
        }
    }

    void minHeapify(vector<int>& arr, int i, int size) {
        int min = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;

        if (l <= size && arr[l] < arr[min]) {
            min = l;
        }
        if (r <= size && arr[r] < arr[min]) {
            min = r;
        }

        if (min != i) {
            swap(arr[min], arr[i]);
            minHeapify(arr, min, size);
        }
    }

   public:
    MinHeap(vector<int>& vec) {
        for (int i : vec) {
            arr.push_back(i);
        }
        buildMinHeap(arr);
    }

    void heapSort() {
        for (int i = arr.size() - 1; i >= 0;) {
            swap(arr[0], arr[i]);
            i--;
            minHeapify(arr, 0, i);
        }

        std::reverse(arr.begin(), arr.end());
    }

    // void insert(int val) {
    //     arr.push_back(val);
    //     int index = arr.size() - 1;
    //     int parent = (index - 1) / 2;

    //     while (index > 0 && arr[index] < arr[parent]) {
    //         swap(arr[index], arr[parent]);
    //         index = parent;
    //         parent = (index - 1) / 2;
    //     }
    // }

    void printHeap() {
        for (int i : arr) {
            cout << i << " ";
        }
        cout << endl;
    }
};

int main() {
    vector<int> arr;
    int n;
    while (true) {
        cin >> n;
        if (n == -1) break;

        arr.push_back(n);
    }
    MinHeap mh(arr);
    mh.printHeap();
    mh.heapSort();
    mh.printHeap();
    return 0;
}