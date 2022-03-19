#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	priority_queue<int> pq;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;

		if (x > 0) pq.push(x);
		else if (x == 0)
		{
			if (pq.empty())
			{
				cout << 0 << "\n";
				continue;
			}
			cout << pq.top() << "\n";
			pq.pop();
		}
	}
}