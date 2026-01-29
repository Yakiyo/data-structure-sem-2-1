#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

typedef struct Node{
    int data;
    struct Node* left;
    struct Node* right;
    struct Node* parent;
    int height;
}Node;

string printNode(Node* x){
    if(x == NULL) return "null";
    else return to_string(x->data);
}

class BST{

    Node* tree_root;

    Node* createNode(int data){
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = data;
        newNode->left = NULL;
        newNode->right = NULL;
        newNode->parent = NULL;
        newNode->height = 0;

        return newNode;
    }

    public:

    Node* getRoot() const{
        return tree_root;
    }

    BST():tree_root(NULL){}

    int update_height(Node* x){
        int leftHeight = (x->left != NULL) ? x->left->height : -1;
        int rightHeight = (x->right != NULL) ? x->right->height : -1;
        return max(leftHeight, rightHeight) + 1;
    }

    void Insert(int key){
        Node* newNode = createNode(key);
        Node* temp = tree_root;

        if(temp == NULL){
            tree_root = newNode;
            return;
        }

        Node* target = temp;
        while(temp != NULL){
            target = temp;
            if(newNode->data < temp->data) temp = temp->left;
            else temp = temp->right;
        }

        newNode->parent = target;
        if(newNode->data < target->data) target->left = newNode;
        else target->right = newNode;

        while (target != NULL)
        {
            target->height = update_height(target);
            target = target->parent;
        }
        
    }

    void print_tree_wo_base(Node* x, int base_value){
        if(x == NULL) return;

        print_tree_wo_base(x->left, base_value);
        if(x->data != base_value) cout << x->data << ' ';
        print_tree_wo_base(x->right, base_value);
    }

    Node* search(int key){
        Node* x = tree_root;
        while(x!=NULL and x->data!=key){
            if(x->data < key) x = x->right;
            else x = x->left;
        }

        return x;
    }

    void anc_descPrint(Node* x){
        if(x->parent == NULL) cout << "NULL";
        else{
            Node* xp = x->parent;
            while(xp != NULL){
                cout << xp->data << ' ';
                xp = xp->parent;
            }
        }
        cout << endl;

        if(x->left == NULL and x->right==NULL) cout << "NULL";
        else{
            print_tree_wo_base(x, x->data);
        }

        cout << endl;
    }
};

int height(Node* x){
    if(x == NULL) return -1;
    return x->height;
}

int main(){
    int input_1, input_2;
    BST tree;

    while(cin >> input_1 and input_1!=-1){
        tree.Insert(input_1);
    }

    while(cin >> input_2 and input_2 != -1){
        Node* temp = tree.search(input_2);
        tree.anc_descPrint(temp);
    }
}