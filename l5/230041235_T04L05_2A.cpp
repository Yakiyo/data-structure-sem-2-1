#include <iostream>

using namespace std;

class Node {
   public:
    int data;
    Node* next;
    Node* prev;

    Node(int v) {
        data = v;
        next = NULL;
        prev = NULL;
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
        cout << "insert front\n";
        if (size == 0) {
            front = create_node(v);
            back = front;
            return;
        }

        Node* newFront = create_node(v);
        newFront->next = front;
        front->prev = newFront;
        front = newFront;
        size++;
    }

    void insert_back(int v) {
        Node* newBack = create_node(v);
        if (size == 0) {
            back = newBack;
            front = back;
            return;
        }
        back->next = newBack;
        newBack->prev = back;
        back = newBack;
        size++;
    }

    void insert_after_node(int v, int n) {
        if (size == 0) {
            cout << "Linked List is empty\n";
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
        left->next = newNode;
        newNode->next = right;

        right->prev = newNode;
        newNode->prev = left;
        size++;
    }

    void update_node(int v, int n) {
        if (size == 0) {
            cout << "Linked List is empty\n";
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
            cout << "List is empty\n";
            return;
        }
        Node* newFront = front->next;
        newFront->prev = NULL;
        front = newFront;
        size--;
    }

    void remove_tail() {
        if (size == 0) {
            cout << "List is empty\n";
            return;
        }
        Node* newBack = back->prev;
        newBack->next = NULL;
        back = newBack;
        size--;
    }

    void remove_element(int v) {
        if (size == 0) {
            cout << "List is empty\n";
            return;
        }

        if (front->data == v) {
            return remove_head();
        }
        if (back->data == v) {
            return remove_tail();
        }

        Node* curr = front;
        while (curr != NULL) {
            if (curr->data = v) break;
            curr = curr->next;
        }
        if (curr == NULL) {
            cout << "Node not found\n";
            return;
        }

        Node* left = curr->prev;
        Node* right = curr->next;

        left->next = right;
        right->prev = left;
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
        cout << endl;
    }

    Node* get_front() const {
        return front;
    }

    void remove_node(Node* node) {
        Node* prev = node->prev;
        Node* next = node->next;
        if (prev != NULL) {
            prev->next = next;
        }
        if (next != NULL) {
            next->prev = prev;
        }

        if (node == front) {
            front = next;
        }
        if (node == back) {
            back = prev;
        }
        delete node;
        size--;
    }

    void printF() const {
        if (size == 0) {
            cout << "List is empty\n";
            return;
        }
        cout << "Head2Tail: ";
        Node* curr = front;
        while (curr != NULL) {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }

    void printB() const {
        if (size == 0) {
            cout << "List is empty\n";
            return;
        }
        cout << "Tail2Head: ";
        Node* curr = back;
        while (curr != NULL) {
            cout << curr->data << " ";
            curr = curr->prev;
        }
        cout << endl;
    }
};

int main() {
    int n;
    LinkedList list = LinkedList();
    while (true) {
        cin >> n;
        if (n == -1) break;

        list.insert_back(n);
    }

    Node* node = list.get_front();

    while (true) {
        int num = node->data;
        while (node->next != NULL && node->next->data == num) {
            Node* toDelete = node->next;
            list.remove_node(toDelete);
        }
        node = node->next;
    }

    return 0;
}