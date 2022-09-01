#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int main() {
  int N, M;
  cin >> N >> M;

  vector<int>* neighbours = new vector<int>[N];

  int* visited = new int[N];
  int* distance = new int[N];

  for (int i = 0; i < M; i++) {
    int from, to;
    cin >> from >> to;
    neighbours[from - 1].push_back(to - 1);
  }

  for (int i = 0; i < N; i++) {
    distance[i] = -1;
    visited[i] = 0;
  }

  queue<int> plan;

  plan.push(0);
  visited[0] = 1;
  distance[0] = 0;
  while (!plan.empty()) {
    int t = plan.front();
    plan.pop();

    for (int j : neighbours[t]) {
      if (!visited[j]) {
        plan.push(j);
        visited[j] = 1;
        distance[j] = distance[t] + 1;
      }
    }
  }

  for (int i = 0; i < N; i++) {
    cout << distance[i] << endl;
  }
}