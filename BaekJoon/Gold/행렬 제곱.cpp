#include <iostream>
#include <vector>

using namespace std;
using ullong = unsigned long long;

const int MOD = 1000;

vector<vector<ullong>> mul(const vector<vector<ullong>>& a, const vector<vector<ullong>>& b)
{
	vector<vector<ullong>> ret(a.size(), vector<ullong>(a.size(), 0));
	for (int i = 0; i < ret.size(); i++)
	{
		for (int j = 0; j < ret.size(); j++)
		{
			for (int k = 0; k < ret.size(); k++)
			{
				ret[i][j] += a[i][k] * b[k][j];
				ret[i][j] %= MOD;
			}
		}
	}
	return ret;
}

vector<vector<ullong>> pow(const vector<vector<ullong>>& mat, ullong exp)
{
	if (exp == 1)
		return mat;

	auto ret = pow(mat, exp / 2);
	ret = mul(ret, ret);

	if (exp % 2 == 1)
	{
		ret = mul(ret, mat);
	}
	return ret;
}

int main()
{
	ullong n, b;
	cin >> n >> b;

	vector<vector<ullong>> mat(n, vector<ullong>(n, 0));
	for (ullong i = 0; i < n; i++)
	{
		for (ullong j = 0; j < n; j++)
		{
			cin >> mat[i][j];
		}
	}

	auto answer = pow(mat, b);
	for (const auto& vec : answer)
	{
		for (ullong e : vec)
			cout << (e%MOD) << " ";
		cout << "\n";
	}
}
