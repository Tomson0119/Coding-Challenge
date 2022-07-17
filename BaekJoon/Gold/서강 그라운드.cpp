#include <iostream>
#include <vector>

using namespace std;

const int INF = 987654321;

void floydWarshall(vector<vector<int>>& graph)
{
	for (int k = 1; k < graph.size(); k++)
	{
		for (int i = 1; i < graph.size(); i++)
		{
			for (int j = 1; j < graph.size(); j++)
			{
				if (graph[i][j] > graph[i][k] + graph[k][j])
					graph[i][j] = graph[i][k] + graph[k][j];
			}
		}
	}
}

int main()
{
	int n, m, r;
	cin >> n >> m >> r;

	vector<int> items(n + 1, 0);
	vector<vector<int>> graph(n + 1, vector<int>(n+1, INF));
	for (int i = 1; i <= n; i++)
	{
		cin >> items[i];
		graph[i][i] = 0;
	}

	for (int i = 0; i < r; i++)
	{
		int a, b, l;
		cin >> a >> b >> l;
		graph[a][b] = l;
		graph[b][a] = l;
	}

	floydWarshall(graph);
	
	int max_item_count = -1;
	for (int i = 1; i <= n; i++)
	{
		int item_count = 0;
		for (int j = 1; j <= n; j++)
		{
			if (graph[i][j] <= m)
			{
				item_count += items[j];
			}
		}
		max_item_count = max(max_item_count, item_count);
	}
    max_item_count = max(0, max_item_count);
	cout << max_item_count << "\n";
}