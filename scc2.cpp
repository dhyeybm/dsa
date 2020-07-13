#include <bits/stdc++.h>
using namespace std;
int adj[100][100];
void dfs(int u,int n,bool vis[],int arr[],int &last)
{
	cout<<u<<' ';
	vis[u] = true;
	for(int i = 1;i<=n;i++)
	{
		if(adj[u][i] && !vis[i])
		{
			dfs(i,n,vis,arr,last);
		}
	}
	arr[last--] = u;


}
int main()
{
	int n,e;
	cin>>n>>e;
	for(int i = 0;i<e;i++)
	{
		int x,y;
		cin>>x>>y;
		adj[x][y] = 1;
	}
	bool vis[n+1] = {false};
	int arr[n+1],last = n;
	for(int i = 1;i<=n;i++)
	{
		if(!vis[i])
			dfs(i,n,vis,arr,last);
	}
	cout<<endl;
	for(int i = 1;i<=n;i++)
	{
		for(int j = 1;j<=i;j++)
		{
			swap(adj[i][j],adj[j][i]);
		}
	}

	int arr2[n+1];
	last = n;
	for(int i = 1;i<=n;i++)
		vis[i] = false;
	for(int i = 1;i<=n;i++)
	{
		if(!vis[arr[i]])
		{
			dfs(arr[i],n,vis,arr2,last);
			cout<<endl;
		}
	}
}