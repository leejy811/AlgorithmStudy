#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;

    cin >> n >> k;

    vector<vector<int>> v(n + 1);

    for (int i = 0; i <= n; i++)
    {
        v[i].resize(k + 1);
        v[i][0] = 1;
        if (i <= k) v[i][i] = 1;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            v[i][j] = v[i - 1][j] + v[i - 1][j - 1];
        }
    }

    cout << v[n][k];

    return 0;
}