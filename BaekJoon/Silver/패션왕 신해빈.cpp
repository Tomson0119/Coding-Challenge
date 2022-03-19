#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int main()
{
	int t;
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		int n;
		cin >> n;

		unordered_map<string, vector<string>> clothes;
		for (int j = 0; j < n; j++)
		{
			string name, part;
			cin >> name >> part;

			clothes[part].push_back(name);
		}

		int cnt = 1;
		for (const auto& [_, vec] : clothes)
		{
			cnt *= (vec.size() + 1);
		}
		cout << cnt - 1 << "\n";
	}
}