#include<bits/stdc++.h>
using namespace std;

void buildTree(int* A, int* tree, int start, int end, int node)
{
		if(start==end)
		{
			tree[node]=A[start];
			return;
		}
		else{
			int mid=start + (end-start)/2;
			buildTree(A,tree,start,mid,2*node+1);
			buildTree(A,tree,mid+1,end,2*node+2);
			tree[node]= tree[2*node+1]+tree[2*node+2];
		}
}

void update(int* A,int* tree,int node, int start, int end, int idx, int val)
{
    if(start == end)
    {
        A[idx] += val;
        tree[node] += val;
    }
    else
    {
        int mid = (start + end) / 2;
        if(start <= idx and idx <= mid)
        {
           
            update(A,tree,2*node, start, mid, idx, val);
        }
        else
        {
            
            update(A,tree,2*node+1, mid+1, end, idx, val);
        }
        tree[node] = tree[2*node] + tree[2*node+1];
    }
}

.

int query(int* A, int* tree, int node, int start, int end, int l, int r)
{
    if(r < start or end < l)
    {
        
        return 0;
    }
    if(l <= start and end <= r)
    {
        
        return tree[node];
    }
    int mid = (start + end) / 2;
    int p1 = query(2*node, start, mid, l, r);
    int p2 = query(2*node+1, mid+1, end, l, r);
    return (p1 + p2);
}

int main()
{
	int n;
	cout<<"Enter the size of array needed:-"<<endl;
	cin>>n;
	int a[n];
	int b[4*n];
	for(int i=0;i<4*n;i++)
	{
		b[i]=0;
	}
	cout<<"Enter the array numbers"<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	buildTree(a,b,0,n-1,0);
	for(int i=0;i<4*n;i++)
	{
		cout<<b[i]<<" ";
	}
	return 0;
}