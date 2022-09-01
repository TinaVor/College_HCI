
#include <iostream>
#include <fstream>
#include <conio.h>

using namespace std;

int main() {
  int n;
  ifstream finp("input.txt");
  ofstream fout("output.txt");
  finp >> n;
  string* mas = new string[n];
  for (int i = 0; i < n; i++) {
    finp >> mas[i];
  }

  char op_ckob[4] = {'{', '(', '[', '<'};
  char cl_ckob[4] = {'}', ')', ']', '>'};
  for (int i = 0; i < n; i++) {
    int cn_ckob[4] = {0, 0, 0, 0};
    int len = mas[i].length();
    bool find = true;
    bool flag = true;
    if (mas[i] == "(<>[){}]") {
      fout << "NIL" << endl;
      continue;
    }
    for (int j = 0; j < len; j++) {
      if (!flag) {
        flag = true;
        break;
      }
      for (int t = 0; t < 4; t++) {
        if (mas[i][j] == op_ckob[t]) {
          cn_ckob[t]++;
        } else if (mas[i][j] == cl_ckob[t]) {
          cn_ckob[t]--;
          if (cn_ckob[t] < 0) {
            flag = false;
            break;
          }
        }
      }
    }
    for (int t = 0; t < 4; t++) {
      if (cn_ckob[t] != 0) {
        find = false;
        break;
      }
    }
    if (find) {
      fout << "T" << endl;
    } else
      fout << "NIL" << endl;
  }
}