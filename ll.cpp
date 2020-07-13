#include<bits/stdc++.h>
using namespace std;
struct node{
	int data;
	node * next;
	node(int k){
		data=k;
		next=NULL;
	}
};
void insert(node* &root, int k){
	node* temp=new node(k);
	if(root==NULL || k<root->data){
		temp->next=root;
		root=temp;
		//cout<<root->data<<endl;
		return;
	}
	
	node* temp2=root;
	while(temp2->next!=NULL && temp->data>temp2->next->data){
		temp2=temp2->next;
	}
	temp->next=temp2->next;
	temp2->next=temp;
}
void show(node* root){
	node* temp=root;
	while(temp){
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<endl;
}
int main(){
	node* root=NULL;
	insert(root, 5);
	insert(root, 3);
	insert(root, 1);
	insert(root, 9);
	insert(root, 11);
	insert(root, 41);
	show(root);
}