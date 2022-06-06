#include <iostream>
#include <vector>

using namespace std;

const int INF = 987654321;

bool Bellman_Ford(const vector<vector<pair<int, int>>>& graph)
{
	vector<int> distances(graph.size(), 0);

	for (int i = 1; i < graph.size(); i++)
	{
		for (int k = 1; k < graph.size(); k++)
		{
			for (const pair<int, int>& p : graph[k])
			{
				if (distances[p.first] > distances[k] + p.second)
				{
					if (i == graph.size() - 1)
						return true;

					distances[p.first] = distances[k] + p.second;
				}
			}
		}
	}
	return false;
}

int main()
{
	int tc;
	cin >> tc;

	while (tc--)
	{
		int n, m, w;
		cin >> n >> m >> w;

		vector<vector<pair<int, int>>> graph(n + 1);
		for (int i = 0; i < m; i++)
		{
			int s, e, t;
			cin >> s >> e >> t;
			graph[s].push_back({ e,t });
			graph[e].push_back({ s,t });
		}
		for (int i = 0; i < w; i++)
		{
			int s, e, t;
			cin >> s >> e >> t;
			graph[s].push_back({ e, -t });
		}

		string answer = (Bellman_Ford(graph)) ? "YES" : "NO";
		cout << answer << "\n";
	}
}