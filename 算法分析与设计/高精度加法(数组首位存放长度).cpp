#include<iostream>
#include<cstdio>
#include<cstring>
#define MAX	10000
using namespace std;
int main()
{
	int a[MAX],b[MAX],c[MAX];
	char stra[MAX],strb[MAX];
	int i,x;
	gets(stra);
	gets(strb);
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	memset(c,0,sizeof(c));
	a[0]=strlen(stra);
	b[0]=strlen(strb);
	for(i=1;i<=a[0];i++)
	{
		a[i]=stra[a[0]-i]-'0';
	}
	for(i=1;i<=b[0];i++)
	{
		b[i]=strb[b[0]-i]-'0';
	}
	c[0]=1;x=0;
	while(c[0]<=a[0]||c[0]<=b[0])
	{
		c[c[0]]=a[c[0]]+b[c[0]]+x;
		x=c[c[0]]/10;
		c[c[0]]%=10;
		c[0]++;
	} 
	c[c[0]]=x;
	if(c[c[0]]==0)	c[0]--;
	for(i=c[0];i>=1;i--)
	{
		cout<<c[i];
	}
	cout<<endl;
	return 0;
} 
