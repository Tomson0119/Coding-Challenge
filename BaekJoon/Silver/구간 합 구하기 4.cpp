#include <iostream>
#include <vector>

using namespace std;

int main()
{
    cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);
    
	int n, m;
	cin >> n >> m;

	vector<int> nums(n + 1, 0);
	for (int i = 1; i <= n; i++)
		cin >> nums[i];

	vector<long long> sums(n+1, 0);
	sums[1] = nums[1];
	for (int i = 2; i <= n; i++)
	{
		sums[i] = sums[i - 1] + nums[i];
	}

	for (int i = 0; i < m; i++)
	{
		int to, from;
		cin >> to >> from;

		cout << sums[from] - sums[to - 1] << "\n";
	}
}