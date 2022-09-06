#include <iostream>
#include <vector>
#include <queue>

using namespace std;
const int INF = 10'000'000;

int solve(const vector<vector<int>>& cave)
{
	int len = cave.size();
	priority_queue<pair<pair<int,int>, int>> pq;
	pq.push({ {0,0}, -cave[0][0]});

	vector<vector<int>> distances(len, vector<int>(len, INF));
	distances[0][0] = cave[0][0];

	while (pq.empty() == false)
	{
		auto p = pq.top().first;
		int r = p.first;
		int c = p.second;
		int rupee = -pq.top().second;
		pq.pop();

		if (distances[r][c] < rupee) continue;
		if (r > 0 && distances[r - 1][c] > cave[r - 1][c] + rupee)
		{
			distances[r - 1][c] = cave[r - 1][c] + rupee;
			pq.push({ {r - 1,c}, -distances[r - 1][c] });
		}
		if (r < len - 1 && distances[r + 1][c] > cave[r + 1][c] + rupee)
		{
			distances[r + 1][c] = cave[r + 1][c] + rupee;
			pq.push({ {r + 1,c}, -distances[r + 1][c] });
		}
		if (c > 0 && distances[r][c-1] > cave[r][c-1] + rupee)
		{
			distances[r][c-1] = cave[r][c-1] + rupee;
			pq.push({ {r,c-1}, -distances[r][c-1] });
		}
		if (c < len - 1 && distances[r][c+1] > cave[r][c+1] + rupee)
		{
			distances[r][c+1] = cave[r][c+1] + rupee;
			pq.push({ {r,c+1}, -distances[r][c+1] });
		}
	}
	return distances[len - 1][len - 1];
}

int main()
{
	int k = 1;
	while (true)
	{
		int n;
		cin >> n;
		
		if (n == 0)
			break;

		vector<vector<int>> cave(n, vector<int>(n, 0));
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> cave[i][j];
			}
		}

		cout << "Problem " << k++ << ": " << solve(cave) << "\n";
	}
}