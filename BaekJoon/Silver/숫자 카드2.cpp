#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int Search(const vector<pair<int, int>>& hash, int value)
{
	int start = 0;
	int end = hash.size() - 1;

	while (start <= end)
	{
		int mid = (start + end) / 2;

		if (hash[mid].first == value)
			return hash[mid].second;

		if (hash[mid].first < value)
			start = mid + 1;
		else
			end = mid - 1;
	}
	return 0;
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	vector<int> nums(n);
	for (int i = 0; i < n; i++)
	{
		cin >> nums[i];
	}
	sort(nums.begin(), nums.end());

	vector<pair<int, int>> hash;
	int current = 0;
	for (int e : nums)
	{
		if (hash.empty() || hash.back().first != e)
		{
			hash.push_back({ e, 1 });
		}
		else
			hash.back().second += 1;
	}

	int m;
	cin >> m;

	for (int i = 0; i < m; i++)
	{
		int v;
		cin >> v;

		cout << Search(hash, v) << " ";
	}
	cout << "\n";
}