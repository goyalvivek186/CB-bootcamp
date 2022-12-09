#include <iostream>
#include <vector>
#include <string>
// #include <algorithm>
// #include <climits>

#define ll long long

using namespace std;

class node
{
public:
	int data;
	node* right;
	node* left;
	node(int d)
	{
		data = d;
		right = left = NULL;
	}
};

node* insert(node* root, int d)
{
	if(root == NULL)
	{
		node* n = new node(d);
		return n;
	}
	if(root->data > d)
	{
		root->left = insert(root->left, d);
	}
	else
	{
		root->right = insert(root->right, d);
	}
    return root;
}

node* delete_BST(node* root, int d)
{
	if(root == NULL)	return NULL;
	if(root->data > d)	root->left = delete_BST(root->left, d);
	else if(root->data < d)	root->right = delete_BST(root->right, d);
	else if(root->data == d)
	{
		//0 child
		if(root->right == NULL and root->left == NULL)
		{
			// delete root;
			return NULL;
		}

		//1 child
		if(root->right == NULL and root->left != NULL)
		{
			return root->left;
		}
		if(root->right != NULL and root->left == NULL)
		{
			return root->right;
		}

		//2 child
		if(root->left != NULL and root->right != NULL)
		{
			node*n = root;
			n = n->right;
			while(n->left != NULL)	n = n->left;
			int x = n->data;
			delete_BST(n, x);
			root->data = x;
			return root;
		}
	}
    return root;
}

void preorder(node* root)
{
	if(root == NULL)	return;
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}

void solve()
{
	int n;
	cin >> n;
	node* root = NULL;
	for(int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		root = insert(root, x);
	}
	cin >> n;
	vector<int> a(n, 0);
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	for(int i = 0; i < n; i++)
	{
		root = delete_BST(root, a[i]);
	}
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		solve();
		cout<<endl;
	}
	
	return 0;
}