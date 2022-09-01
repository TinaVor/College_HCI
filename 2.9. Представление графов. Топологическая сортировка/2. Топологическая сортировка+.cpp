#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    string rez = "";
    vector<int>* arr = new vector<int>[N];
    int* stepen = new int[N] {0};
    
    priority_queue<int, vector<int>, greater<int>> que;
    for (int i = 0; i < M; i++) {
        int A, B;
        cin >> A >> B;
        stepen[B - 1]++;
        arr[A - 1].push_back(B - 1);
    }

    for (int i = 0; i < N; i++) {
        if (stepen[i] == 0) que.push(i);
    }

    while (!que.empty()) {
        int out = que.top();
        rez += to_string(out + 1) + " ";
        que.pop();
        stepen[out] = -1;
        for (int i = 0; i < arr[out].size(); i++) {
            int s = arr[out][i];
            stepen[s]--;
            if (stepen[s] == 0) {
                que.push(s);
            }
        }
    }
    for (int i = 0; i < N; i++) {
        if (stepen[i] != -1) {
            cout << "bad course";
            return 0;
        }
    }
    cout << rez;

    return 0;
}