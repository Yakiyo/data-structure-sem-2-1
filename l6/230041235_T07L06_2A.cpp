#include<iostream>
#include<algorithm>
using namespace std;

typedef struct Node{
    int data;
    struct Node* left;
    struct Node* right;
    struct Node* parent;
    int height;
}Node;

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

    Node* search(int key){
        Node* x = tree_root;
        while(x!=NULL and x->data!=key){
            if(x->data < key) x = x->right;
            else x = x->left;
        }

        return x;
    }

    int longest_path(Node*x){
        int left = (x->left != NULL) ? x->left->height : -1;
        int right = (x->right != NULL) ? x->right->height : -1;
        return left + right + 2;
    }

    void max_dia(Node* x, int &max_value){
        if(x == NULL) return;

        max_dia(x->left, max_value);
        max_dia(x->right, max_value);

        max_value = max(max_value,longest_path(x)+1);
    }

};


int main(){
    int elements, input_1;
    BST tree;

    cin >> elements;
    while(elements--){
        cin >> input_1;
        tree.Insert(input_1);
    }

    int max_dia = -1;
    tree.max_dia(tree.getRoot(), max_dia);
    cout << max_dia << endl;
}