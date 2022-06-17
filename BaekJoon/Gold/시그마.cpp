#include <iostream>
#include <vector>

using namespace std;
using ullong = unsigned long long;

const ullong MOD = 1'000'000'007;

ullong inverse(ullong val, ullong exp)
{
	if (exp == 0) return 1;
	if (exp == 1) return val;

	ullong ret = inverse(val, exp / 2);
	ret *= ret;
	ret %= MOD;

	if (exp % 2 == 1)
	{
		ret *= val;
		ret %= MOD;
	}
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	ullong m;
	cin >> m;
	
	ullong answer = 0;
	for (ullong i = 0; i < m; i++)
	{
		ullong n, s;
		cin >> n >> s;
		answer += (s * inverse(n, MOD - 2)) % MOD;
		answer %= MOD;
	}
	cout << answer << "\n";
}