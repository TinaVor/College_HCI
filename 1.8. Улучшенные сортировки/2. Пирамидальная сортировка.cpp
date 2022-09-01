#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
void siftDown(int* a, int root, int bottom)
{
    int maxChild; 
    bool fl = false; 
    while ((root * 2 <= bottom) && (!fl))
    {
        if (root * 2 == bottom)    
            maxChild = root * 2;    

        else if (a[root * 2] > a[root * 2 + 1])
            maxChild = root * 2;
        else
            maxChild = root * 2 + 1;
        
        if (a[root] < a[maxChild])
        {
            int temp = a[root]; 
            a[root] = a[maxChild];
            a[maxChild] = temp;
            root = maxChild;
        }
        else 
            fl = true; 
    }
}
void heapSort(int* a, int n)
{
    for (int i = (n / 2); i >= 0; i--)
        siftDown(a, i, n - 1);

    for (int i = n - 1; i >= 1; i--)
    {
        int temp = a[0];
        a[0] = a[i];
        a[i] = temp;
        siftDown(a, 0, i - 1);
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
    heapSort(a, n);
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    return 0;
}