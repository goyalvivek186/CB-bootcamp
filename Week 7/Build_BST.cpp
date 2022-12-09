#include <iostream>
#include <vector>

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
	vector<int> a(n, 0);
	for(int i = 0; i < n; i++)	cin >> a[i];

	node* root = NULL;
	root = build_tree(a, 0, n-1);
	preorder(root);

}

int32_t main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1;	
	cin >> t;
	while(t--)
	{
		solve();

		cout<<endl;
	}

	return 0;
}