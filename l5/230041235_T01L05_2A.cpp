#include <iostream>

using namespace std;

class Node {
   public:
    int data;
    Node* next;

    Node(int v) {
        data = v;
        next = NULL;
    }
};

class LinkedList {
   private:
    Node* front;
    Node* back;
    int size;

   public:
    LinkedList() : size(0) {
        front = NULL;
        back = NULL;
    }

    Node* create_node(int v) {
        Node* n = new Node(v);
        return n;
    }

    void insert_front(int v) {
        Node* newFront = create_node(v);
        if (size == 0) {
            front = newFront;
            back = front;
            size++;
            return;
        }

        newFront->next = front;
        front = newFront;
        size++;
    }

    void insert_back(int v) {
        Node* newBack = create_node(v);
        if (size == 0) {
            back = newBack;
            front = back;
            size++;
            return;
        }
        back->next = newBack;
        back = newBack;
        size++;
    }

    void insert_after_node(int v, int n) {
        if (size == 0) {
            cout << "Linked List is empty";
            return;
        }
        Node* curr = front;
        while (curr != NULL && curr->data == n) {
            curr = curr->next;
        }

        if (curr == NULL) {
            cout << "No node found" << endl;
            return;
        }

        Node* left = curr;
        Node* right = curr->next;
        Node* newNode = create_node(v);
        if (curr == back) {
            back = newNode;
        }
        left->next = newNode;
        newNode->next = right;
        size++;
    }

    void update_node(int v, int n) {
        if (size == 0) {
            cout << "Linked List is empty";
            return;
        }
        Node* curr = front;
        while (curr != NULL) {
            if (curr->data == n) {
                break;
            }
            curr = curr->next;
        }

        if (curr == NULL) {
            cout << "Node not found" << endl;
            return;
        }

        curr->data = v;
    }

    void remove_head() {
        if (size == 0) {
            cout << "List is empty";
            return;
        }
        Node* newFront = front->next;
        front = newFront;
        size--;
    }

    void remove_tail() {
        if (size == 0) {
            cout << "List is empty";
            return;
        }

        Node* curr = front;
        while (curr->next != back) {
            curr = curr->next;
        }
        curr->next = NULL;
        back = curr;
        size--;
    }

    void remove_element(int v) {
        if (size == 0) {
            cout << "List is empty";
            return;
        }

        if (front->data == v) {
            return remove_head();
        }
        if (back->data == v) {
            return remove_tail();
        }

        Node* prev = front;

        while (prev->next != NULL && prev->next->data != v) {
            prev = prev->next;
        }

        if (prev->next == NULL) {
            cout << "Node not found";
            return;
        }

        Node* left = prev;
        Node* right = prev->next->next;
        left->next = right;
        size--;
    }

    void displayState() {
        cout << "Head = ";
        if (front == NULL) {
            cout << "NULL ";
        } else {
            cout << front->data << " ";
        }
        cout << "Tail = ";
        if (back == NULL) {
            cout << "NULL ";
        } else {
            cout << back->data << " ";
        }
    }
};

int main() {
    LinkedList list = LinkedList();
    int n;
    int inp1, inp2;
    while (true) {
        cin >> n;

        if (n == 8) break;
        switch (n) {
            case 1:
                cin >> inp1;
                list.insert_front(inp1);
                break;
            case 2:
                cin >> inp1;
                list.insert_back(inp1);
                break;
            case 3:
                cin >> inp1 >> inp2;
                list.insert_after_node(inp1, inp2);
                break;
            case 4:
                cin >> inp1 >> inp2;
                list.update_node(inp1, inp2);
                break;
            case 5:
                list.remove_head();
                break;
            case 6:
                cin >> inp1;
                list.remove_element(inp1);
                break;
            case 7:
                list.remove_tail();
                break;
            default:
                break;
        }
        list.displayState();
    }
    return 0;
}