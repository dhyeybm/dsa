#include <bits/stdc++.h>
using namespace std;
pair<int,int> dfs(vector<vector<int> > &adj,int root,bool vis[])
{
	vis[root] = true;
	int ans = 0,maxd = 0;
	pair<int,int> p;
	for(int i = 0;i<adj[root].size();i++)
	{
		int v = adj[root][i];
		if(!vis[v])
		{
			p = dfs(adj,v,vis);
			ans = max(ans,p.first);
			ans = max(ans,p.second+maxd+1);
			maxd = max(maxd,p.second+1);
		}
	}
	return make_pair(ans,maxd);
}
int main()
{
	int n,e;
	cin>>n>>e;
	vector<vector<int> > adj(n+1);
	for(int i = 0;i<e;i++)
	{
		int x,y;
		cin>>x>>y;
		adj[x].push_back(y);		
	}
	bool vis[n+1] = {false};
	for(int i = 1;i<=n;i++)
	{
		if(!vis[i])
			dfs(adj,i,vis);
	}
}