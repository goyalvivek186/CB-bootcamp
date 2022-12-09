#include <iostream>
#include <vector>
#include <string>

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

node* build_tree(vector<int> &a, int s, int e)
{
	if(s > e)	return NULL;
	int i = (s+e)/2;
	node* n = new node(a[i]);
	n->left = build_tree(a, s, i-1);
	n->right = build_tree(a, i+1, e);

	return n;
}

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

void replace(node* root, int &s)
{
	if(root == NULL)	return;
	replace(root->right, s);
	root->data += s;
	s = root->data;
	replace(root->left, s);
}

void preorder(node* root)
{
	if(root == NULL)	return;
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}

int main()
{
	int n;
	cin >> n;
	node* root = NULL;
	vector<int> a(n, 0);
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	root = build_tree(a, 0, n-1);
	int s = 0;
	replace(root, s);
	preorder(root);
	
	return 0;
}