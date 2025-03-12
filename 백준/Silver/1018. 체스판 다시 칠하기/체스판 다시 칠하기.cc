#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int m, n;

    cin >> m >> n;

    vector<vector<char>> v(m);

    for (int i = 0; i < m; i++)
    {
        v[i].resize(n);
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> v[i][j];
        }
    }

    int minCnt = m * n;
    for (int i = 0; i <= m - 8; i++)
    {
        for (int j = 0; j <= n - 8; j++)
        {
            int cntB = 0;
            for (int k = 0; k < 8; k++)
            {
                for (int l = 0; l < 8; l++)
                {
                    char target = (k % 2 == l % 2) ? 'B' : 'W';
                    if (target != v[i + k][j + l]) cntB++;
                }
            }

            int cntW = 0;
            for (int k = 0; k < 8; k++)
            {
                for (int l = 0; l < 8; l++)
                {
                    char target = (k % 2 == l % 2) ? 'W' : 'B';
                    if (target != v[i + k][j + l]) cntW++;
                }
            }

            int cnt = (cntB < cntW) ? cntB : cntW;
            if (minCnt > cnt) minCnt = cnt;
        }
    }

    cout << minCnt;

    return 0;
}