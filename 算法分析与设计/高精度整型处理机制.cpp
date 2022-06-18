#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int n,temptop=0;
	cin>>n;
	int temp[100];
	while(n/10!=0)
	{
		temp[temptop]=n%10;
		temptop++;
		n/=10;
	}
	temp[temptop]=n;
} 
