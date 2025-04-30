#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;

    cin >> n;

    vector<tuple<int, int, int>> v(n);
    vector<vector<int>> dp(n);

    for (int i = 0; i < n; i++)
    {
        dp[i].resize(3);
        int r, g, b;
        cin >> r >> g >> b;
        v[i] = { r, g, b };
    }

    dp[0][0] = get<0>(v[0]);
    dp[0][1] = get<1>(v[0]);
    dp[0][2] = get<2>(v[0]);

    for (int i = 1; i < n; i++)
    {
        dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + get<0>(v[i]);
        dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + get<1>(v[i]);
        dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + get<2>(v[i]);
    }

    cout << min(min(dp[n - 1][0], dp[n - 1][1]), dp[n - 1][2]);

    return 0;
}