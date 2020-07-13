#include <bits/stdc++.h>
using namespace std;

int match(string str,string pattern)
{
	int m = pattern.size();
	int n = str.size();
	int pi[m];
	int j = 0;
	pi[0] = 0;

	for(int i = 1;i<m;i++)
	{
		if(pattern[i] == pattern[j])
		{
			j++;
			pi[i] = j;
		}
		else
		{
			if(j != 0)
			{
				i--;
				j = pi[j-1];
			}
			else
			{
				pi[i] = 0;
			}
		}
	}
	
	j = 0;
	int i = 0;
	while(i<n && j<m)
	{
		if(pattern[j] == str[i])
		{
			j++;
			i++;
		}
		else
		{
			if(j == 0)
			{
				i++;
			}
			else
				j = pi[j-1];
		}
	}
	if(j == m)
	{
		return i-m;
	}
	else
	{
		return -1;
	}
}
void find(string str)
{
	cout<<str;
}

int main()
{
	string str;
	string pattern;
	cin>>str>>pattern;
	int ans = match(str, pattern);
	if(ans == -1)
	{
		cout<<"Pattern not found"<<endl;
	}
	else
	{
		cout<<"Pttern found at index "<<ans<<endl;
	}

}