#include<iostream>

using namespace std;

class node
{
public:
	int data;
	node *left;
	node *right;

	node(int d)
	{
		data = d;
		left = NULL;
		right = NULL;
	}
};

node *get_tree()
{
	int d;
	cin >> d;
	if(d == -1)	return NULL;

	node *root = new node(d);
	root->left = get_tree();
	root->right = get_tree();

	return root;
}

void inorder_print(node *root)
{
	if(root == NULL)	return;
	inorder_print(root->left);
	cout<<root->data<<endl;
	inorder_print(root->right);
}


int main()
{
	node *root = get_tree();
	inorder_print(root);




	return 0;
}