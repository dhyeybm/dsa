#include <bits/stdc++.h>
using namespace std;
int main()
{
	fstream file("number.txt",ios::in|ios::out);
	int n;
	cin>>n;
	float str;
	for(int i = 0;i<n;i++)
	{
		cin>>str;
		file<<str<<'\n';
	}
	file.clear();
	file.seekg(0,ios::beg);
	float str2;
	for(int i = 0;i<n;i++)
	{
		file>>str2;
		cout<<str2<<endl;
	}	

}