#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;

    cin >> n >> m;

    vector<vector<int>> v(n);
    vector<vector<int>> dist(n);
    queue<pair<int, int>> q;

    for (int i = 0; i < n; i++)
    {
        v[i].resize(m);
        dist[i].resize(m);
        for (int j = 0; j < m; j++)
        {
            cin >> v[i][j];

            if (v[i][j] == 2)
                q.push({ i, j });
            else if (v[i][j] == 1)
                dist[i][j] = -1;
        }
    }

    vector<int> di = { 1, 0, -1, 0 };
    vector<int> dj = { 0, 1, 0, -1 };
    int cnt = 0;

    pair<int, int> p;
    while (!q.empty())
    {
        p = q.front();
        q.pop();

        for (int k = 0; k < 4; k++)
        {
            int x = p.first + di[k];
            int y = p.second + dj[k];

            if (x < 0 || y < 0 || x >= n || y >= m) continue;
            if (v[x][y] != 1) continue;

            v[x][y] = 0;
            q.push({ x, y });
            dist[x][y] = dist[p.first][p.second] + 1;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << dist[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}