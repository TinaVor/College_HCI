#define _CRT_SECURE_NO_WARNING 
#include <stdio.h> 
#include <stdlib.h> 
int binsearch(int a[], int n, int x, int* r) {
    int y = x + *r, left = 0, right = n - 1, i;
    *r = -1;
    do {
        i = (left + right) / 2;
        if (y == a[i]) {
            if (a[i] == a[n - 1]) {
                *r = n - 1;
                break;
            }
            while (a[i + 1] == y) i++;
            *r = i;
            break;
        }
        else {
            if (a[i] < y)
                left = i + 1;
            else
                right = i - 1;
        }
    } while (left <= right);
    return *r;
}

int main() {
    int n, * arr, q, x, r = 0, y = 0;
    scanf("%d", &n);
    arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    scanf("%d", &q);
    do {
        scanf("%d", &x);
        printf("%d\n", binsearch(arr, n, x, &r));
        q--;
    } while (q != 0);
}
