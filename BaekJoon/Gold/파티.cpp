#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

const int INF = 1'000'000'000;

void dijkstra(
	int start,
	const vector<vector<pair<int, int>>>& roads,
	vector<int>& distances)
{
	priority_queue<pair<int, int>> pq;
	pq.push({ start, 0 });

	distances[start] = 0;

	while (pq.empty() == false)
	{
		int curr = pq.top().first;
		int dist = -pq.top().second;

		pq.pop();

		if (distances[curr] < dist) continue;
		for (const pair<int, int>& road : roads[curr])
		{
			int next = road.first;
			int nextDist = road.second;

			if (distances[next] > nextDist + dist)
			{
				distances[next] = nextDist + dist;
				pq.push({ next, -(nextDist + dist) });
			}
		}
	}
}

int getDistance(int start, int target, const vector<vector<pair<int, int>>>& roads)
{
	vector<int> distances(roads.size(), INF);
	dijkstra(start, roads, distances);
	return distances[target];
}

int getLongestTime(int target, const vector<vector<pair<int, int>>>& roads)
{
	vector<int> fromTarget(roads.size(), INF);
	dijkstra(target, roads, fromTarget);

	int max_val = -1;
	for (int i = 1; i < roads.size(); i++)
	{
		int to = getDistance(i, target, roads);
		int from = fromTarget[i];
		max_val = max(max_val, to+from);
	}
	return max_val;
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int n, m, x;
	cin >> n >> m >> x;

	vector<vector<pair<int, int>>> roads(n+1);
	for (int i = 0; i < m; i++)
	{
		int s, e, t;
		cin >> s >> e >> t;
		roads[s].push_back({ e,t });
	}
	cout << getLongestTime(x, roads) << "\n";
}