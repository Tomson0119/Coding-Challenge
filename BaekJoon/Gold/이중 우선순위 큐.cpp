#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int t;
	cin >> t;
	
	for (int i = 0; i < t; i++)
	{
		int k;
		cin >> k;

		multiset<int> sett;
		for (int j = 0; j < k; j++)
		{
			char op;
			int val;
			cin >> op >> val;

			switch (op)
			{
			case 'I':
				sett.insert(val);
				break;

			case 'D':
				if (sett.empty()) break;
				if (val == 1)
					sett.erase(prev(sett.end()));
				else
					sett.erase(sett.begin());
				break;
			}
		}
		if (sett.empty())
			cout << "EMPTY\n";
		else
			cout << *sett.rbegin() << " " << *sett.begin() << "\n";
	}
}