#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;

class Node {
    public:
    int data;
    Node* left;
    Node* right;
    Node* parent;
    Node(int val) : data(val), left(nullptr), right(nullptr), parent(nullptr) {}

    int depth() {
        int d = 0;
        Node* current = this;
        while (current->parent) {
            d++;
            current = current->parent;
        }
        return d;
    }
};

class BST {
    public:
    Node* root;
    BST() : root(nullptr) {}

    void insert(int value) {
        Node* newNode = new Node(value);
        if (!root) {
            root = newNode;
            return;
        }
        Node* current = root;
        Node* parent = nullptr;
        while (current) {
            if (value < current->data) {
                parent = current;
                current = current->left;
            } else {
                parent = current;
                current = current->right;
            }
        }
        newNode->parent = parent;
        if (value < parent->data) {
            parent->left = newNode;
        } else {
            parent->right = newNode;
        }
    }

    vector<Node*> pathToRoot(Node* node) {
        vector<Node*> path;
        Node* parent = node->parent;

        while (parent) {
            path.push_back(parent);
            parent = parent->parent;
        }
        reverse(path.begin(), path.end());
        return path;
    }

    Node* searchKey(int key) {
        Node* current = root;
        while (current) {
            if (current->data == key) {
                return current;
            }
            if (key < current->data) {
                current = current->left;
            } else {
                current = current->right;
            }
        }

        return nullptr;
    }

    Node* lca(int k1, int k2) {
        Node* node1 = searchKey(k1);
        Node* node2 = searchKey(k2);

        if (!node1 || !node2) return nullptr;

        vector<Node*> path1 = pathToRoot(node1);
        vector<Node*> path2 = pathToRoot(node2);
        Node* lcaNode = nullptr;
        int len = min(path1.size(), path2.size());
        for (int i = 0; i < len; i++) {
            if (path1[i] == path2[i]) {
                lcaNode = path1[i];
            } else {
                break;
            }
        }
        return lcaNode;
    }
};

int main() {
    // vector<int> inputs = {4, 2, 6, 1, 3, 5, 7};

    int n;
    cin >> n;
    BST tree;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        tree.insert(val);
    }

    cin >> n;

    for (int i = 0; i < n; i++) {
        int k1, k2;
        cin >> k1 >> k2;
        Node* lca = tree.lca(k1, k2);
        if (lca) {
            cout << lca->data << "\n";
        } else {
            cout << "Not Found\n";
        }
    }

    // Node* lca = tree.lca(7, 3);
    // if (lca) {
    //     cout << "LCA is: " << lca->data << endl;
    // } else {
    //     cout << "One or both keys not found in the tree." << endl;
    // }
    return 0;
}