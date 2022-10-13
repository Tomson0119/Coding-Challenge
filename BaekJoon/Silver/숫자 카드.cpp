#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int contains(vector<int>& cards, int n)
{
	int left = 0;
	int right = cards.size() - 1;
	while (left <= right)
	{
		int mid = (left + right) / 2;

		if (cards[mid] < n)
		{
			left = mid + 1;
		}
		else if (cards[mid] > n)
		{
			right = mid - 1;
		}
		else
		{
			return 1;
		}
	}
	return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    
	int n;
	cin >> n;

	vector<int> cards(n, 0);
	for (int i = 0; i < n; i++)
	{
		cin >> cards[i];
	}

	sort(cards.begin(), cards.end());

	int m;
	cin >> m;

	for (int i = 0; i < m; i++)
	{
		int num;
		cin >> num;
		cout << contains(cards, num) << " ";
	}
	cout << "\n";
}