#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <unordered_set>

using namespace std;

void DFS(const vector<vector<int>>& graph, int start)
{
	stack<int> stk;
	stk.push(start);

	unordered_set<int> visited;

	while (stk.empty() == false)
	{
		int num = stk.top();
		stk.pop();

		if (visited.find(num) != visited.end()) continue;
		visited.insert(num);

		cout << num << " ";

		for (int e : graph[num])
			stk.push(e);
	}
	cout << "\n";
}

void BFS(const vector<vector<int>>& graph, int start)
{
	queue<int> stk;
	stk.push(start);

	unordered_set<int> visited;

	while (stk.empty() == false)
	{
		int num = stk.front();
		stk.pop();

		if (visited.find(num) != visited.end()) continue;
		visited.insert(num);

		cout << num << " ";

		for (int e : graph[num])
			stk.push(e);
	}
	cout << "\n";
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int n, m, v;
	cin >> n >> m >> v;

	vector<vector<int>> graph(n + 1);
	for (int i = 0; i < m; i++)
	{
		int to, from;
		cin >> to >> from;

		graph[to].push_back(from);
		graph[from].push_back(to);
	}

	for (vector<int>& vec : graph)
	{
		sort(vec.begin(), vec.end(), greater<int>());
	}
	DFS(graph, v);
	
	for (vector<int>& vec : graph)
	{
		sort(vec.begin(), vec.end(), less<int>());
	}
	BFS(graph, v);
}