#define _CRT_SECURE_NO_WARNING 
# include <math.h>
# include <stdio.h> 
int main() { 
 int n, t, d, s; 
 scanf("%d", &d); 
 scanf("%d", &s); 
  
 long double** matr = new long double* [2001]; 
 for (int i = 0; i <= 2000; i++) { 
  matr[i] = new  long double[2001]; 
  matr[i][0] = matr[i][i] = 1; 
 } 
 for (int i = 2; i <= 2000; i++) { 
  for (int j = 1; j < i; j++) { 
   matr[i][j] = fmod(matr[i - 1][j - 1], d) + fmod(matr[i - 1][j], d); 
  } 
 }  
   
 for (int i = 0; i < s; i++) 
 { 
  scanf("%d", &n); 
  scanf("%d", &t); 
  if (t>n || t<0) { 
   printf("0\n"); 
   continue; 
  } 
  if (n == 0 || t == 0 || t == n) { 
   printf("1\n"); 
   continue; 
  } 
  printf("%0.10Lg\n", fmodl(matr[n][t], d)); 
 } 
 
 return 0; 
}