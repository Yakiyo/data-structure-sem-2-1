#include <iostream>

using namespace std;

class Node {
   public:
    int data;
    Node* left;
    Node* right;
    Node* parent;

    int height;

    Node(int val) {
        data = val;
        parent = nullptr;
        left = nullptr;
        right = nullptr;
        height = 0;
    }
};

class BST {
   public:
    Node* root;

    BST() {
        root = nullptr;
    }

    void insert(int val) {
        Node* newNode = new Node(val);

        if (root == nullptr) {
            root = newNode;
            return;
        }

        Node* current = root;
        Node* parent = nullptr;
        while (true) {
            parent = current;
            if (val < current->data) {
                current = current->left;
            } else {
                current = current->right;
            }

            if (current == nullptr) {
                break;
            }
        }

        if (val < parent->data) {
            parent->left = newNode;
        } else {
            parent->right = newNode;
        }
        newNode->parent = parent;

        // go up and update heights
        while (parent != nullptr) {
            updateHeight(parent);
            parent = parent->parent;
        }
    }

    int updateHeight(Node* node) {
        if (node == nullptr) {
            return -1;
        }

        int left = -1;
        int right = -1;

        if (node->left != nullptr) {
            left = node->left->height;
        }

        if (node->right != nullptr) {
            right = node->right->height;
        }

        node->height = max(left, right) + 1;
        return node->height;
    }

    int height(Node* node) const {
        return node ? node->height : -1;
    }

    int balanceFactor(Node* node) const {
        if (node == nullptr) {
            return 0;
        }
        return height(node->left) - height(node->right);
    }

    void inorder(Node* node) const {
        if (node == nullptr) {
            return;
        }
        inorder(node->left);
        cout << node->data << "(" << balanceFactor(node) << ") ";
        inorder(node->right);
    }
};

int main() {
    BST tree;
    while (true) {
        int val;
        cin >> val;
        if (val == -1) {
            break;
        }
        tree.insert(val);
        tree.inorder(tree.root);
        cout << endl;
    }

    return 0;
}