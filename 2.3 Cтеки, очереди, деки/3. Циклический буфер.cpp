#include <iostream>
#include <queue>
using namespace std;

void main() {
  int n, m;
  cin >> n >> m;

  queue<int> que;
  for (int i = 0; i < m; i++) {
    int num;
    cin >> num;
    if (num >= 0) {
      bool flag = false;
      for (int j = 0; j < num; j++) {
        int temp;
        cin >> temp;
        if (que.size() < n)
          que.push(temp);
        else
          flag = true;
      }
      m = m - num;
      if (flag) cout << "Memory overflow" << endl;
    } else {
      num = num * (-1);
      long long sum = 0;
      int total = 0;
      if (num > que.size()) {
        if (que.size() == 0) {
          cout << "Empty queue" << endl;
          continue;
        }
        num = que.size();
        for (int j = 0; j < num; j++) {
          sum = sum + que.front();
          que.pop();
        }
        total = sum / num;
        cout << total << endl;
        cout << "Empty queue" << endl;
      } else {
        for (int j = 0; j < num; j++) {
          sum += que.front();
          que.pop();
        }
        total = sum / num;
        cout << total << endl;
      }
    }
  }
}