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

    for (int i = 1; i <= n; i++)
    {
        v[i].resize(n + 1);

        v[i][0] = 1;
        v[i][i] = 1;
        for (int j = 1; j < i; j++)
        {
            v[i][j] = (v[i - 1][j - 1] + v[i - 1][j]) % 10007;
        }
    }

    cout << v[n][k];

    return 0;
}