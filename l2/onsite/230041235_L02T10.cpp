#include <iostream>
#include <stack>
using namespace std;

int main() {
  int n;
  cin >> n;
  int arr[n];
  stack<int> initial_lane, middle_lane, final_lane;
  int min = 1;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  for (int i = n - 1; i >= 0; i--) {
    initial_lane.push(arr[i]);
  }
  
  int i = 0;
  while (!initial_lane.empty() || !middle_lane.empty()) {
    if (!initial_lane.empty() && min == initial_lane.top()) {
      final_lane.push(min);
      initial_lane.pop();
      min++;
      
    } else if (!middle_lane.empty() && middle_lane.top() == min) {
      middle_lane.pop();
      final_lane.push(min++);
      
    } else {
      if (!middle_lane.empty() && !initial_lane.empty() && middle_lane.top() < initial_lane.top()) {
        cout << "NO" << endl;
        return 0;
      }
      middle_lane.push(initial_lane.top());
      initial_lane.pop();
    }
  }
  cout << "YES" << endl;
  return 0;
}