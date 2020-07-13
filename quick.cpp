#include <bits/stdc++.h>
using namespace std;
void quick(int arr[],int lb,int ub)
{
	if(lb>ub)
		return;
	int i = lb,j = ub+1,item = arr[lb];
	bool flag = true;
	while(flag)
	{
		i++;
		while(arr[i]<item)
			i++;
		j--;
		while(arr[j]>item)
			j--;
		if(i<j)
			swap(arr[i],arr[j]);
		else
			flag = false;
	}
	swap(arr[j],arr[lb]);
	quick(arr,lb,j-1);
	quick(arr,j+1,ub);
}
int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i = 0;i<n;i++)
		cin>>arr[i];
	quick(arr,0,n-1);
	for(int i = 0;i<n;i++)
		cout<<arr[i];
}