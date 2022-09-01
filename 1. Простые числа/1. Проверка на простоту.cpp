#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	int count = 0, t = 2;
	while (t * t <= n && count == 0) {
		if (n % t == 0) count++; t++;
	}

	if (n == 1) printf("NO");
	else if (count == 0) printf("YES");
	else printf("NO");
	return 0;
}