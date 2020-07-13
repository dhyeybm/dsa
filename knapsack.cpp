#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	ll n,w;
	cin>>n>>w;
	ll weight[n+1],val[n+1];
	for(int i = 1;i<=n;i++)
	{
		cin>>weight[i]>>val[i];
	}
	ll dp[n+1][w+1] = {0};
	for(int i = 0;i<=n;i++)
	{
		for(int j = 0;j<=w;j++)
		{
			if(i == 0 || j == 0)
				dp[i][j] = 0;
			else if(weight[i] <= j)
			{
				dp[i][j] = max(dp[i-1][j],val[i]+dp[i-1][j-weight[i]]);
			}
			else
				dp[i][j] = dp[i-1][j];
		}
	}
	cout<<dp[n][w]<<'\n';
}