#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	string s,t;
	cin>>s>>t;
	int a = s.length();
	int b = t.length();
	int dp[a+1][b+1];
	for(int i = 0;i<=a;i++)
		dp[i][0] = 0;
	for(int j = 0;j<=b;j++)
		dp[0][j] = 0;
	for(int i = 1;i<=a;i++)
	{
		for(int j = 1;j<=b;j++)
		{
			if(s[i-1] == t[j-1])
			{
				dp[i][j] = dp[i-1][j-1]+1;
			}
			else
				dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
		}
	}
	int i = a,j = b;
	string ans;
	while(i>0 && j>0)
	{
		if(dp[i][j] == dp[i-1][j])
			i--;
		else if(dp[i][j] == dp[i][j-1])
			j--;
		else
		{
			ans+=s[i-1];
			i--;
			j--;
		}
	}
	reverse(ans.begin(),ans.end());
	cout<<ans;

}
