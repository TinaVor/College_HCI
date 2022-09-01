#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void quickSort(int* a, int left, int right)
{
    int pivot; // разрешающий элемент
    int l_hold = left; //левая граница
    int r_hold = right; // правая граница
    pivot = a[left];
    while (left < right) 
    {
        while ((a[right] >= pivot) && (left < right))
            right--; 
        if (left != right) 
        {
            a[left] = a[right]; 
            left++;
        }
        while ((a[left] <= pivot) && (left < right))
            left++;
        if (left != right) 
        {
            a[right] = a[left];
            right--; 
        }
    }
    a[left] = pivot;
    pivot = left;
    left = l_hold;
    right = r_hold;

    if (left < pivot)
        quickSort(a, left, pivot - 1);
    if (right > pivot)
        quickSort(a, pivot + 1, right);
}

int main() {
    int* a;
    int n;
    scanf("%d", &n);
    a = (int*)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    quickSort(a, 0, n - 1);
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    return 0;
}