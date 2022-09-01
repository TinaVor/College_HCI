#include <stdio.h>
int main() {
  long signed A, B = 0;
  long long signed sum = 0;
  FILE* f1 = NULL;
  FILE* f2 = NULL;
  f1 = fopen("input.bin", "rb");
  f2 = fopen("output.bin", "wb");
  fread(&A, sizeof(int), 1, f1);
  fread(&B, sizeof(int), 1, f1);
  sum = (long long)A + (long long)B;
  if (sum <= 0 && sum % 2 != 0)
    sum = (sum / 2) - 1;
  else
    sum /= 2;
  fwrite(&sum, sizeof(int), 1, f2);
  return 0;
}