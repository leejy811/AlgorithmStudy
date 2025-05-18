#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;

    cin >> n;

    vector<vector<int>> g(n);
    for (int i = 0; i < n; i++)
    {
        g[i].resize(n);
        for (int j = 0; j < n; j++)
            cin >> g[i][j];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                if (g[j][k]) continue;
                g[j][k] = (g[j][i] + g[i][k]) / 2;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << g[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}