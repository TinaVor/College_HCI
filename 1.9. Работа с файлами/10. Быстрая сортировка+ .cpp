#include <stdio.h>
void sort(int a[], int b, int t, int m) {
    int i = b + t;
    while (i <= m) {
        int y = a[i];
        int j = i - t;
        while (j >= b && a[j] > y) {
            a[j + t] = a[j];
            j -= t;
        }
        a[j + t] = y;
        i += t;
    }
}
int main() {
    long signed m = 0;
    int t = 1;
    FILE* f1 = NULL;
    f1 = fopen("input.bin", "rb");
    fread(&m, sizeof(int), 1, f1);
    int* a = new int[m]();
    fread(a, sizeof(int), m, f1);
    fclose(f1);
    while (t < m / 6) t = 3 * t + 1;

    while (t >= 1) {
        for (int i = 0; i < t; i++) sort(a, i, t, m - 1);
        t = (t - 1) / 3;
    }
    FILE* f2 = NULL;
    f2 = fopen("output.bin", "wb");
    fwrite(a, sizeof(int), m, f2);
    fclose(f2);
    return 0;
}