#include <iostream>
#include <string>
#include <fstream>
#include <map>
using namespace std;
ifstream fin;

int main() {
    fin.open("input.txt");

    int a[256] = { 0 };

    if (fin.is_open()) {
        char ch;
        while (fin.get(ch)) {
            for (int i = 28; i < 127; i++) {
                if (char(i) == ch) a[i]++;
            }
        }
    }
  
    for (int i = 28; i < 256; i++) {
        if (a[i] != 0) {
            cout << char(i) << " ";
            for (int j = 0; j < a[i]; j++) {
                cout << "#";
            }
            cout << endl;
        }
    }
    return 0;
}