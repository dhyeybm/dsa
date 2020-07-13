#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector<ll> sieve(ll n)
{
	vector<ll> primes;
	bool isPrime[n+1] = {false};
	isPrime[1] = isPrime[0] = false;
	for(ll i = 2;i<=n;i++)
	{
		isPrime[i] = true;
	}
	for(ll i = 2;i*i<=n;i++)
	{
		if(isPrime[i])
		{
			for(ll j = i*i;j<=n;j+=i)
			{
				isPrime[j] = false;
			}
		}
	}
	for(ll i = 2;i<=n;i++)
	{
		if(isPrime[i])
		{
			primes.push_back(i);
		}
	}
	return primes;
}
vector<ll> segsieve(ll l,ll r,vector<ll> primes)
{
	vector<ll> result;
	bool isPrime[r-l+1];
	for(int i = 0;i<r-l+1;i++)
		isPrime[i] = true;
	for(ll i = 0;primes[i]*primes[i]<=r;i++)
	{
		
		ll base = (l/primes[i])*primes[i];
		if(base<l)
			base = base+primes[i];
		if(base == primes[i])
			base = base+primes[i];

		for(ll j = base;j<=r;j+=primes[i])
		{
			isPrime[j-l] = false;
		}
		
	}
	for(int i = 0;i<r-l+1;i++)
	{
		if(isPrime[i])
			result.push_back(l+i);
	}
	return result;
}
int main()
{
	vector<ll> primes = sieve(1000000);
	int t;
	cin>>t;
	while(t--)
	{
		ll r,l;
		cin>>l>>r;
		vector<ll> pr2 = segsieve(l,r,primes);
		for(int i = 0;i<pr2.size();i++)
			cout<<pr2[i]<<' ';
		cout<<endl;
	}
}