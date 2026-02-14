#include <bits/stdc++.h>
using namespace std;

int main() {
    unordered_map<string, int> stringCount;
    string line;
    getline(cin, line);
    for (char& c : line) {
        if (ispunct(c)) {
            c = ' ';
        }
    }
    string temp;
    stringstream ss(line);
    while (ss >> temp) {
        stringCount[temp]++;
    }
    for (auto& it : stringCount) {
        if (it.second > 1) {
            cout << it.first << " " << it.second << endl;
        }
    }
}