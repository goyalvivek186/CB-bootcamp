#include <iostream>
#include <vector>
#include <climits>
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

bool count(node* root, int p, int q, int &ans)
{
	if(root == NULL)	return true ;
	bool l = count(root->left, p, q, ans);
	bool r = count(root->right, p, q, ans);
	if(l and r and root->data >= p and root->data <= q)
	{
		ans++;
		return true;
	}
	else
	{
		return false;
	}

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
	int ans = 0;
	int p, q;
	cin >> p >> q;
	count(root, p, q, ans);
	cout<<ans;
	return 0;
}