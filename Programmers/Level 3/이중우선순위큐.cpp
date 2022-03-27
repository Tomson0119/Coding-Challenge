#include <iostream>
#include <vector>
#include <set>
#include <sstream>

using namespace std;

vector<int> solution(vector<string> operations)
{
	set<int> sett;
	for (const string& s : operations)
	{
		stringstream ss(s);
		char op;
		int val;
		ss >> op >> val;

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
	if(sett.empty())
		return { 0, 0 };
	else
		return { *sett.rbegin(), *sett.begin() };
}

int main()
{
	cout << solution({ "I 16", "D 1" }) << "\n";
	cout << solution({ "I 7","I 5","I -5","D -1" }) << "\n";
}