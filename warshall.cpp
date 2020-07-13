#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,e;
	cin>>n>>e;
	int adj[n+1][n+1] = {0};
	for(int i = 0;i<e;i++)
	{
		int x,y;
		cin>>x>>y;
		adj[x][y] = 1;
	}
	for(int k = 1;k<=n;k++)
	{
		for(int i = 1;i<=n;i++)
		{
			for(int j = 1;j<=n;j++)
			{
				adj[i][j] = adj[i][j]|(adj[i][k]&adj[k][j]);
			}
		}
	}
	for(int i = 1;i<=n;i++)
	{
		for(int j = 1;j<=n;j++)
			cout<<adj[i][j]<<' ';
		cout<<endl;
	}
}