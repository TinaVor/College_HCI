#define _CRT_SECURE_NO_WARNING 
#include <stdio.h> 
#include <iostream>

int invtab_to_permut(int b[], int a[], int n) {
    for (int i = 0; i < n; i++) {
        if (b[i] >= n) return 0;
    }
    if (b[n - 1] != 0)
        return 0;
    else {
        int c;
        for (int i = 0; i < n; i++) {
            c = b[i];
            for (int j = 0; j <= c; j++) {
                if (c == 0) {
                    while (a[j] != 0) {
                        j++;
                        c++;
                    }
                    break;
                }
                else if (a[j] != 0)
                    c++;
            }
            a[c] = (i + 1);
        }
        return 1;
    }
}

int main() {
    int n, * a, * b;
    scanf("%d", &n);
    a = (int*)malloc(sizeof(int) * n);
    b = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &b[i]);
        a[i] = 0;
    }
    if (invtab_to_permut(b, a, n)) {
        for (int i = 0; i < n; i++) {
            printf("%d ", a[i]);
        }
    }
    else
        printf("NO");
    return 0;
}