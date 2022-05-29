#include <iostream>
#include <vector>

using namespace std;

void printNums(const vector<int>& nums)
{
	for (int e : nums)
		cout << e << " ";
	cout << "\n";
}

void backTracking(vector<int> nums, int curr, int n, int m)
{
	if (nums.size() == m)
	{
		printNums(nums);
		return;
	}

	for (int i = curr; i <= n; i++)
	{
		vector<int> vec = nums;
		vec.push_back(i);
		backTracking(vec, i, n, m);
	}
}

int main()
{
	int n, m;
	cin >> n >> m;

	vector<int> nums;
	backTracking(nums, 1, n, m);
}