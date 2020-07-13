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
void display(node* root)
{
	if(root == NULL)
		return ;
	
	
	cout<<root->data<<' ';
	display(root->left);
	display(root->right);
}

void denode(node* &root,int n)
{
    if(root == NULL)
        return;
    if(n < root->data)
    {
        denode(root->left,n);
    }
    else if(n > root->data)
    {
        denode(root->right,n);
    }
    else
    {
        if(root->left == NULL && root->right ==NULL)
        {
            delete root;
            root = NULL;
        }
        else if(root->left == NULL)
        {
           node* nn = root->right;
           delete root;
           root = nn;
        }
        else if(root->right == NULL)
        {
           node* nn = root->left;
           delete root;
           root = nn;
        }
        else
        {
            node* n = root->right;
            while(n->left != NULL)
            {
            	n = n->left;
            }
            root->data = n->data;
            denode(root->right,root->data);
        }
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
	display(root);
	cout<<endl;
	denode(root,1);
	display(root);
    cout<<endl;
}