
#include <stdio.h>

long long factor(long);

int main() {
long t;
scanf("%ld", &t);
for (int i = 0; i <= t; i++) {
for (int j = 0; j <= i; j++) {
printf("%ld", (factor(i) / (factor(j) * factor(i-j))));
if (i != j) printf(" ");
}
if (i == t) break;
printf("\n");
}
return 0;
}

long long factor(long N) {
long long x = 1;
for (int i = 1; i <= N; i++) x *= i;
return x;
}