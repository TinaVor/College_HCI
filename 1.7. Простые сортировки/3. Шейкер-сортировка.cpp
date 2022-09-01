#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
void shake_sort(int* a, int n){
    int left = 0, right = n - 1; 
    int fl = 1;  
    while ((left < right) && fl > 0)
    {
        fl = 0;
        for (int i = left; i < right; i++)  {
            if (a[i] > a[i + 1]) {             
                int t = a[i];
                a[i] = a[i + 1];
                a[i + 1] = t;
                fl = 1;      
            }
        }
        right--; 
        for (int i = right; i > left; i--)  {
            if (a[i - 1] > a[i]){           
                int t = a[i];
                a[i] = a[i - 1];
                a[i - 1] = t;
                fl = 1;    
            }
        }
        left++;
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
	shake_sort(a, n);
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	return 0;
}
