#include <bits/stdc++.h>
using namespace std;
int n = 5;
void push(int q[],int &f,int &r,int num)
{
	int f1 = f;
	if(f == n-1)
		f = 0;
	else
		f = f+1;
	if(f == r)
	{
		cout<<"Overflow"<<endl;
		f = f1;
		return;
	}
	if(r == -1)
		r = f;
	q[f] = num;
}
int pop(int q[],int &f,int &r)
{
	if(f == -1)
	{
		cout<<"Underflow"<<endl;
		return -1;
	}
	int item = q[r];
	if(r == n-1)
		r = 1;
	else
		r = r+1;
	if(f == r)
	{
		f = r = -1;
	}
	return item;
}
int main()
{
	int q[n];
	int r = -1,f = -1;
	push(q,r,f,1);
	push(q,r,f,2);
	push(q,r,f,3);
	push(q,r,f,4);
	push(q,r,f,5);
	push(q,r,f,6);
	cout<<pop(q,r,f)<<endl;
	cout<<pop(q,r,f)<<endl;
	push(q,r,f,9);

}