#include <bits/stdc++.h>
using namespace std;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;

    cin >> n;

    vector<string> v(n);
    vector<vector<bool>> vis(n);
    for (int i = 0; i < n; i++)
    {
        vis[i].resize(n);
        cin >> v[i];
    }

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (vis[i][j]) continue;

            cnt++;
            queue<pair<int, int>> q;
            q.push({ i, j });

            while (!q.empty())
            {
                pair<int, int> p = q.front();
                q.pop();

                for (int dir = 0; dir < 4; dir++)
                {
                    int x = p.first + dx[dir];
                    int y = p.second + dy[dir];
                    if (x < 0 || x >= n || y < 0 || y >= n) continue;
                    if (vis[x][y]) continue;
                    if (v[p.first][p.second] != v[x][y]) continue;

                    q.push({ x, y });
                    vis[x][y] = true;
                }
            }
        }
    }
    cout << cnt << ' ';

    for (int i = 0; i < n; i++)
    {
        fill(vis[i].begin(), vis[i].end(), false);
        for (int j = 0; j < n; j++)
            if (v[i][j] == 'R') v[i][j] = 'G';
    }

    cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (vis[i][j]) continue;

            cnt++;
            queue<pair<int, int>> q;
            q.push({ i, j });

            while (!q.empty())
            {
                pair<int, int> p = q.front();
                q.pop();

                for (int dir = 0; dir < 4; dir++)
                {
                    int x = p.first + dx[dir];
                    int y = p.second + dy[dir];
                    if (x < 0 || x >= n || y < 0 || y >= n) continue;
                    if (vis[x][y]) continue;
                    if (v[p.first][p.second] != v[x][y]) continue;

                    q.push({ x, y });
                    vis[x][y] = true;
                }
            }
        }
    }
    cout << cnt;

    return 0;
}