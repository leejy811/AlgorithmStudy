#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;

    cin >> n >> m;

    vector<string> v(n);
    vector<vector<int>> distF(n);
    vector<vector<int>> distJ(n);
    queue<pair<int, int>> jq;
    queue<pair<int, int>> fq;

    for (int i = 0; i < n; i++)
    {
        distF[i].resize(m);
        distJ[i].resize(m);
        cin >> v[i];
        for (int j = 0; j < m; j++)
        {
            if (v[i][j] == 'J')
                jq.push({ i, j });
            else
                distJ[i][j] = -1;

            if (v[i][j] == 'F')
                fq.push({ i, j });
            else
                distF[i][j] = -1;
        }
    }

    vector<int> di = { 1, 0, -1, 0 };
    vector<int> dj = { 0, 1, 0, -1 };

    while (!fq.empty())
    {
        pair<int, int> p = fq.front();
        fq.pop();

        for (int k = 0; k < 4; k++)
        {
            int x = p.first + di[k];
            int y = p.second + dj[k];

            if (x < 0 || y < 0 || x >= n || y >= m) continue;
            if (distF[x][y] != -1 || v[x][y] == '#') continue;

            fq.push({ x, y });
            distF[x][y] = distF[p.first][p.second] + 1;
        }
    }

    while (!jq.empty())
    {
        pair<int, int> p = jq.front();
        jq.pop();

        for (int k = 0; k < 4; k++)
        {
            int x = p.first + di[k];
            int y = p.second + dj[k];

            if (x < 0 || y < 0 || x >= n || y >= m)
            {
                cout << distJ[p.first][p.second] + 1;
                return 0;
            }
            if (distJ[x][y] >= 0 || v[x][y] == '#') continue;
            if (distF[x][y] != -1 && distJ[p.first][p.second] + 1 >= distF[x][y]) continue;

            jq.push({ x, y });
            distJ[x][y] = distJ[p.first][p.second] + 1;
        }
    }

    cout << "IMPOSSIBLE";

    return 0;
}