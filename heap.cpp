#include <bits/stdc++.h>
using namespace std;

void join(int arr[],int i,int n)
{
	int j = 2*i;
	while(j<=n)
	{
		if(j<n && arr[j+1]>arr[j])
			j++;
		if(arr[j/2]<arr[j])
			swap(arr[j],arr[j/2]);
		else 
			break;
		j = 2*j;
	}
}
void heapify(int arr[],int n)
{
	for(int i = n/2;i>0;i--)
	{
		join(arr,i,n);
	}
}
void heapsort(int arr[],int n)
{
	heapify(arr,n);
	while(n>1)
	{
		swap(arr[1],arr[n--]);
		join(arr,1,n);
	}
}
int main()
{
	int n;
	cin>>n;
	int arr[n+1];
	for(int i = 1;i<=n;i++)
		cin>>arr[i];
	heapsort(arr,n);
	for(int i = 1;i<=n;i++)
		cout<<arr[i]<<' ';

}