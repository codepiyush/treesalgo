#include<bits/stdc++.h>
using namespace std;
struct interval{
	int l;
	int h;
};
class node{
public:
	interval* n;
	int max;
	node* right;
	node* left;
	node(interval a){
		this->n = new interval(a);
		this->right=NULL;
		this->left=NULL;
		this->max=0;
	}
};
class int_tree{
public:
	node* root;
	int_tree(){
		this->root=NULL;
	}
};

node *insert(node* root, interval a)
{
	if(root==NULL)
	{
		node* newnode= new node(a);
		root=newnode;
	}

	else if(a.l<=root->n->l)
	{
		root->left=insert(root->left, a);
	}
	else{
		root->right= insert(root->right, a);
	}
	if(root->max<a.h)
	{
		root->max=a.h;
	}
	return root;
}

void inorder(node *root)
{
	if(root==NULL)
	{
		return;
	}
	inorder(root->left);
	cout<<"[ "<<root->n->l<<" , "<<root->n->h<<" ] max for sub tree:- "<<root->max<<endl;
	inorder(root->right); 
}

bool doOverlaP(interval* i1, interval i2)
{
	if(i1->l<=i2.h && i2.h>=i1->l)
		return true;
	return false;
}

interval *overlapSearch(node* root, interval i)
{
	if(root==NULL) return NULL;
	else if(doOverlaP(root->n, i))
		return root->n;
	if(root->left!=NULL && root->left->max>=i.l)
		return overlapSearch(root->left, i);
	return overlapSearch(root->right, i);
}

/*main part*/
int main()
{
	int n;
	interval a;
	int_tree* tree = new int_tree();
	cout<<"Enter the number of intervals:- "<<endl;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cout<< "Enter low value:- "<<endl;
		cin>>a.l;
		cout<<"Enter high vlaue:- "<<endl;
		cin>>a.h;
		tree->root=insert(tree->root,a);
	}
	inorder(tree->root);

	cout<<"Enter no. of searches you want to perform:- "<<endl;
	cin>>n;
	for(int i=0;i<n;i++)
	{
	cout<<"Enter the interval you want to search: -"<<endl;
	cout<<"low:- ";
	cin>>a.l;
	cout<<"\n high:- ";
	cin>>a.h;
	interval* b= overlapSearch(tree->root, a);
	cout<<"\n[ "<<b->l<<" , "<<b->h<<" ]"; 
	}
}