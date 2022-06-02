#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 200'000'001;

int dijkstra(const vector<vector<pair<int, int>>>& graph, int start, int end)
{
	priority_queue<pair<int, int>> pq;
	pq.push({ start, 0 });

	vector<int> distance(graph.size(), INF);
	distance[start] = 0;

	while (pq.empty() == false)
	{
		int curr = pq.top().first;
		int dist = -pq.top().second;
		pq.pop();

		if (distance[curr] < dist) continue;
		for (const pair<int, int>& p : graph[curr])
		{
			if (p.second + dist < distance[p.first])
			{
				distance[p.first] = p.second + dist;
				pq.push({ p.first, -distance[p.first] });
			}
		}
	}
	return distance[end];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, e;
	cin >> n >> e;

	vector<vector<pair<int, int>>> graph(n + 1);
	for (int i = 0; i < e; i++)
	{
		int v1, v2, c;
		cin >> v1 >> v2 >> c;
		graph[v1].push_back({ v2,c });
		graph[v2].push_back({ v1,c });
	}

	int u, v;
	cin >> u >> v;

	vector<vector<int>> way = {
		{1, u, v, n}, {1, v, u, n}
	};

	int min_value = INF;
	for (const vector<int>& vec : way)
	{
		int total = 0;
		for (int i = 0; i < vec.size() - 1; i++)
		{
			int val = dijkstra(graph, vec[i], vec[i + 1]);
			if (val == INF)
			{
				total = INF;
				break;
			}
			total += val;
		}
		min_value = min(min_value, total);
	}
	if (min_value == INF) min_value = -1;
	cout << min_value << "\n";
}