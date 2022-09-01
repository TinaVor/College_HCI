#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> max_P;
vector<int> t, p, s;
int N, K, T;

void sort() {
  for (int i = 0; i < N; i++)
    for (int j = i + 1; j < N; j++) {
      if (t[i] > t[j]) {
        swap(t[i], t[j]);
        swap(p[i], p[j]);
        swap(s[i], s[j]);
      }
    }
}
void solve();

int main() {
  cin >> N >> K >> T;
  t.resize(N);
  p.resize(N);
  s.resize(N);
  max_P.resize(N);
  for (int i = 0; i < N; i++) cin >> t[i];  // время
  for (int i = 0; i < N; i++) cin >> p[i];  // кошелек
  for (int i = 0; i < N; i++) cin >> s[i];  // полнота
  for (int i = 0; i < N; i++)
    if (t[i] < s[i]) p[i] = 0;
  solve();
  cout << *max_element(max_P.begin(), max_P.end());
  return 0;
}

void solve() {
  sort();
  for (int i = 0; i < N; i++) {
    int curMax_P = p[i];
    for (int j = 0; j < i; j++) {
      if (max_P[j] != 0) {
        int dt = t[i] - t[j];
        int dk = abs(s[i] - s[j]);
        if (dk <= dt) curMax_P = max(curMax_P, max_P[j] + p[i]);
      }
    }
    max_P[i] = curMax_P;
  }
}