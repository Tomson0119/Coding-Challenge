#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	unordered_map<string, string> mapp;
	for (int i = 0; i < n; i++)
	{
		string site, password;
		cin >> site >> password;
		mapp[site] = password;
	}

	for (int i = 0; i < m; i++)
	{
		string site;
		cin >> site;
		cout << mapp[site] << "\n";
	}
}