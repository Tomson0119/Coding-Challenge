#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print(const vector<int>& vec)
{
	for (int e : vec)
		cout << e << " ";
	cout << "\n";
}

void backTracking(
	const vector<int>& nums, vector<int> picks, int idx, int m)
{
	if (picks.size() == m)
	{
		print(picks);
		return;
	}

	for (int i = idx; i < nums.size(); i++)
	{
		vector<int> copy_picks = picks;
		copy_picks.push_back(nums[i]);
		backTracking(nums, copy_picks, i, m);
	}
}

int main()
{
	int n, m;
	cin >> n >> m;

	vector<int> nums(n);
	for (int i = 0; i < n; i++)
	{
		cin >> nums[i];
	}

	sort(nums.begin(), nums.end());

	vector<int> picks;
	backTracking(nums, picks, 0, m);
}