#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<vector<int>> nums(n+1);
	for (int i = 0; i < n-1; i++)
	{
		int a, b;
		cin >> a >> b;
		nums[a].push_back(b);
		nums[b].push_back(a);
	}

	vector<int> tree(n+1);
	
	queue<int> que;
	que.push(1);

	vector<bool> visited(n + 1, false);
	while (que.empty() == false)
	{
		int e = que.front();
		que.pop();

		for (int child : nums[e])
		{
			if (visited[child] == false)
			{
				visited[child] = true;
				tree[child] = e;
				que.push(child);
			}
		}
	}

	for (int i = 2; i <= n; i++)
	{
		cout << tree[i] << "\n";
	}
}