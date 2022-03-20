#include <iostream>

using namespace std;

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	bool nums[21];
	for (int i = 0; i <= 20; i++)
		nums[i] = false;

	for (int i = 0; i < n; i++)
	{
		string op;
		cin >> op;

		int v;
		if (op != "all" && op != "empty")
			cin >> v;

		if (op == "add")
		{
			nums[v] = true;
		}
		else if (op == "remove")
		{
			nums[v] = false;
		}
		else if (op == "check")
		{
			cout << nums[v] << "\n";
		}
		else if (op == "toggle")
		{			
			nums[v] = !nums[v];
		}
		else if (op == "all")
		{
			for (int i = 1; i <= 20; i++)
				nums[i] = true;
		}
		else if (op == "empty")
		{
			for (int i = 1; i <= 20; i++)
				nums[i] = false;
		}
	}
}