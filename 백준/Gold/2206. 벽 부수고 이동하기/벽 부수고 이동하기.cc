#include <bits/stdc++.h>
using namespace std;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;

    cin >> n >> m;

    vector<vector<int>> v(n);
    vector<vector<vector<int>>> vis(n);
    for (int i = 0; i < n; i++)
    {
        v[i].resize(m);
        vis[i].resize(m);
        string s;
        cin >> s;
        for (int j = 0; j < m; j++)
        {
            v[i][j] = s[j] - '0';
            vis[i][j].resize(2);
        }
    }

    queue<tuple<pair<int, int>, int>> q;
    q.push({ {0, 0}, 1 });
    vis[0][0][1] = 1;

    while (!q.empty())
    {
        pair<int, int> pos;
        int canBreak;

        tie(pos, canBreak) = q.front();
        q.pop();

        if (pos.first == n - 1 && pos.second == m - 1)
        {
            cout << vis[pos.first][pos.second][canBreak];
            return 0;
        }

        for (int dir = 0; dir < 4; dir++)
        {
            int nx = pos.first + dx[dir];
            int ny = pos.second + dy[dir];

            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;

            if (v[nx][ny] && canBreak)
            {
                q.push({ {nx, ny}, 0 });
                vis[nx][ny][canBreak - 1] = vis[pos.first][pos.second][canBreak] + 1;
            }
            else if(!v[nx][ny] && !vis[nx][ny][canBreak])
            {
                q.push({ {nx, ny}, canBreak });
                vis[nx][ny][canBreak] = vis[pos.first][pos.second][canBreak] + 1;
            }
        }
    }

    cout << -1;

    return 0;
}