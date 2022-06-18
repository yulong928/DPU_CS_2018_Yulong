#include<iostream>
#include<cstdio>
#include<cstring>
#define MAX 10000
using namespace std;
int main()
{
	int a[MAX],c[MAX];
	char stra[MAX];
	int x,i,b,lena;
	gets(stra);
	cin>>b;
	lena=strlen(stra);
	for(i=0;i<lena;i++)
	{
		a[i]=stra[i]-48;
	}
	x=0;
	int pf=0;
	for(i=0;i<lena;i++)
	{
		x*=10;
		c[i]=(a[i]+x)/b;
		x=(a[i]+x)%b;
	}
	i=0;
	while(c[i]==0&&i<lena)
	{
		i++;
	}
	for(;i<lena;i++)
	{
		cout<<c[i];
	}
	cout<<endl;
	return 0;
}
