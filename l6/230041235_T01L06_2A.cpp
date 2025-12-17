#include<iostream>
#include<queue>

using namespace std;

class Node {
    public:
    int data;
    Node* left;
    Node* right;
    Node* parent;

    Node(int val) : data(val), left(nullptr), right(nullptr), parent(nullptr) {}
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
};

// left data right
void inorderTraversal(Node* node) {
    if (!node) return;
    
    inorderTraversal(node->left);
    
    cout << node->data << " ";
    
    inorderTraversal(node->right);
}

void preorderTraversal(Node* node) {
    if (!node) return;

    cout << node->data << " ";
    preorderTraversal(node->left);
    preorderTraversal(node->right);
}

void postorderTraversal(Node* node) {
    if (!node) return;

    postorderTraversal(node->left);
    postorderTraversal(node->right);
    cout << node->data << " ";
}

void levelorderTraversal(Node* root) {
    if (!root) return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* top = q.front();
        q.pop();
        cout << top->data << " ";

        if (top->left != nullptr) {
            q.push(top->left);
        }
        if (top->right != nullptr) {
            q.push(top->right);
        }
    }
}

int main() {
    int n;
    BST tree;
    // tree.insert(100);
    // tree.insert(150);
    // tree.insert(50);
    // tree.insert(125);
    // tree.insert(135);
    // tree.insert(25);
    // tree.insert(40);
    // tree.insert(200);
    cin >> n;

    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        tree.insert(val);
    }

    cout << "Inorder Traversal: ";
    inorderTraversal(tree.root);

    cout << "\nPreorder Traversal: ";
    preorderTraversal(tree.root);

    cout << "\nPostorder Traversal: ";
    postorderTraversal(tree.root);

    cout << "\nLevelorder Traversal: ";
    levelorderTraversal(tree.root);
    return 0;
}