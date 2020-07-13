// Problem : D. Monopole Magnets
// Contest : Codeforces - Codeforces Round #639 (Div. 2)
// URL : https://codeforces.com/contest/1345/problem/D
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
#define int long long
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define vi vector<int>
#define vstr vector<string>
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
#define FastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define PRECISION std::cout.unsetf ( std::ios::fixed );std::cout.precision(9)
#define PI 3.14159265
#define S second
#define F first
#define CHECK cout<<"CHEDEDWB"<<endl
#define br '\n'
using namespace std;
int mod = 1e9+7;
int inf = 1e18;
int m_inf = INT_MIN;
// int extendedgcd(int a,int b,int &x,int &y){
// 	if(a == 0){
// 		x = 0; y = 1;
// 		return b;
// 	}
// 	int x1,y1;
// 	int d = extendedgcd(b%a,a,x1,y1);
// 	x = y1 - (b/a)*x1;y = x1;
// 	return d;
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
// vector<int> sieve(int n)
// {
// 	vector<int> primes;
// 	bool isPrime[n+1] = {false};
// 	isPrime[1] = isPrime[0] = false;
// 	for(int i = 2;i<=n;i++)
// 	{
// 		isPrime[i] = true;
// 	}
// 	for(int i = 2;i*i<=n;i++)
// 	{
// 		if(isPrime[i])
// 		{
// 			for(int j = i*i;j<=n;j+=i)
// 			{
// 				isPrime[j] = false;
// 			}
// 		}
// 	}
// 	for(int i = 2;i<=n;i++)
// 	{
// 		if(isPrime[i])
// 		{
// 			primes.push_back(i);
// 		}
// 	}
// 	return primes;
// }
// vector<int> segsieve(int l,int r,vector<int> primes)
// {
// 	vector<int> result;
// 	bool isPrime[r-l+1];
// 	for(int i = 0;i<r-l+1;i++)
// 		isPrime[i] = true;
// 	for(int i = 0;primes[i]*primes[i]<=r;i++)
// 	{
// 		int base = (l/primes[i])*primes[i];
// 		if(base<l)
// 			base = base+primes[i];
// 		if(base == primes[i])
// 			base = base+primes[i];
// 		for(int j = base;j<=r;j+=primes[i])
// 			isPrime[j-l] = false;
// 	}
// 	for(int i = 0;i<r-l+1;i++)
// 		if(isPrime[i])
// 			result.push_back(l+i);
// 	return result;
// }
// void dfs(vector<vector<int> > &adj,int root,bool vis[])
// {
// 	vis[root] = true;
// 	for(int i = 0;i<adj[root].size();i++){
// 		int v = adj[root][i];
// 		if(!vis[v])		
// 			dfs(adj,v,vis);
// 	}
// }
// int match(string str,string pattern)
// {
// 	int m = pattern.size();
// 	int n = str.size();
// 	int pi[m];
// 	int j = 0;
// 	pi[0] = 0;

// 	for(int i = 1;i<m;i++)
// 	{
// 		if(pattern[i] == pattern[j])
// 		{
// 			j++;
// 			pi[i] = j;
// 		}
// 		else
// 		{
// 			if(j != 0)
// 			{
// 				i--;
// 				j = pi[j-1];
// 			}
// 			else
// 				pi[i] = 0;
// 		}
// 	}
// 	j = 0;
// 	int i = 0;
// 	while(i<n && j<m)
// 	{
// 		if(pattern[j] == str[i])
// 		{
// 			j++;
// 			i++;
// 		}
// 		else
// 			if(j == 0)
// 				i++;
// 			else
// 				j = pi[j-1];
// 	}
// 	if(j == m)
// 		return i-m;
// 	else
// 		return -1;
// }
bool vis[1001][1001];
char arr[1001][1001];
int n,m;
void dfs(int x,int y)
{
	vis[x][y] = 1;
	if(x > 0 && !vis[x-1][y] && arr[x-1][y] == '#')
		dfs(x-1,y);
	if(y > 0 && !vis[x][y-1] &&  arr[x][y-1] == '#')
		dfs(x,y-1);
	if(x < n-1 && !vis[x+1][y] && arr[x+1][y] == '#')
		dfs(x+1,y);
	if(y < m-1 && !vis[x][y+1] && arr[x][y+1] == '#')
		dfs(x,y+1);

}
int32_t main() 
{
	FastIO; PRECISION;
	int t = 1;
	// cin>>t;
	while(t--)
	{
		cin>>n>>m;

		loop(i,0,n)
			loop(j,0,m)
				cin>>arr[i][j];
		bool flag = true;
		bool flag2 = true;
		bool temp = false;
		loop(i,0,n)
		{
			int r = -1;
			loop(j,0,m)
			{
				if(arr[i][j] == '#'){
					if(r == -1 ||r == j-1)
					{
						r = j;
						
					}
					else
					{
						flag = false;
						break;
					}
				}
			}
			if(r == -1)
			{
				temp = true;
			}
			if(!flag)
				break;
		}
		if(!flag)
		{
			cout<<-1<<'\n';
			continue;
		}
		flag2 = 1;
		bool temp2 = false;
		loop(j,0,m)
		{
			int c = -1;
			loop(i,0,n)
			{
				if(arr[i][j] == '#')
				{
					if(c == -1||c == i-1)
					{
						c = i;						
					}
					else
					{
						flag = false;
						break;
					}
				}
			}
			if(c == -1)
			{
				temp2 = 1;
			}
			if(!flag)
				break;
		}
		if(temp2^temp == 1)
		{
			flag = false;
		}
		if(!flag)
		{
			cout<<-1<<'\n';
			continue;
		}
		mem(vis,0);
		int count = 0;
		loop(i,0,n)
		{
			loop(j,0,m)
			{
				if(!vis[i][j] && arr[i][j] == '#')
				{
					count++;
					dfs(i,j);
				}
			}
		}
		cout<<count<<'\n';		
	}
}