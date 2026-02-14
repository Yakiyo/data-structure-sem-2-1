#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Node {
   public:
    char c;
    bool endmark;
    vector<Node*> child;

    Node(char c, bool endmark = false) : c(c), endmark(endmark) {
        child = vector<Node*>(26 * 2, NULL);
    }
};

class Trie {
   public:
    Node* root;
    Pattern* p;

    bool didMatch = false;

    Trie() {
        root = new Node('*', false);
    }

    void setPattern(string s) {
        p = new Pattern(s);
    }

    int charToIdx(char c) {
        if (c >= 'A' && c <= 'Z') {
            return tolower(c) - 'a' + 26;
        } else {
            return tolower(c) - 'a';
        }
    }

    void insert(string str) {
        Node* curr = root;
        for (char c : str) {
            int i = charToIdx(c);

            Node* target = curr->child[i];
            if (!target) {
                target = new Node(tolower(c));
                curr->child[i] = target;
            }
            curr = target;
        }

        curr->endmark = true;
    }

    // bool search(string str) {
    //     Node* curr = root;

    //     for (char c : str) {
    //         int i = charToIdx(c);
    //         Node* target = curr->child[i];
    //         if (!target) return false;

    //         curr = target;
    //     }

    //     return curr->endmark;
    // }

    // void display(Node* node, char str[], int level) {
    //     // if an endmark is reached, print it
    //     if (node->endmark) {
    //         str[level] = '\0';
    //         cout << str << endl;
    //     }

    //     for (int i = 0; i < 26 * 2; i++) {
    //         if (node->child[i]) {
    //             str[level] = node->child[i]->c;
    //             display(node->child[i], str, level + 1);
    //         }
    //     }
    // }

    void iterateAll(Node* node) {
        if (node->endmark) {
            if (p->isEnd()) {
                didMatch = true;
            }
        }

        for (int i = 0; i < 26 * 2; i++) {
            if (!node->child[i]) continue;

            char c = node->child[i]->c;
            if (c == p->currChar()) {
                p->advance();
                iterateAll(node->child[i]);
                p->retreat();
            } else {
                iterateAll(node->child[i]);
            }
        }
    }
};

class Pattern {
   public:
    string s;
    int pos = 0;
    Pattern(string s) : s(s) {}

    char currChar() {
        return s[pos];
    }

    void advance() {
        if (pos < s.size())
            pos++;
    }

    void retreat() {
        if (pos > 0)
            pos--;
    }

    bool isEnd() {
        return pos >= s.size();
    }
};

vector<string> splitStr(string str, char delimiter) {
    vector<string> words;
    string word;
    stringstream strm(str);

    while (getline(strm, word, delimiter)) {
        words.push_back(word);
    }

    return words;
}

int main() {
    //
    return 0;
}