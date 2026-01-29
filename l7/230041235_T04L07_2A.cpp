#include<iostream>
using namespace std;

typedef struct Node{
    int data;
    struct Node* left;
    struct Node* right;
    struct Node* parent;
    int height;
    int tree_size;
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
        newNode->tree_size = 1;
        return newNode;
    }

    public:

    Node* getRoot() const{
        return tree_root;
    }

    BST():tree_root(NULL){}

    int height(Node* x){
        return (x != NULL) ? x->height : -1; 
    }

    int tsize(Node* x){
        return (x != NULL) ? x->tree_size : 0;
    }

    int update_height(Node* x){
        return max(height(x->left), height(x->right)) + 1;
    }

    int update_size(Node* x){
        return 1 + tsize(x->left) + tsize(x->right);
    }

    int balance_factor(Node* x){
        return height(x->left)-height(x->right);
    }

    void update_ancestor_heights(Node* x){
        Node* temp = x;
        while(temp != NULL){
            temp->height = update_height(temp);
            temp->tree_size = update_size(temp);
            temp = temp->parent;
        }
    }

    void right_rotate(Node* z){
        Node* y = z->left;
        Node* yR = y->right;

        y->parent = z->parent;
        
        if(z==tree_root) tree_root = y;
        else if(z == z->parent->right) z->parent->right = y;
        else z->parent->left = y;

        y->right = z;
        z->parent = y;

        z->left = yR;
        if(yR!=NULL) yR->parent = z;
        
        update_ancestor_heights(z);
    }

    void left_rotate(Node* z){
        Node* y = z->right;
        Node* yL = y->left;

        y->parent = z->parent;
        
        if(z==tree_root) tree_root = y;
        else if(z == z->parent->right) z->parent->right = y;
        else z->parent->left = y;

        y->left = z;
        z->parent = y;

        z->right = yL;
        if(yL!=NULL) yL->parent = z;
        
        update_ancestor_heights(z);
    }

    void balance_node(Node*z){
        int bfactor = balance_factor(z);
        if(bfactor>1){
            if(balance_factor(z->left) >= 0){
                right_rotate(z);
            }
            else {
                left_rotate(z->left);
                right_rotate(z);
            }
        }

        else if(bfactor<-1){
            if(balance_factor(z->right) <= 0){
                left_rotate(z);
            }
            else{
                right_rotate(z->right);
                left_rotate(z);
            }
        }
    }


    void printTree(Node* x){
        if(x == NULL) return;

        printTree(x->left);
        cout << x->data << '(' << tsize(x) << ") ";
        printTree(x->right);
    }

    void Insert(int key){
        Node* newNode = createNode(key);
        Node* temp = tree_root;

        if(temp == NULL){
            tree_root = newNode;
            return;
        }

        Node* target = NULL;
        while(temp != NULL){
            target = temp;
            if(newNode->data < temp->data) temp = temp->left;
            else temp = temp->right;
        }

        newNode->parent = target;
        if(newNode->data < target->data) target->left = newNode;
        else target->right = newNode;

        update_ancestor_heights(target);
        while (target != NULL)
        {   
            int bfactor = balance_factor(target);
            if(bfactor<-1 or bfactor>1){
                balance_node(target);
                printTree(tree_root);
                break;
            }
            else target = target->parent;
        }
    }

    void printSmallCount(int key){
        int count = 0;
        Node* x = tree_root;

        while(x!=NULL){
            if(x->data<key){
                int left = tsize(x->left);
                count+= left+1;
                x = x->right;
            }
            else if(x->data == key){
                count += tsize(x->left);
                x = x->right;
            }
            else x = x->left;
        }

        cout << count << endl;
    }

};

int main(){
    int input;
    BST tree;

    while(cin >> input and input != -1){
        tree.Insert(input);
    }
    
    while(cin >> input and input != -1){
        tree.printSmallCount(input);
    }


}