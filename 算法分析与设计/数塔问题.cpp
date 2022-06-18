#include<iostream>
using namespace std;
#define MAX 100
int d[MAX][MAX];
int DataTower(int n)
{
	int maxAdd[n][n],path[n][n];
	int i,j;
	for(j=0;j<n;j++)
	{
		maxAdd[n-1][j]=d[n-1][j];
	}
	for(i=n-2;i>=0;i--)
	{
		for(j=0;j<=i;j++)
		{
			if(maxAdd[i+1][j]>maxAdd[i+1][j+1])
			{
				maxAdd[i][j]=d[i][j]+maxAdd[i+1][j];
				path[i][j]=j;
			}
			else{
				maxAdd[i][j]=d[i][j]+maxAdd[i+1][j+1];
				path[i][j]=j+1;
			}
		}
	}
	cout<<"Â·¾¶Îª:"<<d[0][0];
	j=path[0][0];
	for(i=1;i<n;i++)
	{
		cout<<"-->";
		cout<<d[i][j];
		j=path[i][j];
	}
	cout<<endl;
	return maxAdd[0][0];
}
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<=i;j++)
		{
			cin>>d[i][j];
		}
	}
	int maxadd = DataTower(n);
	cout<<maxadd<<endl;
} 
