#include <bits/stdc++.h>
#define int long long
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define vi vector<int>
#define vvi vector<vector<int> >
#define mii map<int,int>
#define pb push_back
#define pii pair<int,int>
#define mkp make_pair
#define scan(a,n) for(int i =0 ; i<n ; i++) cin>>a[i]
#define print(a,n) for(int i = 0 ; i < n ; i++) {cout<<a[i]<<' ';}cout<<'\n'
#define mem(a,v) memset(a,v,sizeof(a))
#define loop(i,n) for (int i = 0; i < n; i++)
#define loop1(i,n) for (int i = 1; i < n; i++)
#define FastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define PRECISION std::cout.unsetf ( std::ios::floatfield );std::cout.precision(15)
#define PI 3.14159265
#define S second
#define F first
#define CHECK cout<<"CHEDEDWB"<<endl
using namespace std;
int mod = 1e9;
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
void calc(string &str,int &i,int &tempx,int &tempy)
{
	while(str[i] != ')')
	{
		if(str[i] == 'S')
		{
			tempx = (tempx+1)%mod;
		}
		else if(str[i] == 'N')
		{
			tempx = (tempx+mod-1)%mod;
		}
		else if(str[i] == 'E')
			tempy = (tempy+1)%mod;
		else if(str[i] == 'W')
			tempy = (tempy+mod-1)%mod;
		else
		{
			int num = str[i]-'0';
			i = i+2;
			int tx = 0,ty = 0;
			calc(str,i,tx,ty);
			tempx =(tempx+(((num%mod)*tx)%mod)+mod)%mod;
			tempy =(tempy+(((num%mod)*ty)%mod)+mod)%mod;
		}
		i++;
	}

}
int32_t main() 
{
	FastIO; PRECISION;
	int t = 1;
	cin>>t;
	cout<<(pow(1.01,3700))<<endl;
}