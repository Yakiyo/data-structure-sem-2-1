#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

vector<int> map;
int sizem = 0;
int tableSize;
int prob;

int f(int i, int x) {
    if (prob == 1) {
        return i;
    }
    if (prob == 2) {
        return i * i;
    }

    return i * (7 - (x % 7));
}

int hashf(int x, int i = 0) {
    int index = (x + f(i, x)) % tableSize;

    if (map.at(index) != 0) {
        cout << "Collision: Index-" << index << endl;

        if (i > 5) {
            cout << "Input abandoned" << endl;
            return -1;
        }

        return hashf(x, i + 1);
    }
    cout << "Inserted : Index-" << index;
    
    float lf = (float) (sizem + 1) / (float) tableSize;
    
    cout << " (L.F=" << lf << ")" << endl;
    return index;
}

int main() {
    int c, N, Q;
    cin >> c >> N >> Q;
    prob = c;
    tableSize = N;

    // cout << std::fixed << setprecision(1);

    map = vector<int>(tableSize, 0);

    for (int i = 0; i < Q; i++) {
        int n;
        cin >> n;
        int idx = hashf(n);
        if (idx == -1) continue;
        map[idx] = n;
        sizem++;
    }

    return 0;
}