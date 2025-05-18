#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;

    cin >> n >> m;

    vector<vector<int>> g(n);
    for (int i = 0; i < n; i++)
    {
        g[i].resize(n);
        fill(g[i].begin(), g[i].end(), 12000000);
        g[i][i] = 0;
    }

    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        if (g[a][b] > c)
            g[a][b] = c;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                if (j == k) continue;
                g[j][k] = min(g[j][k], g[j][i] + g[i][k]);
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (g[i][j] == 12000000)
                cout << "0 ";
            else
                cout << g[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}