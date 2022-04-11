#include <iostream>
#include <vector>
#include <queue>
 
using namespace std;
using AdjList = vector<vector<pair<int, int>>>;

const int INF = 987654321;

int dijkstra(int start, int end, const AdjList& graph)
{
	vector<int> distances(graph.size(), INF);
	distances[start] = 0;

	priority_queue<pair<int, int>> pq;
	pq.push({ start,0 });

	while (pq.empty() == false)
	{
		int curr = pq.top().first;
		int dist = -pq.top().second;
		pq.pop();

		if (dist > distances[curr]) continue;
		for (const pair<int, int>& p : graph[curr])
		{
			int next = p.first;
			int nextDist = dist + p.second;
			if (distances[next] > nextDist)
			{
				distances[next] = nextDist;
				pq.push({ next, -nextDist });
			}
		}
	}
	return distances[end];
}

int main()
{
	int n, m;
	cin >> n >> m;

	AdjList graph(n+1);
	for (int i = 0; i < m; i++)
	{
		int s, e, w;
		cin >> s >> e >> w;
		graph[s].push_back({ e,w });
	}
	int start, end;
	cin >> start >> end;
	cout << dijkstra(start, end, graph) << "\n";
}