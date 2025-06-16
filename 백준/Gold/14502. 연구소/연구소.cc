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

    queue<pair<int, int>> q;
    vector<pair<int, int>> b;
    for (int i = 0; i < n; i++)
    {
        v[i].resize(m);
        for (int j = 0; j < m; j++)
        {
            cin >> v[i][j];
            if (v[i][j] == 0)
                b.push_back({ i, j });
            else if (v[i][j] == 2)
                q.push({ i, j });
        }
    }

    vector<bool> temp(b.size());
    fill(temp.end() - 3, temp.end(), true);

    int max = 0;
    do
    {
        int cnt = b.size() - 3;
        vector<vector<int>> area(v);

        for (int i = 0; i < temp.size(); i++)
            if (temp[i])
                area[b[i].first][b[i].second] = 1;

        queue<pair<int, int>> q_temp(q);
        while (!q_temp.empty())
        {
            pair<int, int> p = q_temp.front();
            q_temp.pop();

            for (int dir = 0; dir < 4; dir++)
            {
                int x = p.first + dx[dir];
                int y = p.second + dy[dir];

                if (x < 0 || y < 0 || x >= n || y >= m) continue;
                if (area[x][y] != 0) continue;

                area[x][y] = 2;
                q_temp.push({ x, y });
                cnt--;
            }
        }

        if (max < cnt)
            max = cnt;
    } while (next_permutation(temp.begin(), temp.end()));

    cout << max;

    return 0;
}