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
    vector<vector<bool>> visit(n);

    for (int i = 0; i < n; i++)
    {
        v[i].resize(m);
        visit[i].resize(m);
        for (int j = 0; j < m; j++)
        {
            cin >> v[i][j];

            visit[i][j] = !v[i][j];
        }
    }

    vector<int> di = { 1, 0, -1, 0 };
    vector<int> dj = { 0, 1, 0, -1 };
    int max = 0, cnt = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (visit[i][j]) continue;

            int tmp = 0;

            queue<pair<int, int>> q;
            visit[i][j] = true;
            q.push({ i, j });
            tmp++;
            while (!q.empty())
            {
                pair<int, int> p = q.front();
                q.pop();

                for (int k = 0; k < 4; k++)
                {
                    int x = p.first + di[k];
                    int y = p.second + dj[k];

                    if (x < 0 || y < 0 || x >= n || y >= m) continue;
                    if (visit[x][y]) continue;

                    visit[x][y] = true;
                    q.push({ x, y });
                    tmp++;
                }
            }

            cnt++;
            if (max < tmp)
                max = tmp;
        }
    }

    cout << cnt << '\n' << max;

    return 0;
}