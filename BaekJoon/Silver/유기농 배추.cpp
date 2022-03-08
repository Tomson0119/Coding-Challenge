#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void MarkField(const vector<vector<int>>& field, vector<vector<bool>>& visited, int r, int c)
{
	queue<pair<int, int>> que;
	que.push({ r,c });

	while (que.empty() == false)
	{
		int row = que.front().first;
		int col = que.front().second;
		que.pop();

		if (visited[row][col] == true)
			continue;

		visited[row][col] = true;

		if (row > 0 && field[row - 1][col] == 1)
			que.push({ row - 1,col });
		if (row < field.size() - 1 && field[row + 1][col] == 1)
			que.push({ row + 1,col });
		if (col > 0 && field[row][col - 1] == 1)
			que.push({ row,col - 1 });
		if (col < field[0].size() - 1 && field[row][col + 1] == 1)
			que.push({ row, col + 1 });
	}
}

int GetCountOfWorms(const vector<vector<int>>& field)
{
	vector<vector<bool>> visited(field.size(), vector<bool>(field[0].size(), false));

	int cnt = 0;
	for (int i = 0; i < field.size(); i++)
	{
		for (int j = 0; j < field[0].size(); j++)
		{
			if (field[i][j] == 1 && visited[i][j] == false)
			{
				MarkField(field, visited, i, j);
				cnt++;
			}
		}
	}
	return cnt;
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int t;
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		int m, n, k;
		cin >> m >> n >> k;

		vector<vector<int>> field(m, vector<int>(n, 0));
		for (int j = 0; j < k; j++)
		{
			int r, c;
			cin >> r >> c;
			field[r][c] = 1;
		}

		cout << GetCountOfWorms(field) << "\n";
	}
}