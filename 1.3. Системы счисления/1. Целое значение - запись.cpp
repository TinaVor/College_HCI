#include <stdio.h>
#include <locale.h>

int main()
{
    int n;
    int b;
    int x;
  
    scanf_s("%d", &b);
    do {
            
        scanf_s("%d", &n);
    } while (n < 0);


    char buffer[33] = "", z;
    char* p = buffer + 32;

     do {
         x = n % b;
         z = x + ((x < 10) ? '0' : 'a' - 10);
         *--p = z;
         n /= b;
     } while (n);
     printf("%s", p);
}
