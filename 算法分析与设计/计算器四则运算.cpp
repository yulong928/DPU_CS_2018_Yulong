#include<iostream>
#include<cstdio>
#include<cstring>
#define MAX 10000
using namespace std;
void add()
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
}
void jian()
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
}
void cheng()
{
	int a[MAX],b[MAX],c[MAX];
	char a1[MAX],b1[MAX];
	int lena,lenb,lenc,i,j,x;
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	memset(c,0,sizeof(c));
	gets(a1);
	gets(b1);
	lena=strlen(a1);
	lenb=strlen(b1);
	for(i=0;i<lena;i++)
	{
		a[i]=a1[lena-i-1]-48;
	}
	for(i=0;i<lenb;i++)
	{
		b[i]=b1[lenb-i-1]-48;
	}
	x=0;
	for(i=0;i<lena;i++)
	{
		for(j=0;j<lenb;j++)
		{
			c[i+j]=c[i+j]+a[i]*b[j]+x;
			x=c[i+j]/10;
			c[i+j]%=10;
		}
		c[i+j]=x;
		x=0;
	}
	lenc=i+j;
	while(c[lenc]==0)	lenc--; 
	for(i=lenc;i>=0;i--)
	{
		cout<<c[i];
	}
	cout<<endl;
}
void chu()
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
}
int main()
{
	int n;
	scanf("%d\n",&n);
	switch(n)
	{
		case 0:add();break;
		case 1:jian();break;
		case 2:cheng();break;
		case 3:chu();break;
		default:break;
	}
	return 0;
} 
