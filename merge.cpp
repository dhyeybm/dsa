#include <bits/stdc++.h>
using namespace std;
void merge(int arr[],int l,int mid,int r)
{
	int sz = r-l+1;
	int i = l,j = mid+1,k = 0,temp[sz] = {0};
	while(i<=mid && j<=r)
	{
		if(arr[i]<arr[j])
		{
			temp[k] = arr[i];
			i++;
		}
		else
		{
			temp[k] = arr[j];
			j++;
		}
		k++;
	}
	while(i<=mid)
	{
		
		temp[k++] = arr[i];
		i++;
	}
	while(j<=r)
	{
		
		temp[k++] = arr[j];
		j++;
	}
	for(i = 0;i<sz;i++)
	{
		arr[l+i] = temp[i];
	}
}
void mergesort(int arr[],int l,int r)
{
	if(r-l+1 <= 1)
		return;
	int mid = l+(r-l)/2;
	mergesort(arr,l,mid);
	mergesort(arr,mid+1,r);
	merge(arr,l,mid,r);
}
int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i = 0;i<n;i++)
		cin>>arr[i];
	mergesort(arr,0,n-1);
	for(int i = 0;i<n;i++)
		cout<<arr[i]<<' ';		
	
}