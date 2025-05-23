#include <bits/stdc++.h>
using namespace std;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
vector<vector<int>> v;
vector<vector<bool>> vis;
int res = 0;
int n, m;

void dfs(int x, int y, int wei, int cnt)
{
    if (cnt == 4)
    {
        res = max(res, wei);
        return;
    }

    for (int dir = 0; dir < 4; dir++)
    {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        if (vis[nx][ny]) continue;

        vis[nx][ny] = true;
        dfs(nx, ny, wei + v[nx][ny], cnt + 1);
        vis[nx][ny] = false;
    }

    if (x - 1 >= 0 && y - 1 >= 0 && x + 1 < n)
        res = max(res, v[x][y - 1] + v[x - 1][y] + v[x][y] + v[x + 1][y]);

    if (y + 1 < m && x - 1 >= 0 && x + 1 < n)
        res = max(res, v[x][y + 1] + v[x - 1][y] + v[x][y] + v[x + 1][y]);

    if (y - 1 >= 0 && x - 1 >= 0 && y + 1 < m)
        res = max(res, v[x][y - 1] + v[x - 1][y] + v[x][y] + v[x][y + 1]);

    if (y - 1 >= 0 && x + 1 < n && y + 1 < m)
        res = max(res, v[x][y - 1] + v[x + 1][y] + v[x][y] + v[x][y + 1]);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    v.resize(n);
    vis.resize(n);
    for (int i = 0; i < n; i++)
    {
        v[i].resize(m);
        vis[i].resize(m);
        for (int j = 0; j < m; j++)
            cin >> v[i][j];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            vis[i][j] = true;
            dfs(i, j, v[i][j], 1);
            vis[i][j] = false;
        }
    }
    cout << res << ' ';

    return 0;
}