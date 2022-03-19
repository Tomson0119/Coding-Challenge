#include <iostream>

using namespace std;
using llong = long long;

llong nums[101];

int main()
{
	int t;
	cin >> t;

	nums[1] = nums[2] = nums[3] = 1;
	for (int i = 4; i <= 100; i++)
	{
		nums[i] = nums[i - 2] + nums[i - 3];
	}

	for (int i = 0; i < t; i++)
	{
		int n;
		cin >> n;

		cout << nums[n] << "\n";
	}
}