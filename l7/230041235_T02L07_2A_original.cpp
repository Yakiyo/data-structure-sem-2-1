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

    void insertNode(Node* node, Node* newNode) {
        if (newNode->data < node->data) {
            if (node->left) {
                insertNode(node->left, newNode);
            } else {
                node->left = newNode;
                newNode->parent = node;
            }
        } else {
            if (node->right) {
                insertNode(node->right, newNode);
            } else {
                node->right = newNode;
                newNode->parent = node;
            }
        }
    }

    void insert(int val) {
        Node* newNode = new Node(val);

        if (root == nullptr) {
            root = newNode;
            return;
        }

        insertNode(root, newNode);

        Node* parent = newNode->parent;
        // go up and update heights
        while (parent != nullptr) {
            updateHeight(parent);
            parent = parent->parent;
        }

        parent = newNode->parent;

        while (parent) {
            int bf = balanceFactor(parent);
            if (bf > 1 || bf < -1) {
                balance(parent, newNode);
                break;
            }
            parent = parent->parent;
        }
    }

    void balance(Node* node, Node* newNode) {
        int bf = balanceFactor(node);
        if (bf < -1 || bf > 1) return;
        // left heavy
        if (bf > 1) {
            Node* y = node->left;

            // LR case
            if (data(newNode) > data(node->left)) {
                // converts it to LL case
                leftRotate(node->left);

                rightRotate(node);
                return;
            }
            // LL case
            if (data(newNode) < data(node->left)) {
                rightRotate(node);
                return;
            }
        } else {
            Node* y = node->right;

            // RL case
            if (data(newNode) < data(node->right)) {
                // converts to RR case
                rightRotate(node->right);

                leftRotate(node);
                return;
            }

            if (data(newNode) > data(node->right)) {
                leftRotate(node);
            }
        }
    }

    int data(Node* node) {
        if (!node) return -1;
        return node->data;
    }

    int updateHeight(Node* node) {
        if (node == nullptr) {
            return -1;
        }

        int left = -1;
        int right = -1;

        if (node->left) {
            left = node->left->height;
        }

        if (node->right) {
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

    void leftRotate(Node* z) {
        Node* y = z->right;
        Node* yl = z->left;

        transplant(z, y);
        y->left = z;
        z->parent = y;

        z->right = yl;
        if (yl) yl->parent = z;
        
        updateHeight(z);
    }

    void rightRotate(Node* z) {
        Node* y = z->left;
        Node* yr = z->right;

        transplant(z, y);

        y->right = z;
        z->parent = y;

        z->left = yr;
        if (yr) yr->parent = z;

        updateHeight(z);
    }

    void transplant(Node* node, Node* child) {
        Node* parent = node->parent;

        if (child) child->parent = parent;

        if (!parent) {
            if (root == node) root = child;
            return;
        }

        // connect to the appropiate arm of parent
        if (parent->right->data == node->data) {
            parent->right == child;
        } else {
            parent->left == child;
        }
    }

    void inorder(Node* node) const {
        if (!node) return;

        inorder(node->left);
        cout << node->data << "(" << balanceFactor(node) << ") ";
        inorder(node->right);
    }

    void printAvl() const {
        inorder(root);
        cout << endl;
    }
};

int main() {
    BST tree;
    // tree.insert(7);
    // tree.insert(10);
    // tree.insert(11);

    // cout << tree.root->data << " " << tree.root->right->data << " " << tree.root->right->right->data << endl;

    // tree.leftRotate(tree.root);
    // cout << tree.root->data << " " << tree.root->left->data << " " << tree.root->right->data << endl;
    int n;

    while (true) {
        cin >> n;
        if (n == -1) break;

        tree.insert(n);

        tree.printAvl();
    }
    return 0; 
}