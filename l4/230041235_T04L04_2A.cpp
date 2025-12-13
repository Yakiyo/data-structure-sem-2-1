#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Wizard {
   public:
    string name;
    int age;
    string house;

    Wizard(string n, int a, string h) : name(n), age(a), house(h) {}

    bool operator<(const Wizard& other) const {
        return age < other.age;
    }

    bool operator>(const Wizard& other) const {
        return age > other.age;
    }
};

void max_heapify(vector<Wizard>& arr, int i, int size) {
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
        swap(arr[largest], arr[i]);
        max_heapify(arr, largest, size);
    }
}

void build_max_heap(vector<Wizard>& arr) {
    int len = arr.size();

    int start = len / 2 - 1;

    for (int i = start; i >= 0; i--) {
        max_heapify(arr, i, arr.size());
    }
}

void print_vec(vector<Wizard>& arr) {
    for (Wizard i : arr) {
        printWizard(i);
    }
    cout << endl;
}

void heap_sort(vector<Wizard>& arr) {
    for (int i = arr.size() - 1; i >= 0;) {
        // swap arr[0] and arr[i]
        swap(arr[0], arr[i]);
        i--;
        max_heapify(arr, 0, i);
    }
}

class MyHeap {
   private:
    vector<Wizard> arr;

   public:
    MyHeap() {
        // for (Wizard i : vec) {
        //     arr.push_back(i);
        // }
        // build_max_heap(arr);
    }

    Wizard extractMax() {
        Wizard maxWizard = arr[0];
        swap(arr[0], arr[arr.size() - 1]);
        arr.pop_back();
        max_heapify(arr, 0, arr.size() - 1);
        return maxWizard;
    }

    void insert(Wizard w) {
        arr.push_back(w);
        int index = arr.size() - 1;
        int parent = (index - 1) / 2;

        while (index > 0 && arr[index] > arr[parent]) {
            swap(arr[index], arr[parent]);
            index = parent;
            parent = (index - 1) / 2;
        }
    }
};

void printWizard(const Wizard& w) {
    cout << w.name << " " << w.age << " " << w.house << "\n";
}

int main() {
    
    MyHeap wizards = MyHeap();
    char command;

    while(true) {
        cin >> command;
        if (command == 'X') break;

        if (command == 'S') {
            Wizard w = wizards.extractMax();
            printWizard(w);
            continue;
        }

        string name, house;
        int age;
        cin >> name >> age >> house;
        Wizard w(name, age, house);
        wizards.insert(w);
    }
    
    return 0;
}