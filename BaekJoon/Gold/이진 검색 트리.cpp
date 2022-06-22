#include <iostream>
#include <map>

using namespace std;

struct Node
{
	int left;
	int right;

	Node()
		: left(0), right(0)
	{
	}
};

void insert(map<int, Node>& tree, int val, int root)
{
	if (root == 0) return;
	if (root > val)
	{
		if (tree[root].left == 0)
		{
			tree[root].left = val;
			tree[val] = Node();
			return;
		}
		insert(tree, val, tree[root].left);
	}
	else
	{
		if (tree[root].right == 0)
		{
			tree[root].right = val;
			tree[val] = Node();
			return;
		}
		insert(tree, val, tree[root].right);
	}
}

void postorder(map<int, Node>& tree, int root)
{
	if (root > 0)
	{
		postorder(tree, tree[root].left);
		postorder(tree, tree[root].right);
		cout << root << "\n";
	}
}

int main()
{
	map<int, Node> tree;
	
	int root = 0;
	int max_n = 0;
	int prev = 0;
	int n;
	while (cin >> n)
	{
		if (root == 0) {
			root = n;
			prev = n;
			max_n = n;
			tree[n] = Node();
			continue;
		}
		
		if (prev > n)
		{
			tree[prev].left = n;
			tree[n] = Node();
			prev = n;
			max_n = (max_n < n) ? n : max_n;
			continue;
		}

		if (max_n < n)
		{
			tree[max_n].right = n;
			tree[n] = Node();
			prev = n;
			max_n = n;
			continue;
		}

		insert(tree, n, root);
		prev = n;
		max_n = (max_n < n) ? n : max_n;
	}
	postorder(tree, root);
}