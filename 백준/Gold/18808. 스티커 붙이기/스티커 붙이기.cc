#include <bits/stdc++.h>
using namespace std;

vector<vector<bool>> v;
vector<vector<int>> sti;
int r, c;

bool Possible(int x, int y)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (sti[i][j] && v[x + i][y + j])
                return false;
        }
    }

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (sti[i][j])
                v[x + i][y + j] = true;
        }
    }

    return true;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, k;

    cin >> n >> m >> k;

    v.resize(n);
    for (int i = 0; i < n; i++)
    {
        v[i].resize(m);
    }

    sti.resize(11);
    for (int i = 0; i < 11; i++)
    {
        sti[i].resize(11);
    }

    for (int s = 0; s < k; s++)
    {
        cin >> r >> c;

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                cin >> sti[i][j];
            }
        }

        for (int dir = 0; dir < 4; dir++)
        {
            bool possible = false;
            for (int a = 0; a <= n - r; a++)
            {
                for (int b = 0; b <= m - c; b++)
                {
                    if (Possible(a, b))
                    {
                        possible = true;
                        break;
                    }
                }
                if (possible) break;
            }
            if (possible)
                break;

            vector<vector<int>> tmp(11);

            for (int i = 0; i < r; i++)
            {
                tmp[i].resize(11);
                for (int j = 0; j < c; j++)
                {
                    tmp[i][j] = sti[i][j];
                }
            }

            for (int i = 0; i < c; i++)
                for (int j = 0; j < r; j++)
                    sti[i][j] = tmp[r - 1 - j][i];

            swap(r, c);
        }
    }

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (v[i][j])
                cnt++;
        }
    }

    cout << cnt;

    return 0;
}