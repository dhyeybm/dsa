#include <bits/stdc++.h>
using namespace std;
int adj[100][100];
int help[100][100];
void dfs(int u,int n,bool vis[],stack<int> &s)
{
	vis[u] = true;
	for(int i = 1;i<=n;i++)
	{
		if(adj[u][i] && !vis[i])
		{
			dfs(i,n,vis,s);
		}
	}
	s.push(u);
}
void dfs2(int u,int n,bool vis[])
{
	vis[u] = true;
	cout<<u<<' ';
	for(int i = 1;i<=n;i++)
	{
		if(help[u][i] && !vis[i])
		{
			dfs2(i,n,vis);
		}
	}

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
	stack<int> s;
	for(int i = 1;i<=n;i++)
	{
		if(!vis[i])
			dfs(i,n,vis,s);
	}
	cout<<endl;
	for(int i = 1;i<=n;i++)
		for(int j = 1;j<=n;j++)
			help[i][j] = adj[j][i];
	for(int i = 1;i<=n;i++)
		vis[i] = false;
	while(!s.empty())
	{
		int u = s.top();
		s.pop();
		/*cout<<u<<' ';*/
		if(!vis[u]){
			dfs2(u,n,vis);
			cout<<endl;
		}
	}
	
}