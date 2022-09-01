#define _CRT_SECURE_NO_WARNING 
#include <stdio.h> 
#include <stdlib.h> 
int binsearch(double* a, int n, int x) {
    int r = n - 1, l = 0, i;
    while ((r - l) > 1) {
        i = (r + l) / 2;
        if (a[i] < x)
            l = i;
        else
            r = i;
    }
    if (x - a[l] <= a[r] - x)
        return l;
    else
        return r;
}
int main() {
    int n, x;
    double* arr;
    scanf("%d", &n);
    scanf("%d", &x);
    arr = (double*)malloc(n * sizeof(double));
    for (int i = 0; i < n; i++) {
        scanf("%lf", &arr[i]);
    }
    printf("%d",binsearch(arr, n, x));
    free(arr);
}