#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;

    cin >> m >> n;

    vector<vector<int>> v(n);
    vector<vector<int>> day(n);
    queue<pair<int, int>> q;

    for (int i = 0; i < n; i++)
    {
        v[i].resize(m);
        day[i].resize(m);
        for (int j = 0; j < m; j++)
        {
            cin >> v[i][j];

            if (v[i][j] == 1)
                q.push({ i, j });
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
            if (v[x][y] != 0) continue;

            v[x][y] = 1;
            q.push({ x, y });
            day[x][y] = day[p.first][p.second] + 1;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (v[i][j] == 0)
            {
                cout << -1;
                return 0;
            }
        }
    }

    cout << day[p.first][p.second];

    return 0;
}