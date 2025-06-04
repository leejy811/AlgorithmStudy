#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> bag(n + 1);
    for (int i = 1; i <= n; i++)
    {
        int w, v;
        cin >> w >> v;
        bag[i] = { w, v };
    }

    vector<vector<int>> dp(n + 1);
    for (int i = 0; i <= n; i++)
        dp[i].resize(k + 1);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            if (bag[i].first <= j)
                dp[i][j] = max(dp[i - 1][j - bag[i].first] + bag[i].second, dp[i - 1][j]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    cout << dp[n][k];

    return 0;
}