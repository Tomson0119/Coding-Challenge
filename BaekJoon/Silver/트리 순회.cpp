#include <iostream>
#include <vector>

using namespace std;

void preorder(const vector<vector<int>>& tree, int num)
{
	cout << (char)(num + 'A');
	if(tree[num][0] + 'A' != '.') preorder(tree, tree[num][0]);
	if(tree[num][1] + 'A' != '.') preorder(tree, tree[num][1]);
}

void inorder(const vector<vector<int>>& tree, int num)
{
	if (tree[num][0] + 'A' != '.') inorder(tree, tree[num][0]);
	cout << (char)(num + 'A');
	if (tree[num][1] + 'A' != '.') inorder(tree, tree[num][1]);
}

void postorder(const vector<vector<int>>& tree, int num)
{
	if (tree[num][0] + 'A' != '.') postorder(tree, tree[num][0]);
	if (tree[num][1] + 'A' != '.') postorder(tree, tree[num][1]);
	cout << (char)(num + 'A');
}

int main()
{
	int n;
	cin >> n;

	vector<vector<int>> tree(n);
	for (int i = 0; i < n; i++)
	{
		char parent, child1, child2;
		cin >> parent >> child1 >> child2;
		tree[parent - 'A'].push_back(child1 - 'A');
		tree[parent - 'A'].push_back(child2 - 'A');
	}

	preorder(tree,0);
	cout << "\n";

	inorder(tree,0);
	cout << "\n";

	postorder(tree,0);
	cout << "\n";
}