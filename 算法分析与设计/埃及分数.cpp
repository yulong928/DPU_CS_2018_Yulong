#include<iostream>
using namespace std;
int gongyueshu(int m,int n)
{
	int r=m%n;
	while(r!=0)
	{
		m=n;
		n=r;
		r=m%n;
	}
	return n;
}
void anjiFenshu(int a,int b)
{
	int e,r;
	cout<<a<<"/"<<b<<"=";
	do{
		e=b/a+1;
		cout<<"1/"<<e<<"+";
		a=a*e-b;
		b=b*e;
		r=gongyueshu(b,a);
		if(r>1)
		{
			a=a/r;b=b/r;
		} 
	}while(a>1);
	cout<<"1/"<<b<<endl;
	return;
}
int main()
{
	int a,b;
	cin>>a>>b;
	anjiFenshu(a,b);
	return 0;
} 
