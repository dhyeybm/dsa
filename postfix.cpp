#include <bits/stdc++.h>
using namespace std;
int n = 100;
void push(char s[],int &top,char ch)
{
	if(top == n-1)
	{
		cout<<"Overflow"<<endl;
		return;
	}
	s[++top] = ch;

}
char pop(char s[],int &top)
{
	if(top == -1){
		cout<<"Underflow"<<endl;
		return 0;
	}
	return s[top--];
}
int f(char ch)
{
	if(ch == '+'|| ch =='-')
		return 1;
	if(ch == '*' || ch=='/')
		return 2;
	if(ch=='(')
		return 0;
	if(ch == '#')
		return -1;

	return 3;
}
int r(char ch)
{
	if(ch == '+'||ch == '-'||ch == '/'||ch == '*')
		return -1;
	if(ch=='('||ch==')')
		return 0;
	return 1;
}

int main()
{
	string str;
	cin>>str;
	string postfix;
	int rank = 0;
	char s[n];
	int top = 0;
	s[0] = '#';
	for(int i = 0;i<str.size();i++)
	{
		char next = str[i];
		cout<<postfix<<' '<<s[top]<<endl;

		if(next == '(')
		{
			push(s,top,next);
			continue;
		}
		if(next == ')')
		{
			while(s[top] != '(')
			{
				char ch = pop(s,top);
				if(ch == 0)
				{
					cout<<"Invalid"<<endl;
					return 0;
				}
				postfix+=ch;
				rank+=r(ch);
				if(rank<0)
				{
					cout<<"Invalid\n";
					return 0;
				}
			}
			pop(s,top);
			continue;

		}
		while(f(next)<=f(s[top]))
		{
			char op = pop(s,top);
			postfix=postfix+op;
			rank+=r(op);
		}
		push(s,top,next);
	}
	while(s[top]!='#')
	{
		char temp = pop(s,top);
		postfix+=temp;
		rank+=r(temp);
	}
	//cout<<rank<<endl;
	if(rank==1)
		cout<<postfix<<endl;
	else
		cout<<"INVALID\n";
}
