#include<iostream>
#define MAX 1000
using namespace std;
int data[MAX][MAX];
void Full(int number,int begin,int size)
{
	int i,j,k;
	if(size==0)
	{
		return;
	}
	if(size==1)
	{
		data[begin][begin]=number;
		return;
	}
	i=begin;j=begin;
	for(k=0;k<size-1;k++)
	{
		data[i][j]=number;
		number++;
		i++;
	}
	for(k=0;k<size-1;k++)
	{
		data[i][j]=number;
		number++;
		j++;
	}
	for(k=0;k<size-1;k++)
	{
		data[i][j]=number;
		number++;
		i--;
	}
	for(k=0;k<size-1;k++)
	{
		data[i][j]=number;
		number++;
		j--;
	}
	Full(number,begin+1,size-2);
}
int main() 
{
	int size;
	cin>>size;
	Full(1,0,size);
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<size;j++)
		{
			cout<<data[i][j]<<"\t";
		}
		cout<<"\n";
	}
	return 0;
} 
