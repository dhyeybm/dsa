#include <bits/stdc++.h>
using namespace std;
int v;
int adj[100][100];
void bfs(int s)
{
	queue<int> q;
	char col[v+1];
	int d[v+1],p[v+1];
	for(int i = 1;i<=v;i++)
	{
		p[i] = 0;
		d[i] = INT_MAX;
		col[i] = 'W';
	}
	q.push(s);
	d[s] = 0;
	while(!q.empty())
	{
		int u = q.front();
		q.pop();
		col[u] = 'G';
		for(int j = 1;j<=v;j++)
		{
			if(adj[u][j] == 1 && col[j]=='W')
			{
				col[j] = 'G';
				p[j] = u;
				d[j] = d[u]+1;
				q.push(j);
			}
		}
		col[u] = 'B';
	}
	for(int i = 1;i<=v;i++)
	{
		cout<<d[i]<<' ';
	}
	cout<<endl;
	for(int i = 1;i<=v;i++)
	{
		cout<<col[i]<<' ';
	}
	cout<<endl;
	for(int i = 1;i<=v;i++)
	{
		cout<<p[i]<<' ';
	}
	cout<<endl;
}
int main()
{
	int e;
	cin>>v>>e;
	for(int k = 0;k<e;k++)
	{
		int i,j;
		cin>>i>>j;
		adj[i][j] = adj[j][i] = 1;
	}
	bfs(1);
}
