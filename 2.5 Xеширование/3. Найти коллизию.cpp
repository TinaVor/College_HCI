#include <iostream>
#include <fstream>
#include <unordered_map>

using namespace std;

int main() {
  unordered_map<unsigned int, unsigned int> HT;

  unsigned int n = 0;
  for (unsigned int i = 1; i <= 200000; i++) {
    printf("eval %u\n", i);
    fflush(stdout);
    scanf("%u", &n);
    if (HT.find(n) != HT.end()) {
      printf("answer %u %u", HT[n], i);
      return 0;
    }
    HT[n] = i;
  }
}