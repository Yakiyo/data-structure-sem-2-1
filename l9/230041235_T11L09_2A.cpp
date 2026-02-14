#include <bits/stdc++.h>
using namespace std;

int hashfunc(string word) {
    int hashValue = 0;
    for (char c : word) {
        if (isupper(c)) c = tolower(c);
        if (islower(c)) {
            int bitPos = c - 'a';
            hashValue |= 1 << bitPos;
        }
    }
    return hashValue;
}

int main() {
    string input;
    getline(cin, input);

    string target;
    cin >> target;

    int targetHashValue = hashfunc(target);

    string temp;
    stringstream ss(input);

    while (ss >> temp) {
        int tempHashValue = hashfunc(temp);

        if (tempHashValue == targetHashValue) {
            cout << temp << " ";
        }
    }
    cout << endl;
}