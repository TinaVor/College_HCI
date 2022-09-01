#define _CRT_SECURE_NO_WARNINGS
#define FNAME "input.txt"
#include <stdio.h>
#include <string.h>
#include <locale.h>

int main() {

	FILE* F = fopen(FNAME, "r");
	setlocale(LC_ALL, "");
	int a[256] = { 0 };
	
	unsigned char  h;
	while (!feof(F))
	{
		h = fgetc(F);
		if(!feof(F)) a[(int)h]++;
	}

	for (int i = 12; i < 256; i++)
	{
		if (a[i] != 0)
		{
			printf("%d : %c - %d \n", i, i, a[i]);
		}
	}
	return 0;
}