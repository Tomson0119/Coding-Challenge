#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

void backTracking(set<vector<int>>& output,
	const vector<int>& nums, vector<int> picks,
	vector<bool> check, int m)
{
	if (picks.size() == m)
	{
		output.insert(picks);
		return;
	}

	for (int i = 0; i < nums.size(); i++)
	{
		vector<bool> copy_check = check;
		vector<int> copy_picks = picks;
		if (copy_check[i] == false)
		{
			copy_check[i] = true;
			copy_picks.push_back(nums[i]);
			backTracking(output, nums, copy_picks, copy_check, m);
		}
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

	set<vector<int>> output;
	vector<int> picks;
	vector<bool> check(n, false);
	backTracking(output, nums, picks, check, m);

	for (auto iter = output.begin(); iter != output.end(); iter++)
	{
		for (int e : (*iter))
		{
			cout << e << " ";
		}
		cout << "\n";
	}
}