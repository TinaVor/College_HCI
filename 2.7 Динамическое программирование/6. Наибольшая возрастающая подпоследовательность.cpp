#include <iostream>
#include <vector>

using namespace std;

void res(vector<int> a, int K) {
  int x[10000], y[10000];

  for (int i = 0; i < K; ++i) {
    x[i] = 1;
    y[i] = -1;
    for (int j = 0; j < i; ++j)
      if (a[j] < a[i])
        if (1 + x[j] > x[i]) {
          x[i] = 1 + x[j];
          y[i] = j;
        }
  }

  int as = x[0], ps = 0;
  for (int i = 0; i < K; ++i)
    if (x[i] > as) {
      as = x[i];
      ps = i;
    }
  cout << as << endl;

  vector<int> path;
  while (ps != -1) {
    path.push_back(ps);
    ps = y[ps];
  }
  reverse(path.begin(), path.end());
  for (int i = 0; i < (int)path.size(); ++i) {
    cout << "A[" << path[i] + 1 << "] = " << a[path[i]] << endl;
  }
}

int main() {
  int K;
  cin >> K;
  vector<int> a(K + 1);
  for (int i = 0; i < K; i++) {
    cin >> a[i];
  }
  res(a, K);
}