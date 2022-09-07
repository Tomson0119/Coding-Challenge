#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, d, k, c;
    cin >> n >> d >> k >> c;

    vector<int> sushis(n, 0);
    vector<int> dp(n, 0);
    vector<int> exists(d + 1, 0);

    int prev = -1;
    for (int i = 0; i < n; i++)
    {
        cin >> sushis[i];
        if (i == 0)
        {
            dp[i] = 1;
            exists[sushis[i]] = 1;
        }
        else
        {
            dp[i] = dp[i - 1];
            if (exists[sushis[i]] == 0)
            {
                dp[i] += 1;
            }
            exists[sushis[i]] += 1;

            if (i - prev > k)
            {
                prev += 1;
                exists[sushis[prev]] -= 1;
                if (exists[sushis[prev]] == 0)
                {
                    dp[i] -= 1;
                }
            }
        }
        if (exists[c] == 0)
        {
            dp[i] += 1;
        }
        exists[c] += 1;
    }

    for (int i = 0; i < k; i++)
    {
        int prev_idx = (i - 1 < 0) ? n - 1 : i-1;

        dp[i] = dp[prev_idx];
        if (exists[sushis[i]] == 0)
        {
            dp[i] += 1;
        }
        exists[sushis[i]] += 1;
        
        prev += 1;
        exists[sushis[prev]] -= 1;
        if (exists[sushis[prev]] == 0)
        {
            dp[i] -= 1;
        }

        if (exists[c] == 0)
        {
            dp[i] += 1;
        }
        exists[c] += 1;
    }

    int max_val = -1;
    for (int i = 0; i < n; i++)
    {
        max_val = max(max_val, dp[i]);
    }
    cout << max_val << "\n";
}