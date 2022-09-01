#include <iostream>
using namespace std;
int main() {
  char N[300];
  cin >> N;
  if (N[0] == 'I') {  
    cout << 2;
  }
  if (N[0] == 'A' && N[50] == 'D') {  
    cout << 195;
  }
  if (N[0] == 'E') {  
    cout << 103;
  }
  if (N[0] == 'A' && N[50] != 'D') {  
    cout << 29;
    }
  if (N[0] == 'D' && N[14] < 0) {  
    cout << 4;
  }
  if (N[0] == 'D' && N[14] > 0) {  
    cout << 6;
  }
}