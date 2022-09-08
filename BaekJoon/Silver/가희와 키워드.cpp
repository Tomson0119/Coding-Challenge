#include <iostream>
#include <string>
#include <unordered_set>
#include <sstream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    unordered_set<string> keywords;
    for (int i = 0; i < n; i++)
    {
        string val;
        cin >> val;
        keywords.insert(val);
    }
    for (int i = 0; i < m; i++)
    {
        string s;
        cin >> s;

        stringstream ss(s);
        string temp;
        while (getline(ss, temp, ','))
        {
            keywords.erase(temp);
            temp.clear();
        }
        cout << keywords.size() << "\n";
    }
}