//ц╟ещеепР
#include<iostream>
#include<cstdio> 
#define MAX 100
using namespace std;
int main()
{
	int a[MAX],temp;
	cin>>a[0];
	for(int i=1;i<=a[0];i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=a[0];i++)
	{
		for(int j=a[0];j>i;j--)
		{
			if(a[j]<a[j-1])
			{
				temp=a[j];
				a[j]=a[j-1];
				a[j-1]=temp;
			}
		}
	}
	for(int i=1;i<=a[0];i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
	return 0;
}
