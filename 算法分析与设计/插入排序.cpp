#include<iostream>
using namespace std; 
void charu(int a[],int n)
{
	int temp,loc;
	for(int j=1;j<n;j++)
	{
		temp=a[j];
		loc=j;
		while(a[loc-1]>temp&&loc>0)
		{
			a[loc]=a[loc-1];
			loc--;
		}
		a[loc]=temp;
	}
}
int main()
{
	int n,sum;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	charu(a,n);
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
	return 0;
}
