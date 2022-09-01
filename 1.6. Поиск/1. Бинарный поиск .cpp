#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int Search_Binary(int* a, int left, int right, int x)
{
    int midd = 0;
    while (1)
    {
        midd = (left + right) / 2;

        if (x < a[midd])       
            right = midd - 1;      
        else if (x > a[midd])  
            left = midd + 1;    
        else                       
            return midd;           

        if (left > right)          
            return -1;
    }
}
int main() {
    int* a;
    int n, x;
    scanf("%d", &n);
    scanf("%d", &x);
    a = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int index = 0;
    index = Search_Binary(a, 0, n, x);
    if (index >= 0) {
        printf("%d", index);
    }
    else {
        printf("-1");
    }
    return 0;
}




    
    

