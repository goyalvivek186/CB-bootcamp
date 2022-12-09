#include <iostream>
// #include <vector>
// #include <string>
// #include <algorithm>
#include <queue>
#define ll long long

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

node *build_tree()	//inorder
{
	int d;
	cin >> d;
	if(d == -1)	return NULL;
		
	node *n = new node(d);
	n->left = build_tree();
	n->right = build_tree();
	return n;
}

node *build_tree_level()
{
	int d;
	cin >> d;
	if(d == -1)	return NULL;

	node *root = new node(d);
	queue<node*> q;
	q.push(root);
	while(!q.empty())
	{
		node *f = q.front();
		q.pop();
		cin >> d;	//left
		if(d == -1)
		{
			f->left = NULL;
		}
		else
		{
			f->left = new node(d);
			q.push(f->left);
		}

		cin >> d;	//right
		if(d == -1)
		{
			f->right = NULL;
		}
		else
		{
			f->right = new node(d);
			q.push(f->right);
		}
	}
	return root;
}


void level_order_print(node *root)
{
	queue<node*> q;
	q.push(root);
	q.push(NULL);
	while(!q.empty())
	{
		node *f = q.front();
		q.pop();
		if(f == NULL)
		{
			cout<<endl;
			if(!q.empty())	q.push(NULL);
		}
		else
		{
			cout<<f->data<<" ";
			if(f->left != NULL)
			{
				// cout<<f->left->data;
				q.push(f->left);
			}
			if(f->right != NULL)
			{
				// cout<<f->right->data;
				q.push(f->right);
			}
		}
	}
}

class find_it
{
public:
	bool e1, e2;
	int cnt;
	find_it()
	{
		e1 = e2 = false;
		cnt = 0;
	}
};

find_it dist(node *root, int e1, int e2)
{
	if(root == NULL)
	{
		find_it f;
		return f;
	}

	find_it l = dist(root->left, e1, e2);
	find_it r = dist(root->right, e1, e2);

	find_it x;
	if(root->data == e1)	x.e1 = true;
	if(root->data == e2)	x.e2 = true;
	if(l.e1 and l.e2)	return l;
	if(r.e1 and r.e2)	return r;

	if((l.e1 and r.e2) or (l.e2 and r.e1))
	{
		x.e1 = true;
		x.e2 = true;
		x.cnt++;
	}	
	return x;

}




int main()
{

	// node* root = build_tree();
	node* root = build_tree_level();
	level_order_print(root);
	int e1, e2;	cin >> e1 >> e2;

	find_it x = dist(root, e1, e2);
	cout<<x.cnt<<endl;


	return 0;
}