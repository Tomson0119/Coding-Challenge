#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode
{
	pair<int,int> parent;
	vector<pair<int,int>> children;

	TreeNode(int n, int w) { parent = { n,w }; }
};

void BFS(int start, const vector<TreeNode>& tree, vector<int>& distances)
{
	vector<int> visited(tree.size(), false);
	visited[start] = true;

	queue<pair<int,int>> que;
	que.push({ start,0 });

	while (que.empty() == false)
	{
		int curr = que.front().first;
		int dist = que.front().second;
		que.pop();

		distances[curr] = dist;

		const pair<int, int>& parent = tree[curr].parent;
		if (parent.first > 0 && visited[parent.first]==false)
		{
			visited[parent.first] = true;
			que.push({ parent.first, parent.second + dist });
		}
		for (const pair<int,int>& child : tree[curr].children)
		{
			if (visited[child.first] == false)
			{
				visited[child.first] = true;
				que.push({ child.first, child.second + dist });
			}
		}
	}
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
	int n;
	cin >> n;

	vector<TreeNode> tree(n + 1, TreeNode(-1, -1));
	for (int i = 0; i < n-1; i++)
	{
		int s, e, w;
		cin >> s >> e >> w;
		tree[s].children.push_back({e,w});
		tree[e].parent = { s,w };
	}

	vector<int> nodes;
	for (int i = 1; i <= n; i++)
	{
		if (tree[i].children.size() == 0 || tree[i].parent.first < 0)
			nodes.push_back(i);
	}

	int max_val = 0;
	for (int i = 0; i < nodes.size(); i++)
	{
		vector<int> distances(tree.size(), -1);
		BFS(nodes[i], tree, distances);
		for (int j = i + 1; j < nodes.size(); j++)
		{
			max_val = max(max_val, distances[nodes[j]]);
		}
	}
	cout << max_val << "\n";
}