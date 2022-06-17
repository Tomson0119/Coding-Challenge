#include <iostream>
#include <vector>

using namespace std;
using ullong = unsigned long long;

const ullong MOD = 1'000'000'007;

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

vector<vector<ullong>> pow(ullong n)
{
	if (n == 0)
		return {{1,0}, {0,1}};
	if (n == 1)
		return {{1,1}, {1,0}};

	auto mat = pow(n / 2);
	mat = mul(mat, mat);
	if (n % 2 != 0)
	{
		mat = mul(mat, { {1,1}, {1,0} });
	}
	return mat;
}

int main()
{
	ullong n;
	cin >> n;

	auto mat = pow(n-1);

	vector<ullong> answer = { 0,0 };
	vector<ullong> values = { 1,0 };
	for (int i = 0; i < mat.size(); i++)
	{
		for (int j = 0; j < mat.size(); j++)
		{
			answer[i] += mat[i][j] * values[j];
		}
	}
	cout << answer[0] << endl;
}