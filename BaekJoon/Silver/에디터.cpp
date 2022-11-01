#include <iostream>
#include <list>
#include <string>

using namespace std;

void insert(list<char>& list, const string& s)
{
	for (char c : s)
	{
		list.push_back(c);
	}
}

void print(const list<char>& list)
{
	for (char c : list)
	{
		cout << c;
	}
	cout << "\n";
}

void operate(list<char>& lst, char op, char letter, list<char>::iterator& pos)
{
	if (op == 'L')
	{
		if (pos != lst.begin()) pos--;
	}
	else if (op == 'D')
	{
		if (pos != lst.end()) pos++;
	}
	else if (op == 'B')
	{
		if (pos != lst.begin())
		{
			pos = lst.erase(--pos);
		}
	}
	else if (op == 'P')
	{
		pos = lst.insert(pos, letter);
		if (pos != lst.end()) pos++;
	}
}

int main()
{
	string s;
	cin >> s;

	int m;
	cin >> m;

	list<char> list;
	insert(list, s);
	auto pos = list.end();

	for (int i = 0; i < m; i++)
	{
		char op;
		cin >> op;

		char letter{};
		if (op == 'P')
		{
			cin >> letter;
		}
		operate(list, op, letter, pos);
	}
    print(list);
}