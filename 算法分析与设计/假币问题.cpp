#include<iostream>
using namespace std;
int time=0;
int Coin(int a[],int low,int high,int n)
{
	int i,num1,num2,num3;
	int add1=0,add2=0;
	if(n==1)
	{
		return low+1;
	} 
	if(n%3==0)
	{
		num1=num2=n/3;
	}
	else{
		num1=num2=n/3+1;
	}
	num3=n-num1-num3;
	for(i=0;i<num1;i++)
	{
		add1=add1+a[low+i];
	}
	for(i=num1;i<num1+num2;i++)
	{
		add2=add2+a[low+i];
	}
	if(add1<add2)
	{
		return Coin(a,low,low+num1-1,num1);
	}
	else if(add1>add2)
	{
		return Coin(a,low+num1,low+num1+num2-1,num2);
	}
	else{
		return Coin(a,low+num1+num2,high,num3);
	}
}
int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int sum= Coin(a,0,n-1,n);
	cout<<sum<<" "<<time;
} 
