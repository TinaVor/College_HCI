#include <stack>
#include <iostream>

using namespace std;

int main() {
  stack<int> stk;
  bool isOk = true;
  char c;
  do {
    while (c = cin.peek(), c == ' ' || c == '\t') cin.get();
    if (c == EOF || c == '\n' || c == '=') {
      isOk = false;
      cin.get();
    } else {
      int t;
      cin >> t;
      if (cin.fail()) {
        int x, y;
        y = stk.top();
        stk.pop();
        x = stk.top();
        stk.pop();

        switch (c) {
          case '+':
            x += y;
            break;
          case '-':
            x -= y;
            break;
          case '*':
            x *= y;
            break;
          case '/':
            x /= y;
            break;
          default:
            break;
        }
        stk.push(x);
        cin.clear();
        if (c = cin.peek(), c != EOF && c != '\n' && c != '=') cin.get();
      } else
        stk.push(t);
    }
  } while (isOk);

  cout << stk.top() << endl;

  return 0;
}