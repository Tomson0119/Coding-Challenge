#include <iostream>
#include <queue>
#include <unordered_set>

using namespace std;

int BFS(int n, int k)
{
	queue<pair<int, int>> que; // current position, time passed
	que.push({ n, 0 });

	unordered_set<int> visited;
	while (que.empty() == false)
	{
		int curr = que.front().first;
		int time = que.front().second;
		que.pop();

		if (curr == k)
			return time;

		if (visited.find(curr) != visited.end())
			continue;
		visited.insert(curr);

		que.push({ curr - 1, time + 1 });
		if (curr < k)
		{
			que.push({ curr + 1, time + 1 });
			if (curr > 0) que.push({ curr * 2, time + 1 });
		}
	}
	return -1;
}

int main()
{
	int n, k;
	cin >> n >> k;

	cout << BFS(n, k) << "\n";
}