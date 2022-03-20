#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void DFS(int start, const vector<vector<int>>& graph, vector<bool>& visited)
{
	stack<int> stk;
	stk.push(start);

	while (stk.empty() == false)
	{
		int curr = stk.top();
		stk.pop();

		if (visited[curr] == true) continue;
		visited[curr] = true;

		for (int e : graph[curr])
			stk.push(e);
	}
}

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	vector<vector<int>> graph(n + 1);
	vector<bool> visited(n + 1, false);

	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;

		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	int count = 0;
	for (int i = 1; i <= n; i++)
	{
		if (visited[i] == false)
		{
			DFS(i, graph, visited);
			count += 1;
		}
	}
	cout << count << "\n";
}