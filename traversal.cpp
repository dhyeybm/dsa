#include <bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	node *left,*right;
};

node* insert(node* root,int n)
{
	if(root == NULL)
	{
		node* temp = new node();
		temp->left = NULL;
		temp->right = NULL;
		temp->data = n;
		return temp;
	}
	if(n<root->data)
		root->left = insert(root->left,n);
	else
		root->right = insert(root->right,n);
	return root;
}
void preorder(node* root)
{
	stack<node*> s;
	s.push(NULL);	
	while(root)
	{
		cout<<root->data<<' ';
		if(root->right)
			s.push(root->right);
		if(root->left != NULL)
			root = root->left;
		else
		{
			root = s.top();
			s.pop();
		}
	}
}
void inorder(node* root)
{
	stack<node*> s;
	node* temp  = root;

	while(temp || !s.empty())
	{
		while(temp)
		{
			s.push(temp);
			temp = temp->left;
		}
		temp = s.top();
		s.pop();
		cout<<temp->data<<' ';
		temp = temp->right;	
	}	
}
void postorder(node* root)
{
	stack <node*> s1,s2;
	node* temp = root;
	s1.push(temp);
	while(!s1.empty())
	{
		node* nn = s1.top();
		s1.pop();
		if(nn->left)
			s1.push(nn->left);
		if(nn->right)	
			s1.push(nn->right);
		s2.push(nn);
	}
	while(!s2.empty())
	{
		node* nn = s2.top();
		s2.pop();
		cout<<nn->data<<' ';
	}
}
int main()
{
	node* root = NULL;
	root = insert(root,4);
	root = insert(root,2);
	root = insert(root,1);
	root = insert(root,3);
	root = insert(root,6);
	root = insert(root,5);
	root = insert(root,7);
	//preorder(root);
	cout<<endl;
	inorder(root);
	postorder(root);
}