#include<iostream>
#define MAX 1000
using namespace std;
int arc[MAX][MAX]={-1};
int TSP1(int w)
{
	int edgeCount=0,TSPLength=0;
	int min,u,v;
	int flag[n]={0};
	u=w;flag[w]=1;
	while(edgeCount<n-1)
	{
		min=100;
		for(int j=0;j<n;j++)
		{
			if((flag[j]==0)&&(arc[u][j]!=0)&&(arc[u][j]<min))
			{
				v=j;min=arc[u][j];
			}
		}
		TSPLength+=arc[u][v];
		flag[v]=1;edgeCount++;
		cout<<u<<"-->"<<v<<endl;
		u=v;
	}
	cout<<v<<"-->"<<w<<endl;
	return(TSPLength+arc[u][w]);
}
int main()
{
	
} 
