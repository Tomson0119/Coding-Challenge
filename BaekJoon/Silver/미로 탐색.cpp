#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <tuple>

using namespace std;

bool Find(const pair<int, int>& p, const vector<pair<int, int>>& visited)
{
	auto res = find(visited.begin(), visited.end(), p);
	return (res != visited.end());
}

int BFS(vector<string>& maze)
{
	queue<tuple<int, int, int>> que; // point, distance
	que.push({ 0, 0, 1 });

	vector<pair<int, int>> visited;
	while (que.empty() == false)
	{
		int row = get<0>(que.front());
		int col = get<1>(que.front());
		int dist = get<2>(que.front());
		que.pop();

		if (row == maze.size() - 1 && col == maze[0].size() - 1)
			return dist;

		if (Find({ row,col }, visited)) continue;
		visited.push_back({ row,col });

		if (row > 0 && maze[row - 1][col] == '1')
			que.push({ row - 1, col, dist + 1 });
		if (row < maze.size() - 1 && maze[row + 1][col] == '1')
			que.push({ row + 1, col, dist + 1 });
		if (col > 0 && maze[row][col - 1] == '1')
			que.push({ row, col - 1, dist + 1 });
		if (col < maze[0].size() - 1 && maze[row][col + 1] == '1')
			que.push({ row, col + 1, dist + 1 });
	}
	return -1;
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	vector<string> maze;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		maze.push_back(s);
	}

	cout << BFS(maze) << "\n";
}