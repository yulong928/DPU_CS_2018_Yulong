#include<iostream>
using namespace std; 
void bubblesort(int a[],int n)
{
	int b,exchanged=n-1,temp;
	while(exchanged!=0)
	{
		b=exchanged;exchanged=0;
		for(int i=0;i<b;i++)
		{
			if(a[i]>a[i+1]){
				temp=a[i];a[i]=a[i+1];a[i+1]=temp;
				exchanged=i;
			}
		}
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
	bubblesort(a,n);
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
	return 0;
}
