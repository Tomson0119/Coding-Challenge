#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	unordered_map<string, string> book;
	for (int i = 1; i <= n; i++)
	{
		string s;
		cin >> s;

		string num = to_string(i);
		book[num] = s;
		book[s] = num;
	}

	for (int i = 0; i < m; i++)
	{
		string s;
		cin >> s;
		cout << book[s] << "\n";
	}
}