#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool Find(const pair<int, int>& val, const vector<pair<int, int>>& visited)
{
	return (find(visited.begin(), visited.end(), val) != visited.end());
}

int BFS(const pair<int, int>& start, const vector<string>& houses, vector<pair<int, int>>& visited)
{
	queue<pair<int, int>> que;
	que.push(start);

	int cnt = 0;
	while (que.empty() == false)
	{
		int row = que.front().first;
		int col = que.front().second;
		que.pop();

		if (Find({ row,col }, visited)) continue;
		visited.push_back({ row,col });

		cnt += 1;

		if (row > 0 && houses[row - 1][col] == '1')
			que.push({ row - 1,col });
		if (row < houses.size() - 1 && houses[row + 1][col] == '1')
			que.push({ row + 1,col });
		if (col > 0 && houses[row][col - 1] == '1')
			que.push({ row,col - 1 });
		if (col < houses[0].size() - 1 && houses[row][col + 1] == '1')
			que.push({ row,col + 1 });
	}
	return cnt;
}

int main()
{
	int n;
	cin >> n;
	
	vector<string> houses(n);
	for (int i = 0; i < n; i++)
	{
		cin >> houses[i];
	}

	vector<int> answers;
	vector<pair<int, int>> visited;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (houses[i][j] == '1' && Find({i, j}, visited)==false)
			{
				int cnt = BFS({ i, j }, houses, visited);
				answers.push_back(cnt);
			}
		}
	}

	sort(answers.begin(), answers.end());
	cout << answers.size() << "\n";
	for (int e : answers) cout << e << "\n";
}