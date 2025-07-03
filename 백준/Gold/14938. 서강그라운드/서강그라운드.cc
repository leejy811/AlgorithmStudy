#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, r;

    cin >> n >> m >> r;

    vector<int> item(n);

    for (int i = 0; i < n; i++)
    {
        cin >> item[i];
    }

    vector<vector<int>> g(n);
    for (int i = 0; i < n; i++)
    {
        g[i].resize(n);
        fill(g[i].begin(), g[i].end(), 1e9);
    }

    for (int i = 0; i < r; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        g[a][b] = c;
        g[b][a] = c;
    }

    int max = 0;
    for (int i = 0; i < n; i++)
    {
        queue<pair<int, int>> q;
        q.push({ i, 0 });

        vector<bool> vis(n);
        vis[i] = true;
        while (!q.empty())
        {
            pair<int, int> p = q.front();
            q.pop();

            for (int j = 0; j < n; j++)
            {
                if (i == j) continue;
                if (g[p.first][j] + p.second > g[i][j]) continue;
                if (g[p.first][j] + p.second > m) continue;

                g[i][j] = g[p.first][j] + p.second;
                q.push({ j, g[i][j] });
                vis[j] = true;
            }
        }

        int res = 0;
        for (int j = 0; j < n; j++)
            if (vis[j])
                res += item[j];
        if (max < res)
            max = res;
    }

    cout << max;

    return 0;
}