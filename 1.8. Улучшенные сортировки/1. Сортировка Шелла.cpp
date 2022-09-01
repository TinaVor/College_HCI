#include <malloc.h>
#include <stdio.h>
#include <conio.h>

void Shell(int *a, int n)
{
    int i, j, step, tmp;
    for (step = n / 2; step > 0; step /= 2) {
        for (i = step; i < n; i++)
        {
            tmp = a[i];
            for (j = i; j >= step; j -= step)
            {
                if (tmp < a[j - step])
                    a[j] = a[j - step];
                else
                    break;
            }
            a[j] = tmp;
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
    Shell(a, n);
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    return 0;
}