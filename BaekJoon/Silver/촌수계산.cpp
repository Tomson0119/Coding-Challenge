#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int solve(const vector<vector<int>>& graph, int a, int b)
{
	queue<pair<int,int>> que;
	que.push({ a,0 });

	vector<bool> visited(graph.size(), false);
	visited[a] = true;
	while (que.empty() == false)
	{
		int curr = que.front().first;
		int count = que.front().second;
		que.pop();

		if (curr == b)
		{
			return count;
		}

		for (int e : graph[curr])
		{
			if (visited[e] == false)
			{
				visited[e] = true;
				que.push({ e, count + 1 });
			}
		}
	}
	return -1;
}

int main()
{
	int n;
	cin >> n;

	int a, b;
	cin >> a >> b;

	int m;
	cin >> m;

	vector<vector<int>> graph(n + 1);
	for (int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}

	cout << solve(graph, a, b) << "\n";
}