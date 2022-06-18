#include <iostream>
#include <cstdio>
#include <cstring>
#define MAX 100000
using namespace std;
int main()
{
	int a[MAX], b[MAX], c[MAX];
	int n, i, j, k, x, m, num, lena, lenb, lenc;
	cin >> n;
	memset(a, 0, sizeof(a));
	memset(c, 0, sizeof(c));
	a[0] = 1;
	lena = 1;
	for (i = 2; i <= n; i++)
	{
		num = i;
		memset(b, 0, sizeof(b));
		lenb = 0;
		while (num / 10 != 0)
		{
			b[lenb] = num % 10;
			lenb++;
			num /= 10;
		}
		b[lenb++] = num;
		x = 0;
		for (j = 0; j < lena; j++)
		{
			for (k = 0; k < lenb; k++)
			{
				c[j + k] = c[j + k] + a[j] * b[k] + x;
				x = c[j + k] / 10;
				c[j + k] %= 10;
			}
			c[j + k] = x;
			x = 0;
		}
		lenc = j + k + 1;
		memset(a, 0, sizeof(a));
		for (m = 0; m < lenc; m++)
		{
			a[m] = c[m];
		}
		lena = lenc;
		memset(c, 0, sizeof(c));
	}
	while (a[lena] == 0)
		lena--;
	for (i = lena; i >= 0; i--)
	{
		cout << a[i];
	}
	cout << endl;
	return 0;
}
