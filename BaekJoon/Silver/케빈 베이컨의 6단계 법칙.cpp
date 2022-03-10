#include <iostream>
#include <vector>

using namespace std;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	
	vector<vector<int>> dist(n + 1, vector<int>(n+1, 10000));
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;

		dist[a][b] = 1;
		dist[b][a] = 1;
	}

	for (int i = 0; i <= n; i++)
		dist[i][i] = 0;

	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (dist[i][j] > dist[i][k] + dist[k][j])
					dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}

	int pick = -1;
	int minv = 10000;
	for (int i = 1; i <= n; i++)
	{
		int sum = 0;
		for (int j = 1; j <= n; j++)
		{
			if (i != j)
			{
				sum += dist[i][j];
			}
		}
		if (minv > sum)
		{
			minv = sum;
			pick = i;
		}
		else if (minv == sum)
		{
			if (pick > i)
				pick = i;
		}
	}
	cout << pick << "\n";
}