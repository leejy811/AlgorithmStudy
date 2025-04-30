#include <bits/stdc++.h>
using namespace std;

vector<int> dp(10000005);
vector<int> pre(10000005);

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;

    cin >> n;

    dp[2] = 1;
    dp[3] = 1;
    pre[2] = 1;
    pre[3] = 1;
    for (int i = 4; i <= n; i++)
    {
        dp[i] = dp[i - 1] + 1;
        pre[i] = i - 1;

        if (i % 3 == 0 && dp[i] > dp[i / 3] + 1)
        {
            dp[i] = dp[i / 3] + 1;
            pre[i] = i / 3;
        }
        if (i % 2 == 0 && dp[i] > dp[i / 2] + 1)
        {
            dp[i] = dp[i / 2] + 1;
            pre[i] = i / 2;
        }
    }

    cout << dp[n] << '\n';

    int p = n;
    while (p != 0)
    {
        cout << p << ' ';
        p = pre[p];
    }

    return 0;
}