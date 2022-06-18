#include<iostream>
#include<cstdio>
#include<cstring>
#define MAX	10000
using namespace std;
int main()
{
	int a[MAX],b[MAX],c[MAX];
	char stra[MAX],strb[MAX];
	int lena,lenb,lenc,i,x;
	gets(stra);
	gets(strb);
	lena=strlen(stra);
	lenb=strlen(strb);
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	memset(c,0,sizeof(c));
	for(i=0;i<lena;i++)
	{
		a[i]=stra[lena-i-1]-'0';
	}
	for(i=0;i<lenb;i++)
	{
		b[i]=strb[lenb-i-1]-'0';
	}
	lenc=0;x=0;
	while(lenc<lena||lenc<lenb)
	{
		c[lenc]=a[lenc]+b[lenc]+x;
		x=c[lenc]/10;
		c[lenc]%=10;
		lenc++;
	} 
	c[lenc]=x;
	if(c[lenc]==0)	lenc--;
	for(i=lenc;i>=0;i--)
	{
		cout<<c[i];
	}
	cout<<endl;
	return 0;
} 
