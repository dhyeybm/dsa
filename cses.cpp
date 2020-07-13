

// Problem : Coin Combinations II
// Contest : CSES - CSES Problem Set
// URL : https://cses.fi/problemset/task/1636
// Memory Limit : 512 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
#define int long long
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define vi vector<int>
#define vstr vector<string>
#define vdb vector<double>
#define vbool vector<bool>
#define vvi vector<vector<int> >
#define mii map<int,int>
#define pb push_back
#define pii pair<int,int>
#define vpair vector<pii > 
#define mkp make_pair
#define scan(a,n) for(int i =0 ; i<n ; i++) cin>>a[i]
#define print(a,n) for(int i = 0 ; i < n ; i++) {cout<<a[i]<<' ';}cout<<'\n'
#define mem(a,v) memset(a,v,sizeof(a))
#define loop(i,a,b) for (int i = a; i < b; i++)
#define loope(i,a,b) for (int i = a; i <= b; i++)
#define bloop(i,a,b) for(int i = a;i>=b;i--)
#define FastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define PRECISION std::cout.unsetf ( std::ios::fixed );std::cout.precision(9)
#define PI 3.14159265
#define S second
#define F first
#define CHECK cout<<"CHEDEDWB"<<endl
#define CHECK1(a) cout<<a<<endl
#define CHECK2(a,b) cout<<a<<' '<<b<<endl;
#define br '\n'
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(),x.end()
using namespace std;
int mod = 1e9+7;
int inf = 1e18;
int m_inf = INT_MIN;
// int extendedgcd(int a,int b,int &x,int &y){
	// if(a == 0){
		// x = 0; y = 1;
		// return b;
	// }
	// int x1,y1;
	// int d = extendedgcd(b%a,a,x1,y1);
	// x = y1 - (b/a)*x1;y = x1;
	// return d;
// }
// int expmod(int a,int b) {
// 	if(b == 1) return a;
// 	if(b == 0) return 1;
// 	int m1 = expmod(a,b/2)%mod;
// 	if(b%2) return ((m1*m1)%mod*a%mod)%mod;
// 	return (m1*m1)%mod;
// }
// int power(int a,int b) {
// 	if(b == 1) return a;
// 	if(b == 0) return 1;
// 	int m1 = power(a,b/2);
// 	if(b%2) return m1*m1*a;
// 	return m1*m1;
// }
// int logn(int n, int r) 
// { 
//     return (n > r - 1) ? 1 + logn(n / r, r) : 0; 
// } 

// int nCr(int n,int r)
// {
	// r = min(r,n-r);
	// if(r<0)
		// return 0;
	// if(r == 0)
		// return 1;
	// int ans = 1;
	// for(int i = 1;i<=r;i++)
	// {
		// ans = ans*(n-i+1)/i;
	// }
	// return ans;
// 		
// }
// vi factmod(int n)
// {
	// vi ans(n+1);
	// ans[0] = 1;
	// loop(i,1,n+1)
	// {
		// ans[i] = (ans[i-1]*i)%mod;
	// }
	// return ans;
// }
// int nCrmod(int n,int r,vi &fact)
// {
	// int x1,y1;
	// extendedgcd(fact[r],mod,x1,y1);
	// int x2,y2;
	// extendedgcd(fact[n-r],mod,x2,y2);
	// int ans = (fact[n]*((x1+mod)%mod))%mod;
	// ans = (ans*((x2+mod)%mod))%mod;
	// return ans;
// }

// void dfs(vector<vector<int> > &adj,int root,vbool &vis)
// {
// 	vis[root] = true;
// 	for(int i = 0;i<adj[root].size();i++){
// 		int v = adj[root][i];
// 		if(!vis[v])		
// 			dfs(adj,v,vis);
// 	}
// }

int32_t main() 
{
	FastIO; PRECISION;
	int t = 1;
	// cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vi arr(n);
		scan(arr,n);
		int mn = inf;
		loop(i,0,1<<n)
		{
			int a = 0,b = 0;
			for(int j = 0;j<n;j++)
			{
				if(((1<<j)&i) == 0)
					a+=arr[j];
				else
					b+=arr[j];
			}
			mn = min(mn,abs(b-a));			
		}
		cout<<mn<<'\n';
	}
}