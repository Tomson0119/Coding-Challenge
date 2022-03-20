#include <iostream>
#include <vector>

using namespace std;

const int INF = 100'000'000;

int main()
{
	int n;
	cin >> n;

	vector<vector<int>> graph(n, vector<int>(n, INF));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int v;
			cin >> v;

			if (v == 1)
				graph[i][j] = v;
		}
	}

	for (int k = 0; k < n; k++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (graph[i][j] > graph[i][k] + graph[k][j])
					graph[i][j] = graph[i][k] + graph[k][j];
			}
		}
	}

	for (const vector<int>& vec : graph)
	{
		for (int e : vec)
		{
			if (e == INF)
				cout << 0 << " ";
			else
				cout << 1 << " ";
		}
		cout << "\n";
	}
}