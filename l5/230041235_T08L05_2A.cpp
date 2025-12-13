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

Node* safe_next(Node* node) {
    if (node == NULL) return NULL;
    return node->next;
}

Node* next_odd(Node* node) {
    return safe_next(safe_next(node));
}

class LinkedList {
   private:
    Node* front;
    Node* back;
    int size;

    Node* create_node(int v) {
        Node* n = new Node(v);
        return n;
    }

   public:
    LinkedList() : size(0), front(NULL), back(NULL) {}

    void insert_back(int v) {
        Node* newBack = create_node(v);
        if (size == 0) {
            front = newBack;
            back = newBack;
            size++;
            return;
        }
        back->next = newBack;
        newBack->prev = back;
        back = newBack;
        size++;
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
        size--;
    }

    // inserts node "value" after node "prev"
    void insert_after(Node* prev, Node* value) {
        // in case we are adding after the back node
        // we update back node pointer
        if (prev == back) {
            back = value;
        }
        Node* next = safe_next(prev);
        // connect prev and value
        prev->next = value;
        value->prev = prev;

        // connect value and next
        value->next = next;
        if (next != NULL) {
            next->prev = value;
        }
        size++;
    }

    Node* get_front() const {
        return front;
    }

    void print_list() const {
        Node* curr = front;
        while (curr != NULL) {
            cout << curr->data << " ";
            curr = curr->next;
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

    Node* toAddAfter = list.get_front();

    Node* currentOdd = next_odd(list.get_front());

    while (currentOdd != NULL) {
        Node* nextCurrentOdd = next_odd(currentOdd);
        list.remove_node(currentOdd);
        list.insert_after(toAddAfter, currentOdd);
        toAddAfter = currentOdd;
        currentOdd = nextCurrentOdd;
    }

    list.print_list();
    return 0;
}