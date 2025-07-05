#include <bits/stdc++.h>
using namespace std;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int r, c, t;

    cin >> r >> c >> t;

    vector<vector<int>> v(r);

    vector<pair<int, int>> air;
    for (int i = 0; i < r; i++)
    {
        v[i].resize(c);
        for (int j = 0; j < c; j++)
        {
            cin >> v[i][j];

            if (v[i][j] == -1)
                air.push_back({ i, j });
        }
    }

    while (t--)
    {
        vector<vector<int>> tmp(v);
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (v[i][j] <= 0) continue;

                int amount = v[i][j] / 5;
                for (int dir = 0; dir < 4; dir++)
                {
                    int nx = i + dx[dir];
                    int ny = j + dy[dir];

                    if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
                    if (v[nx][ny] == -1) continue;

                    tmp[nx][ny] += amount;
                    tmp[i][j] -= amount;
                }
            }
        }

        v = tmp;

        pair<int, int> cur = air[0];
        cur = { cur.first - 1, cur.second };
        for (int dir = 0; dir < 4; dir++)
        {
            while (1)
            {
                pair<int, int> nxt = { cur.first + dx[dir] * -1, cur.second + dy[dir] };
                if (nxt.first < 0 || nxt.second < 0
                    || nxt.first >= r || nxt.second >= c) break;
                if (v[nxt.first][nxt.second] == -1) break;
                if (dx[dir] == -1 && v[cur.first][0] == -1) break;

                v[cur.first][cur.second] = v[nxt.first][nxt.second];
                cur = nxt;
            }
        }
        v[air[0].first][air[0].second + 1] = 0;

        cur = air[1];
        cur = { cur.first + 1, cur.second };
        for (int dir = 0; dir < 4; dir++)
        {
            while (1)
            {
                pair<int, int> nxt = { cur.first + dx[dir], cur.second + dy[dir] };
                if (nxt.first < 0 || nxt.second < 0
                    || nxt.first >= r || nxt.second >= c) break;
                if (v[nxt.first][nxt.second] == -1) break;
                if (dx[dir] == -1 && v[cur.first][0] == -1) break;

                v[cur.first][cur.second] = v[nxt.first][nxt.second];
                cur = nxt;
            }
        }
        v[air[1].first][air[1].second + 1] = 0;
    }

    int res = 0;
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            if (v[i][j] > 0)
                res += v[i][j];

    cout << res;

    return 0;
}