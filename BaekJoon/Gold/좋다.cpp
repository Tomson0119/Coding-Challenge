#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

bool check(map<int, int>& m, int result, int left, int right)
{
	if (m.find(left) != m.end())
	{
		int val = m[left];
		if (result == left) // 0+2=2 와 같은 경우
		{
			val -= 1;
		}
		if (right == left) // 3+3=6 와 같은 경우
		{
			val -= 1;
		}
		return (val >= 1);
	}
	return false;
}

int solve(vector<int>& nums)
{
	sort(nums.begin(), nums.end());
	
	map<int, int> m;
	for (int e : nums)
	{
		m[e] += 1;
	}

	int answer = 0;
	for (int i=0;i<nums.size();i++)
	{
		if (nums[i] <= 0)
		{
			for (int k = 0; k < nums.size(); k++)
			{
				if (k == i) continue;
				int num = nums[i];
				if (num > 0) break;

				num -= nums[k];
				if (check(m, nums[i], num, nums[k]))
				{
					answer += 1;
					break;
				}
			}
		}
		else
		{
			for (int k = 0; k < i; k++)
			{
				int num = nums[i];
				num -= nums[k];
				if (check(m, nums[i], num, nums[k]))
				{
					answer += 1;
					break;
				}
			}
		}
    }
	return answer;
}

int main()
{
	int n;
	cin >> n;

	vector<int> nums(n, 0);
	for (int i = 0; i < n; i++)
	{
		cin >> nums[i];
	}

	cout << solve(nums) << "\n";
}