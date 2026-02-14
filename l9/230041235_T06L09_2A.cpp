#include <iostream>
#include <vector>

using namespace std;

class Node {
   public:
    Node* child[2];

    Node() {
        child[0] = nullptr;
        child[1] = nullptr;
    }
};

class Trie {
   public:
    Node* root;

    Trie() {
        root = new Node();
    }

    void insert(int num) {
        Node* curr = root;

        for (int i = 31; i >= 0; i--) {
            // get the i-th bit of num (0 or 1)
            int bit = (num >> i) & 1;

            // insert child if not exists
            if (!curr->child[bit]) {
                curr->child[bit] = new Node();
            }

            curr = curr->child[bit];
        }
    }

    int findMaxXOR(int num) {
        Node* curr = root;
        int maxXOR = 0;

        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            int toggledBit = 1 - bit;

            if (curr->child[toggledBit]) {
                maxXOR = maxXOR | (1 << i);
                curr = curr->child[toggledBit];
                continue;
            }
            
            curr = curr->child[bit];
        }
        return maxXOR;
    }
};

int main() {
    int num;
    Trie t;
    vector<int> nums;
    while (cin >> num) {
        t.insert(num);
        nums.push_back(num);
    }
    int maxXor = 0;
    for (int num : nums) {
        int currXor = t.findMaxXOR(num);
        maxXor = max(maxXor, currXor);
    }

    cout << maxXor << endl;
    return 0;
}