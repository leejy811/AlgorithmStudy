#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, h;

    cin >> m >> n >> h;

    vector<vector<vector<int>>> v(h);
    vector<vector<vector<int>>> day(h);
    queue<tuple<int, int, int>> q;

    for (int i = 0; i < h; i++)
    {
        v[i].resize(n);
        day[i].resize(n);
        for (int j = 0; j < n; j++)
        {
            v[i][j].resize(m);
            day[i][j].resize(m);
            for (int k = 0; k < m; k++)
            {
                cin >> v[i][j][k];

                if (v[i][j][k] == 1)
                    q.push({ i, j, k });
            }
        }
    }

    vector<int> di = { 1, 0, 0, -1, 0, 0 };
    vector<int> dj = { 0, 1, 0, 0, -1, 0 };
    vector<int> dk = { 0, 0, 1, 0, 0, -1 };
    int cnt = 0;

    tuple<int, int, int> p;
    while (!q.empty())
    {
        p = q.front();
        q.pop();

        for (int k = 0; k < 6; k++)
        {
            int x = get<0>(p) + di[k];
            int y = get<1>(p) + dj[k];
            int z = get<2>(p) + dk[k];

            if (x < 0 || y < 0 || z < 0 || x >= h || y >= n || z >= m) continue;
            if (v[x][y][z] != 0) continue;

            v[x][y][z] = 1;
            q.push({ x, y, z });
            day[x][y][z] = day[get<0>(p)][get<1>(p)][get<2>(p)] + 1;
        }
    }

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < m; k++)
            {
                if (v[i][j][k] == 0)
                {
                    cout << -1;
                    return 0;
                }
            }
        }
    }

    cout << day[get<0>(p)][get<1>(p)][get<2>(p)];

    return 0;
}