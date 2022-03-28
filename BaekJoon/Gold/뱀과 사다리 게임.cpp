#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

int BFS(const vector<int> board)
{
	queue<pair<int,int>> que;
	que.push({ 1,0 });

	unordered_set<int> visited;
	while (que.empty() == false)
	{
		int curr = que.front().first;
		int cnt = que.front().second;
		que.pop();
		
		if (curr == 100)
			return cnt;

		if (visited.find(curr) != visited.end())
			continue;
		visited.insert(curr);

		for (int i = curr+1; i <= curr+6; i++)
		{
			if (i > 100) continue;
			
			if (board[i] != 0)
				que.push({ board[i], cnt + 1 });
			else
				que.push({ i, cnt + 1 });
		}
	}
	return -1;
}

int main()
{
	int n, m;
	cin >> n >> m;

	vector<int> board(101, 0);
	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		board[x] = y;
	}

	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		board[u] = v;
	}

	cout << BFS(board) << "\n";
}