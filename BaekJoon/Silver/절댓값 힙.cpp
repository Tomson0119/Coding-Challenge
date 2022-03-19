#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct CustomCompare
{
	bool operator()(int a, int b) const {
		int abs_a = (a > 0) ? a : -a;
		int abs_b = (b > 0) ? b : -b;

		if (abs_a == abs_b)
			return (a > b);
		return (abs_a > abs_b);
	}
};

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	priority_queue<int, vector<int>, CustomCompare> pq;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;

		if (x != 0) pq.push(x);
		else
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