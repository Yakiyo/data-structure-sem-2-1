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


    void k_smallest(Node* x, int &k, int &traversed){
        if(x == NULL) return;
        k_smallest(x->left, k, traversed);
        traversed++;
        if(traversed == k){
            cout << x->data << endl;
            return;
        }
        k_smallest(x->right, k , traversed);
    }

    Node* search(Node* x, int key){
        while(x!=NULL and x->data!=key){
            if(x->data < key) x = x->right;
            else x = x->left;
        }

        return x;
    }
};


int main(){
    int input_1, input_2;
    BST tree;
    cin >> input_1;
    int tree_size = input_1;

    while(input_1--){
        cin >> input_2;
        tree.Insert(input_2);
    }

    cin >> input_1;
    while(input_1--){
        int traversed = 0;
        
        cin >> input_2;
        if(input_2>tree_size){
            cout << "Invalid" << endl;
            continue;
        }
        tree.k_smallest(tree.getRoot(), input_2, traversed);
    }

}