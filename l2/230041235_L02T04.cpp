#include<iostream>
#include<stack>
#include<vector>

using namespace std;

int main() {
    int n;
    vector<int> nums;
    stack<int> stk;
    vector<int> nge;

    while (true) {
        cin >> n;
        if (n == -1) {
            break;
        }
        nums.push_back(n);
    }
    for (int i = nums.size() - 1; i >= 0; i--) {

        while (!stk.empty() && stk.top() <= nums[i]) {
            stk.pop();
        }

        if (stk.empty()) {
            nge.push_back(-1);
        } else {
            nge.push_back(stk.top());
        }
        stk.push(nums[i]);
    }

    for (int i = nge.size() - 1; i >= 0; i--) {
        cout << nge[i] << ' ';
    }
}