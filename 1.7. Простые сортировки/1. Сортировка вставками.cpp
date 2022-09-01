#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
void ins_sort(int* a, int n) {
	int x = 0, j = 0;
	for (int i = 1; i < n; i++) {
		x = a[i];
		j = i - 1;
		while (j >= 0 && a[j] > x) {
			a[j + 1] = a[j];
			j = j - 1;
		}
		a[j + 1] = x;
	}
}

int main() {
	int* a;
	int n;
	scanf("%d", &n);
	a = (int*)malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	ins_sort(a, n);
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	return 0;
}