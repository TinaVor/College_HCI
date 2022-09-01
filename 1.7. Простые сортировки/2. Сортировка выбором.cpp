#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
void select_sort(int* a, int n) {
	
	for (int i = 0; i < n-1; i++) {
		int min = i, t; 
		for (int j = i + 1; j < n; j++) {
			if (a[j] < a[min]) {
				min = j;
			}
		}
		if (i != min) {
			t = a[i];
			a[i] = a[min];
			a[min] = t;
		}
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
	select_sort(a, n);
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	return 0;
}
