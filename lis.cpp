#include <bits/stdc++.h>
#define int long long
using namespace std;
int m = 1000000007;
int dp[2001][2001];

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	int n;
	cin>>n;
	int arr[n];
	for(int i = 0;i<n;i++)
		cin>>arr[i];
	int dp[n];
	memset(dp,-1,sizeof(dp));
	dp[0] = 1;
	for(int i = 1;i<n;i++)
	{
		dp[i] = 1;
		for(int j = i-1;j>=0;j--)
		{
			if(arr[j]<=arr[i])
			{
				dp[i] = max(dp[i],1+dp[j]);
			}
		}
	}
	int mx = 0;
	for(int i = 0;i<n;i++)
		if(dp[i]>mx)
			mx = dp[i];
	cout<<mx<<'\n';
}

