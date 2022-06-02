#include <iostream>
#include <vector>
#include <stack>

using namespace std;

pair<int,int> DFS(const vector<vector<pair<int, int>>>& graph, int start)
{
	stack<pair<int, int>> stk;
	stk.push({ start, 0 });

	vector<bool> visited(graph.size(), false);
	visited[start] = true;

	int longest_node = -1;
	int max_dist = -1;
	while (stk.empty() == false)
	{
		int curr = stk.top().first;
		int dist = stk.top().second;
		stk.pop();

		if (max_dist < dist)
		{
			max_dist = dist;
			longest_node = curr;
		}

		for (const auto& p : graph[curr])
		{
			if (visited[p.first] == false)
			{
				visited[p.first] = true;
				stk.push({ p.first, dist + p.second });
			}
		}
	}
	return { longest_node, max_dist };
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	vector<vector<pair<int, int>>> graph(n + 1);
	for (int i = 0; i < n; i++)
	{
		int from;
		cin >> from;

		while (true)
		{
			int to, weight;
			cin >> to;

			if (to == -1) break;
			cin >> weight;

			graph[from].push_back({ to, weight });
		}
	}

	auto p = DFS(graph, 1);
	p = DFS(graph, p.first);
	cout << p.second << "\n";
}