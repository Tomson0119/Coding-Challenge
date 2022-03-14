#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool Find(const vector<int>& vec, int target)
{
	return (find(vec.begin(), vec.end(), target) != vec.end());
}

int BFS(int start, const vector<vector<int>>& graph)
{
	queue<int> que;
	que.push(start);

	int cnt = 0;
	vector<int> visited;
	while (que.empty() == false)
	{
		int curr = que.front();
		que.pop();

		if (Find(visited, curr))
			continue;
		
		visited.push_back(curr);
		cnt += 1;

		for (int e : graph[curr])
		{
			que.push(e);
		}
	}
	return cnt-1;
}

int main()
{
	int n, m;
	cin >> n >> m;

	vector<vector<int>> graph(n+1);
	for (int i = 0; i < m; i++)
	{
		int to, from;
		cin >> from >> to;

		graph[to].push_back(from);
		graph[from].push_back(to);
	}

	cout << BFS(1, graph) << "\n";
}