#include <iostream>

using namespace std;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	int cnt = 0;
	long long val = 1;
	for (int i = 2; i <= n; i++)
	{
		val *= i;
		while (val % 10 == 0)
		{
			cnt += 1;
			val /= 10;
		}
		val %= 10'000'000;
	}
	cout << cnt << "\n";
}