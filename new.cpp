#include <bits/stdc++.h>
using namespace std;

void adjust(int* arr,int i,int  n)
{
	int j=2*i;
	if(j<n && arr[j]<arr[j+1])
	{
		j++;
	}	
	if(arr[i]<arr[j])
	{
		swap(arr[i],arr[j]);
	}
}

void heapify(int* arr,int n)
{
	for(int i=n/2;i>=1;i--)
	{
		adjust(arr,i,n);
	}
}
void heapsort(int* arr,int n)
{
	heapify(arr,n);
	for(int i=n;i>=1;i--)
	{
		swap(arr[1],arr[i]);
		heapify(arr,--n);
	}
}
int main()
{
	int n;
	cin>>n;
	int arr[n+1];
	for(int i=1;i<n+1;i++)
	{
		cin>>arr[i];
	}
	heapsort(arr,n);
	for(int i=1;i<n+1;i++)
	{
		cout<<arr[i]<<" ";
	}
}
