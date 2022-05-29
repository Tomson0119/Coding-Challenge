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
	const vector<int>& nums, vector<int> picks, 
	vector<bool> check, int m)
{
	if (picks.size() == m)
	{
		print(picks);
		return;
	}

	for (int i = 0; i < nums.size(); i++)
	{
		vector<bool> copy_check = check;
		vector<int> copy_picks = picks;
		if (copy_check[i]==false)
		{
			copy_check[i] = true;
			copy_picks.push_back(nums[i]);
			backTracking(nums, copy_picks, copy_check, m);
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

	vector<int> picks;
	vector<bool> check(8, false);
	backTracking(nums, picks, check, m);
}