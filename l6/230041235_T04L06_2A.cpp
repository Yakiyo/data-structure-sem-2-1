#include<iostream>
#include<stack>
using namespace std;

typedef struct Node{
    int data;
    struct Node* left;
    struct Node* right;
    struct Node* parent;
    int depth;
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
        newNode->depth = 0;

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

        newNode->depth = (newNode->parent ? newNode->parent->depth + 1 : 0);

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

    Node* findLCA(int x, int y){
        Node* first = search(x);
        Node* second = search(y);

        while(first->depth != second->depth){
            if(first->depth<second->depth) second = second->parent;
            else first = first->parent;
        }

        while(first!=second){
            first = first->parent;
            second = second->parent;
        }

        return first;
    }

    void printPath(int x, int y){
        int count = 0;
        Node* LCA = findLCA(x,y);
        Node* first = search(x);
        Node* second = search(y);

        while(first!=LCA){
            cout << first->data << ' ';
            count++;
            first = first->parent;
        }
        cout << LCA->data << ' ';
        count++;

        stack<Node*> temp;
        while(second!=LCA){
            temp.push(second);
            second = second->parent;
        }
        while(!temp.empty()){
            cout << temp.top()->data << ' ';
            count++;
            temp.pop();
        }

        cout << '\n' << count << endl;

    }

    void print_tree(Node* x){
        if(x == NULL) return;

        print_tree(x->left);
        cout << x->data << '(' << x->height << ") ";
        print_tree(x->right);
    }


};


int main(){
    int input_1, input_2;
    BST tree;

    while(cin >> input_1 and input_1!=-1){
        tree.Insert(input_1);
    }
    tree.print_tree(tree.getRoot());
    cout << endl;

    while(cin >> input_2 >> input_1 and (input_2 != -1 or input_1 != -1)){
        tree.printPath(input_2, input_1);
    }
    
}