#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<int> nums(n + 1);
	nums[1] = 1;
	
	int mod = 10'007;
	for (int i = 2; i <= n; i++)
	{
		if (i % 2 == 0)
			nums[i] = (nums[i - 1] * 2 + 1) % mod;
		else
			nums[i] = (nums[i - 1] * 2 - 1) % mod;
	}
	cout << nums[n] << "\n";
}