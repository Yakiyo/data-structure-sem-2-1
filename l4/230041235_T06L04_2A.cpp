#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;


// Max Priority Queue
class MPQueue {
    private:
    vector<int> arr;

    void build_max_heap(vector<int>& arr) {
        int len = arr.size();
        int start = len / 2 - 1;

        for (int i = start; i >= 0; i--) {
            max_heapify(arr, i, arr.size() - 1);
        }
    }

    void max_heapify(vector<int>& arr, int i, int size) {
        int largest = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;

        if (l <= size && arr[l] > arr[largest]) {
            largest = l;
        }
        if (r <= size && arr[r] > arr[largest]) {
            largest = r;
        }

        if (largest != i) {
            swap(arr[largest], arr[i]);
            max_heapify(arr, largest, size);
        }
    }

    void shiftUp(int i) {
        int parent = (i - 1) / 2;
        if (i > 0 && arr[i] > arr[parent]) {
            swap(arr[i], arr[parent]);
            shiftUp(parent);
        }
    }

    void shiftDown(int i) {
        max_heapify(arr, i, arr.size() - 1);
    }

    public:
    MPQueue(vector<int> vec) {
        for (int i : vec) {
            arr.push_back(i);
        }
        build_max_heap(arr);
    }

    int size() {
        return arr.size();
    }

    int maximum() {
        if (arr.size() == 0) {
            return -1;
        }
        return arr[0];
    }

    int extractMax() {
        if (arr.size() == 0) {
            return -1;
        }

        int maxVal = arr[0];
        arr[0] = arr.back();
        arr.pop_back();
        max_heapify(arr, 0, arr.size() - 1);

        return maxVal;
    }

    void insert(int val) {
        arr.push_back(val);
        int index = arr.size() - 1;
        int parent = (index - 1) / 2;

        while (index > 0 && arr[index] > arr[parent]) {
            swap(arr[index], arr[parent]);
            index = parent;
            parent = (index - 1) / 2;
        }
    }

    void increaseKey(int index, int value) {
        if (index < 0 || index >= arr.size() || value < arr[index]) {
            return;
        }

        arr[index] = value;
        shiftUp(index);
    }

    void decreaseKey(int index, int value) {
        if (index < 0 || index >= arr.size() || value > arr[index]) {
            return;
        }

        arr[index] = value;
        shiftDown(index);
    }

    void printQueue() {
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
    MPQueue q(arr);
    while (true) {
        cin >> n;
        if (n == -1) break;

        if (n == 1) {
            cout << q.maximum() << endl;
            q.printQueue();
            continue;
        } 

        if (n == 2) {
            cout << q.extractMax() << endl;
            q.printQueue();
            continue;
        }

        if (n == 3) {
            int val;
            cin >> val;
            q.insert(val);
            q.printQueue();
            continue;
        }

        if (n == 4) {
            int index, value;
            cin >> index >> value;
            q.decreaseKey(index, value);
            q.printQueue();
            continue;
        }

        if (n == 5) {
            int index, value;
            cin >> index >> value;
            q.increaseKey(index, value);
            q.printQueue();
            continue;
        }

    }
    return 0;
}