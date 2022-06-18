//—°‘Ò≈≈–Ú
#include<iostream>
#include<cstdio>
#define MAX 100
using namespace std;
int main()
{
	int a[MAX],temp,k;
	cin>>a[0];
	for(int i=1;i<=a[0];i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=a[0];i++)
	{
		k=i;
		for(int j=i;j<=a[0];j++)
		{
			if(a[i]>=a[j])
			{
				k=j;
			}
		}
		if(k!=i)
		{
			temp = a[k];
			a[k] = a[i];
			a[i] = temp;
		}
	}
	for(int i=1;i<=a[0];i++)
	{
		cout<<a[i];
		cout<<" " ;
	}
	cout<<endl;	
} 
