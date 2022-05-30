#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	int a, b;
	cin >> a >> b;

	queue<pair<long long, int>> que;
	que.push({ a, 1 });

	int answer = -1;
	while (que.empty() == false)
	{
		auto [curr, cnt] = que.front();
		que.pop();

		if (curr > b)
			continue;

		if (curr == b)
		{
			answer = cnt;
			break;
		}

		que.push({ curr * 2, cnt + 1 });
		que.push({ curr * 10 + 1, cnt + 1 });
	}
	cout << answer << "\n";
}