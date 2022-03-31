#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	map<int, int> nums1;
	vector<int> nums2(n);
	for (int i = 0; i < n; i++)
	{
		int v;
		cin >> v;
		nums1[v] = 0;
		nums2[i] = v;
	}

	int i = 0;
	for (auto iter = nums1.begin(); iter != nums1.end(); iter++)
	{
		(*iter).second = i++;
	}

	for (int e : nums2)
	{
		cout << nums1[e] << " ";
	}
	cout << "\n";
}