#include <iostream>

using namespace std;

class Node {
   public:
    int data;
    int height;
    Node* left;
    Node* right;
    Node* parent;

    Node(int val) : data(val), left(nullptr), right(nullptr), parent(nullptr), height(0) {}

    void print() {
        cout << "Data: " << data << ", Height: " << height << ", Parent: ";
        if (parent) {
            cout << parent->data;
        } else {
            cout << "None";
        }
        cout << endl;
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
        // traverse ancestors and update heights as necessary
        while (!parent) {
            parent->height = max(safe_height(parent->left), safe_height(parent->right)) + 1;
            parent = parent->parent;
        }
    }

    int safe_height(Node* node) {
        if (!node) return -1;
        return node->height;
    }

    int calcNodeHeight(Node* node) {
        if (!node) return -1;
        return 1 + max(calcNodeHeight(node->left), calcNodeHeight(node->right));
    }

    void print_tree() {
        _inorderRecursive(root);
        cout << endl;
    }

    void _inorderRecursive(Node* node) {
        if (!node) return;

        _inorderRecursive(node->left);

        cout << node->data << " ";

        _inorderRecursive(node->right);
    }

    void search(int key) {
        Node* result = searchKey(key);
        if (!result) {
            cout << "Key " << key << " not found in the tree." << endl;
        } else {
            result->print();
        }
    }

    void height(int key) {
        Node* result = searchKey(key);
        if (!result) {
            cout << "Key " << key << " not found in the tree." << endl;
        } else {
            cout << "Height of node with key " << key << " is: " << result->height << endl;
        }
    }

    Node* searchKey(int key) {
        Node* current = root;
        while (current) {
            if (current->data == key) {
                current->print();
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

    void before_after(int key) {
        Node* current = searchKey(key);
        if (!current) {
            cout << "Key " << key << " not found in the tree." << endl;
            return;
        }

        Node* before = nullptr;
        Node* after = nullptr;

        Node* parent = current->parent;
        if (current->left) {
            // find max of left sub tree
            before = current->left;
            while (before->right) {
                before = before->right;
            }
        } else {
            if (parent && parent->right == current) {
                before = parent;
            }
        }

        if (current->right) {
            // find min of right sub tree
            after = current->right;
            while (after->left) {
                after = after->left;
            }
        } else {
            if (parent && parent->left == current) {
                after = parent;
            }
        }
        // if (parent) {
        //     if (parent->left == current) {
        //         before = current->left;
        //         after = parent;
        //     } else {
        //         after = current->right;
        //         before = parent;
        //     }
        // } else {
        //     before = current->left;
        //     after = current->right;
        // }

        if (before) {
            cout << "Before " << before->data << " ";
        }
        if (after) {
            cout << "After " << after->data << endl;
        }
    }

    void max_min(Node* node) {
        if (!node) return;
        Node* min = node->left;
        ;
        Node* max = node->right;
        while (min && min->left) {
            min = min->left;
        }
        while (max && max->right) {
            max = max->right;
        }
        if (min) {
            cout << "Minimum value in the tree: " << min->data << endl;
        } else {
            cout << "Tree has no left subtree, hence no minimum value." << endl;
        }
        if (max) {
            cout << "Maximum value in the tree: " << max->data << endl;
        } else {
            cout << "Tree has no right subtree, hence no maximum value." << endl;
        }
    }
};

int main() {
    int n;
    int inp;
    BST tree;
    while (true) {
        cin >> n;
        if (n == -1) break;

        switch (n) {
            case 1:
                cin >> inp;
                tree.insert(inp);
                break;
            case 2:
                tree.print_tree();
                break;
            case 3:
                cin >> inp;
                tree.search(inp);
                break;
            case 4:
                cin >> inp;
                tree.height(inp);
                break;
            case 5:
                cin >> inp;
                tree.before_after(inp);
                break;
            case 6:
                cin >> inp;
                Node* searchResult = tree.searchKey(inp);
                if (searchResult) {
                    tree.max_min(searchResult);
                }
                break;
            default:
                break;
        }
    }
    return 0;
}