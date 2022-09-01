#include <iostream>
#include <fstream>
#include <stdio.h>
using namespace std;

int revers(int from) {
    int t;
    char* from_by = (char*)&from;
    char* to_by = (char*)&t;
    to_by[0] = from_by[3];
    to_by[1] = from_by[2];
    to_by[2] = from_by[1];
    to_by[3] = from_by[0];
    return t;
}

int main() {
    int m, y=0, k;
    bool prav_por_bit = true;
    ifstream infile;
    infile.open("input.bin", ios::binary | ios::in);
    infile.read((char*)&m, sizeof(int));

    if (m >= 1 && m <= 10000) {
        prav_por_bit = true;
    }
    else {
        prav_por_bit = false;
        m = revers(m);
    }
   
    for (int i = 0; i < m; i++) {
        infile.read((char*)&k, sizeof(int));
        if (!prav_por_bit) {
            k = revers(k);
        }
        y+= k;
    }

    if (!prav_por_bit) y = revers(y);
  
    ofstream outfile;
    outfile.open("output.bin", ios::binary | ios::out);
    outfile.write((char*)&y, sizeof(int));

    return 0;
}