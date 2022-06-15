#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> offset = {
	{0, 1}, {-1, 0}, {0, -1}, {1, 0}
};

bool grid[101][101];

void make_curves(vector<pair<int, int>>& curves, 
	const pair<int,int>& endpoint, 
	vector<vector<bool>>& visited, int g)
{
	if (g == 0) return;
	
	int length = curves.size();
	for (int i=0;i<length;i++)
	{
		const auto& p = curves[i];

		int dy = p.first - endpoint.first;
		int dx = endpoint.second - p.second;

		int new_y = endpoint.first - dx;
		int new_x = endpoint.second - dy;

		if (visited[new_y][new_x] == false)
		{
			curves.emplace_back(new_y, new_x);
			visited[new_y][new_x] = true;
		}
	}
	make_curves(curves, curves[length], visited, g - 1);
}

void dragon_curve(int x, int y, int d, int g)
{
	vector<pair<int, int>> curves = {
		{y, x}, {y + offset[d].first, x + offset[d].second}
	};
	vector<vector<bool>> visited(101, vector<bool>(101, false));
	for (const auto& p : curves)
	{
		visited[p.first][p.second] = true;
	}

	make_curves(curves, curves.back(), visited, g);

	for (const auto& p : curves)
	{
		grid[p.first][p.second] = true;
	}
}

int count_square()
{
	int cnt = 0;
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			if (grid[i][j] && grid[i + 1][j]
				&& grid[i][j + 1] && grid[i + 1][j + 1])
				cnt++;
		}
	}
	return cnt;
}

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int x, y, d, g;
		cin >> x >> y >> d >> g;
		dragon_curve(x, y, d, g);
	}
	cout << count_square() << endl;
}