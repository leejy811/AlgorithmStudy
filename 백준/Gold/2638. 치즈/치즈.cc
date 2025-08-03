#include <bits/stdc++.h>
using namespace std;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

vector<vector<int>> v;
vector<vector<bool>> vis;

int n, m;

bool dfs(int x, int y)
{
    vis[x][y] = true;

    if (x == 0 || y == 0 || x == n - 1 || y == m - 1)
        return true;

    for (int dir = 0; dir < 4; dir++)
    {
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
        if (vis[nx][ny]) continue;
        if (v[nx][ny]) continue;

        if (dfs(nx, ny))
            return true;
    }

    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    v.resize(n);
    vis.resize(n);
    vector<pair<int, int>> c;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        v[i].resize(m);
        vis[i].resize(m);
        for (int j = 0; j < m; j++)
        {
            cin >> v[i][j];

            if (v[i][j])
            {
                c.push_back({ i, j });
                cnt++;
            }
        }
    }

    int res = 0;
    while (cnt)
    {
        vector<pair<int, int>> rm;
        vector<vector<bool>> open(n);

        for (int i = 0; i < n; i++)
            open[i].resize(m);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!v[i][j])
                {
                    for (int k = 0; k < n; k++)
                        fill(vis[k].begin(), vis[k].end(), false);
                    open[i][j] = dfs(i, j);
                }
            }
        }

        for (pair<int, int> p : c)
        {
            int x, y;
            tie(x, y) = p;

            if (!v[x][y]) continue;

            int air = 0;
            for (int dir = 0; dir < 4; dir++)
            {
                int nx = x + dx[dir];
                int ny = y + dy[dir];

                if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                if (v[nx][ny]) continue;
                if (!open[nx][ny]) continue;

                air++;
            }

            if (air >= 2)
                rm.push_back({ x, y });
        }

        for (pair<int, int> p : rm)
        {
            v[p.first][p.second] = 0;
            cnt--;
        }

        res++;
    }

    cout << res;

    return 0;
}