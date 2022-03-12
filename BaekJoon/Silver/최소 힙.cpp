#include <iostream>
#include <queue>

using namespace std;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	priority_queue<int> pq;
	for (int i = 0; i < n; i++)
	{
		int v;
		cin >> v;
		
		if (v > 0)
			pq.push(-v);
		else
		{
			if (pq.empty())
				cout << v << "\n";
			else
			{
				cout << -pq.top() << "\n";
				pq.pop();
			}
		}
	}
}