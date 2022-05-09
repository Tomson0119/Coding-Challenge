#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> getStarTree(int n)
{
	if (n == 3)
	{
		vector<string> tree = { "  *  ", " * * ", "*****" };
		return tree;
	}

	auto tree = getStarTree(n / 2);
	vector<string> ret = tree;	
	
	string space(n / 2, ' ');
	for (int i = 0; i < ret.size(); i++)
	{
		ret[i] = space + ret[i] + space;
	}
	for (int i = 0; i < tree.size(); i++)
	{
		ret.push_back(tree[i] + " " + tree[i]);
	}
	return ret;
}

int main()
{
	int n;
	cin >> n;

	auto answer = getStarTree(n);
	for (const string& s : answer)
	{
		cout << s << "\n";
	}
}