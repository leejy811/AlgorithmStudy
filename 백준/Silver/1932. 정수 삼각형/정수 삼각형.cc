#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<vector<int>> dp(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            int x;
            cin >> x;
            dp[i].push_back(x);
        }
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            if (j == 0)
                dp[i][j] = dp[i - 1][j] + dp[i][j];
            else if (j == i)
                dp[i][j] = dp[i - 1][j - 1] + dp[i][j];
            else
                dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + dp[i][j];
        }
    }

    cout << *max_element(dp[n - 1].begin(), dp[n - 1].end());

    return 0;
}