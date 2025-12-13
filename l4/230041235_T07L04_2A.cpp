#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Heap {
   private:
    vector<int> arr;
    public:
    Heap() {}
    int size() {
        return arr.size();
    }
    // make clone of input heap
    Heap(const vector<int>& input) {
        for (int val : input) {
            arr.push_back(val);
        }
    }

    void insert(int val) {
        arr.push_back(val);
        int i = arr.size() - 1;
        int parent = (i - 1) / 2;
        while(i > 0 && arr[i] > arr[parent]) {
            swap(arr[i], arr[parent]);
            i = parent;
            parent = (i - 1) / 2;
        }
    }

    int extractMax() {
        if (arr.empty()) {
            return -1;
        }
        int maxVal = arr[0];
        arr[0] = arr.back();
        arr.pop_back();
        return maxVal;
    }

    int getMaxThree() {
        int result = 1;
        Heap copy = Heap(arr);
        if (copy.size() < 3) {
            return -1;
        }
        for (int i = 0; i < 3; i++) {
            result *= copy.extractMax();
        }
        return result;
    }
};

int main() {
    vector<int> input;
    Heap heap = Heap();

    int len;
    cin >> len;
    for (int i = 0; i < len; i++) {
        int val;
        cin >> val;
        heap.insert(val);
        cout << heap.getMaxThree() << endl;
    }
    return 0;
}