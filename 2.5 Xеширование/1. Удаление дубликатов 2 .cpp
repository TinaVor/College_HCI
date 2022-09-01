#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

class Hash {
  int size;
  vector<int>* table;

 public:
  Hash(int value) {
    this->size = value;
    table = new vector<int>[size];
  }
  bool Insert(int key, int value) {
    int ind = HashFun(key);
    int temp = table[ind].size();
    if (temp > 0) {
      for (int i = 0; i < temp; i++) {
        if (table[ind][i] == value) {
          return 0;
        }
      }
    }
    table[ind].push_back(value);
    return 1;
  }
  int HashFun(int q) {
    q *= q;
    q %= this->size;
    return q < 0 ? -q : q;
  }
};

int main() {
  int N;
  ifstream inp;
  inp.open("input.bin", ios_base::binary);
  ofstream out;
  out.open("output.bin", ios_base::binary);
  inp.read((char*)&N, sizeof(N));
  vector<int> rez;
  Hash hastab(N);
  for (int i = 0; i < N; i++) {
    int n;
    inp.read((char*)&n, sizeof(n));
    int flag = hastab.Insert(n, n);
    if (flag) rez.push_back(n);
  }
  int t = rez.size();
  out.write((char*)&t, 4);
  for (int i = 0; i < t; i++) {
    out.write((char*)&rez.at(i), 4);
  }
}