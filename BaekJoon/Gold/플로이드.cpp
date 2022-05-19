#include <iostream>
#include <vector>

using namespace std;

const int INF = 10'000'001;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	vector<vector<int>> graph(n + 1,vector<int>(n+1, INF));
	for (int i = 1; i <= n; i++) graph[i][i] = 0;
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		graph[a][b] = min(c, graph[a][b]);
	}

	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (graph[i][j] > graph[i][k] + graph[k][j])
					graph[i][j] = graph[i][k] + graph[k][j];
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (graph[i][j] == INF)
				cout << 0 << " ";
			else
				cout << graph[i][j] << " ";
		}
		cout << "\n";
	}
}