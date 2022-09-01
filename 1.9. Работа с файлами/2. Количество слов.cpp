#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <fstream>
#include <map>
using namespace std;
ifstream fin;
int main() {
    fin.open("input.txt");
    int a[50] = { 0 };
    if (fin.is_open()) {
        string c;
        while (!fin.eof()) {
            c = "";
            fin >> c;
            a[c.length()]++;
        }
    }
  
    for (int i = 1; i < 50; i++) {
        if (a[i] != 0) {
            cout << i << " - " << a[i] << endl;
        }
    }
    return 0;
}