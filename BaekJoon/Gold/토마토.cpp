#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int m, n, h;
	cin >> m >> n >> h;

	queue<tuple<int, int, int, int>> que;
	vector<vector<vector<int>>> tomatos(h, vector<vector<int>>(n, vector<int>(m)));
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < m; k++)
			{
				cin >> tomatos[i][j][k];
				if (tomatos[i][j][k] == 1)
					que.push({ i,j,k, 0 });
			}
		}
	}

	int day = 0;
	while (que.empty() == false)
	{
		int l = get<0>(que.front());
		int r = get<1>(que.front());
		int c = get<2>(que.front());
		day = get<3>(que.front());
		que.pop();

		if (l > 0 && tomatos[l - 1][r][c] == 0)
		{
			que.push({ l - 1,r,c,day + 1 });
			tomatos[l - 1][r][c] = 1;
		}
		if (l < h - 1 && tomatos[l + 1][r][c] == 0)
		{
			que.push({ l + 1,r,c,day + 1 });
			tomatos[l + 1][r][c] = 1;
		}
		if (r > 0 && tomatos[l][r - 1][c] == 0)
		{
			que.push({ l,r - 1,c,day + 1 });
			tomatos[l][r - 1][c] = 1;
		}
		if (r < n - 1 && tomatos[l][r + 1][c] == 0)
		{
			que.push({ l,r + 1,c,day + 1 });
			tomatos[l][r + 1][c] = 1;
		}
		if (c > 0 && tomatos[l][r][c - 1] == 0)
		{
			que.push({ l,r,c - 1,day + 1 });
			tomatos[l][r][c - 1] = 1;
		}
		if (c < m - 1 && tomatos[l][r][c + 1] == 0)
		{
			que.push({ l,r,c + 1,day + 1 });
			tomatos[l][r][c + 1] = 1;
		}
	}

	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < m; k++)
			{
				if (tomatos[i][j][k] == 0)
				{
					day = -1;
					break;
				}
			}
		}
	}
	cout << day << "\n";
}