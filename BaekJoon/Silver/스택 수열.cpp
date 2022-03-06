#include <iostream>
#include <vector>
#include <string>

using namespace std;


int main()
{
	int n;
	cin >> n;

	vector<string> answers;
	vector<int> stack;
	stack.reserve(n);

	int next = 1;
	for (int i = 0; i < n; i++)
	{
		int v;
		cin >> v;

		if (v >= next)
		{
			for (int k = next; k < v; k++)
			{
				stack.push_back(k);
				answers.push_back("+");
			}
			next = v + 1;
			answers.push_back("+");
			answers.push_back("-");
		}
		else
		{
			int top = 0;
			while (top != v && stack.empty() == false)
			{
				top = stack.back();
				stack.pop_back();
				answers.push_back("-");
			}

			if (top != v)
			{
				answers.clear();
				answers.push_back("NO");
				break;
			}
		}
	}

	for (const string& s : answers)
		cout << s << "\n";
}