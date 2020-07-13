#include <bits/stdc++.h>
#define int long long
using namespace std;
int mod = 1000000007;
int inf = INT_MAX;

int expmod(int a,int b) {
	if(b == 1) return a;
	if(b == 0) return 1;
	int m1 = expmod(a,b/2)%mod;
	if(b%2) return ((m1*m1)%mod*a%mod)%mod;
	return (m1*m1)%mod;
}
int32_t main()
{
	int a,b;
	cin>>a>>b;
	int ans = expmod(a,b);
	cout<<ans<<'\n';
}