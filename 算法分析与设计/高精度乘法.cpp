#include <iostream>
#include <cstdio>
#include <cstring>
#define MAX 10000
using namespace std;
int main()
{
	int a[MAX], b[MAX], c[MAX];
	char a1[MAX], b1[MAX];
	int lena, lenb, lenc, i, j, x;
	memset(a, 0, sizeof(a));
	memset(b, 0, sizeof(b));
	memset(c, 0, sizeof(c));
	gets(a1);
	gets(b1);
	lena = strlen(a1);
	lenb = strlen(b1);
	for (i = 0; i < lena; i++)
	{
		a[i] = a1[lena - i - 1] - 48;
	}
	for (i = 0; i < lenb; i++)
	{
		b[i] = b1[lenb - i - 1] - 48;
	}
	x = 0;
	for (i = 0; i < lena; i++)
	{
		for (j = 0; j < lenb; j++)
		{
			c[i + j] = c[i + j] + a[i] * b[j] + x;
			x = c[i + j] / 10;
			c[i + j] %= 10;
		}
		c[i + j] = x;
		x = 0;
	}
	lenc = i + j;
	while (c[lenc] == 0)
		lenc--;
	for (i = lenc; i >= 0; i--)
	{
		cout << c[i];
	}
	cout << endl;
}
