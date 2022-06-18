#include<iostream>
#include<cstdio>
#include<cstring>
#define MAX	10000
using namespace std;
int main()
{
	int a[MAX],b[MAX],c[MAX];
	char stra[MAX],strb[MAX],t[MAX];
	int lena,lenb,lenc,i,x,temp;
	gets(stra);
	gets(strb);
	lena=strlen(stra);
	lenb=strlen(strb);
	if((lena<lenb)||(lena==lenb&&strcmp(stra,strb)<0))
	{
		strcpy(t,stra);
		strcpy(stra,strb);
		strcpy(strb,t);
		temp=lena;
		lena=lenb;
		lenb=temp;
		cout<<"-";
	} 
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
	for(lenc=0;lenc<lena;lenc++)
	{
		if(a[lenc]<b[lenc])
		{
			a[lenc+1]=a[lenc+1]-1;
			a[lenc]=a[lenc]+10;
		}
		c[lenc]=a[lenc]-b[lenc];
	}
	while(c[lenc]==0)	lenc--;
	for(i=lenc;i>=0;i--)
	{
		cout<<c[i];
	}
	cout<<endl;
	return 0;
} 
