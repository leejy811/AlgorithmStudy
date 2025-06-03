#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s1, s2;
    cin >> s1 >> s2;

    vector<vector<int>> dp(s1.size() + 1);

    dp[0].resize(s2.size() + 1);
    for (int i = 1; i <= s1.size(); i++)
    {
        dp[i].resize(s2.size() + 1);
        for (int j = 1; j <= s2.size(); j++)
        {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    cout << dp[s1.size()][s2.size()];

    return 0;
}