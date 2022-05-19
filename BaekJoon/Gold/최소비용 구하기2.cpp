#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 100'000'001;

pair<int, vector<int>> dijkstra(const vector<vector<pair<int, int>>>& graph, int start, int end)
{
	priority_queue<pair<int, int>> pq;
	pq.push({ start, 0 });

	vector<int> distances(graph.size(), INF);
	distances[start] = 0;

	vector<vector<int>> path(graph.size());
	path[start] = { start };

	while (pq.empty() == false)
	{
		int curr = pq.top().first;
		int dist = -pq.top().second;
		pq.pop();

		if (distances[curr] < dist) continue;
		for (const pair<int,int>& p : graph[curr])
		{
			int nextDist = p.second + dist;
			if (distances[p.first] > nextDist)
			{
				path[p.first] = path[curr];
				path[p.first].push_back(p.first);

				distances[p.first] = nextDist;
				pq.push({ p.first, - nextDist});
			}
		}
	}
	return { distances[end], path[end] };
}

int main()
{
	int n, m;
	cin >> n >> m;

	vector<vector<pair<int, int>>> graph(n + 1);
	for (int i = 0; i < m; i++)
	{
		int from, to, weight;
		cin >> from >> to >> weight;
		graph[from].push_back({ to, weight });
	}

	int start, end;
	cin >> start >> end;

	pair<int, vector<int>> answer = dijkstra(graph, start, end);
	cout << answer.first << "\n";
	cout << answer.second.size() << "\n";
	for (int e : answer.second) cout << e << " ";
	cout << "\n";
}