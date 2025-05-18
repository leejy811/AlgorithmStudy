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
    vector<vector<int>> nxt(n);
    for (int i = 0; i < n; i++)
    {
        g[i].resize(n);
        nxt[i].resize(n);
        fill(g[i].begin(), g[i].end(), 12000000);
        fill(nxt[i].begin(), nxt[i].end(), -1);
        g[i][i] = 0;
    }

    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        if (g[a][b] > c)
        {
            g[a][b] = c;
            nxt[a][b] = b;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                if (j == k) continue;
                if (g[j][i] + g[i][k] < g[j][k])
                {
                    g[j][k] = g[j][i] + g[i][k];
                    nxt[j][k] = nxt[j][i];
                }
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

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (nxt[i][j] == -1)
            {
                cout << "0\n";
                continue;
            }

            vector<int> path;
            int nxt_temp = i;
            while (nxt_temp != -1 && nxt_temp != j)
            {
                path.push_back(nxt_temp);
                nxt_temp = nxt[nxt_temp][j];
            }
            path.push_back(nxt_temp);
            cout << path.size() << ' ';
            for (int x : path)
            {
                cout << x + 1 << ' ';
            }
            cout << '\n';
        }
    }

    return 0;
}