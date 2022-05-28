#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;

	vector<int> visited(100'001, false);
	queue<pair<int, int>> que;
	que.push({ n, 0 });

	while (que.empty() == false)
	{
		int curr = que.front().first;
		int time = que.front().second;
		que.pop();

		if (curr == k)
		{
			cout << time << "\n";
			break;
		}

		if (curr > 0 && visited[curr - 1] == false)
		{
			visited[curr - 1] = true;
			que.push({ curr - 1, time + 1 });
		}
		if (curr > 0 && curr < k && curr*2 < visited.size()
			&& visited[curr * 2] == false)
		{
			visited[curr * 2] = true;
			que.push({ curr * 2, time });
		}
		if (curr < k && curr+1 < visited.size()
			&& visited[curr + 1] == false)
		{
			visited[curr + 1] = true;
			que.push({ curr + 1, time + 1 });
		}
	}
}