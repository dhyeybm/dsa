#include <bits/stdc++.h>
#define int long long
using namespace std;
int inf = INT_MAX;

void dijk(vector<vector<pair<int,int> > > &adj,int source,int ans[])
{
	ans[source] = 0;
	set<pair<int,int> > s;
	s.insert(make_pair(ans[source],source));
	while(!s.empty())
	{
		pair<int,int> p = *(s.begin());
		int d = p.first,curr = p.second;
		s.erase(s.begin());
		for(int i = 0;i<adj[curr].size();i++)
		{
			int v = adj[curr][i].first;
			if(ans[curr]+adj[curr][i].second < ans[v])
			{
				if(ans[v] != inf)
					{
					s.erase(s.find(make_pair(ans[v],v)));
				}
				ans[v] = ans[curr]+adj[curr][i].second;
				s.insert(make_pair(ans[v],v));
			}
		}
	} 
}

int32_t main()
{
	int v,e,x,y,weight;
	cin>>v>>e;
	vector<vector<pair<int,int> > > adj(v+1);
	for(int i = 0;i<e;i++)
	{
		cin>>x>>y>>weight;
		adj[x].push_back(make_pair(y,weight));
		adj[y].push_back(make_pair(x,weight));
	}
	int ans[v+1];
	fill(ans,ans+v+1,inf);
	dijk(adj,1,ans);
	for(int i = 1;i<=v;i++)
	{
		cout<<ans[i]<<' ';
	}
}