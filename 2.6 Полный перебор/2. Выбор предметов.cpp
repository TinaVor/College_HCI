#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <math.h>
typedef struct object {
  unsigned long long w;
  unsigned long long c;
  bool pr;
} Object;

unsigned long long Ves (Object* mass, int N) {
  unsigned long long sum = 0;
  for (int i = 0; i < N; i++) {
    if (mass[i].pr == true) sum += mass[i].w;
  }
  return sum;
}
unsigned long long Count(Object* mass, int N) {
  unsigned long long sum = 0;
  for (int i = 0; i < N; i++) {
    if (mass[i].pr == true) sum += mass[i].c;
  }
  return sum;
}
int Long(Object* mass, int N) {
  int L = 0;
  for (int i = 0; i < N; i++) {
    if (mass[i].pr == true) L++;
  }
  return L;
}
int main() {
  freopen("input.txt", "r", stdin);
  int N, L = 0;
  unsigned long long W, C = 0;
  scanf("%d %llu", &N, &W);
  Object* mass = (Object*)malloc(21 * sizeof(Object));
  Object* Output = (Object*)malloc(21 * sizeof(Object));
  for (int i = 0; i < N; i++) {
    scanf("%llu %llu", &mass[i].w, &mass[i].c);
    mass[i].pr = false;
  }
  for (int i = 0; i < pow(2, N); i++) {
    for (int j = 20; j >= 0; j--) {
      mass[j].pr = (i >> j) & 1u;
    }
    if (Ves(mass, N) <= W) {
      if (Count(mass, N) > C) {
        for (int j = 0; j <= 20; j++) {
          Output[j] = mass[j];
        }
        C = Count(mass, N);
        L = Long(mass, N);
      }
    }
  }
  printf("%llu %d\n", C, L);
  for (int i = 0; i < N; i++) {
    if (Output[i].pr == true) printf("%d ", i + 1);
  }
  return 0;
}