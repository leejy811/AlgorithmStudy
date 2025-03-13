#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int num;

    cin >> num;

    int m = num / 5, n = num / 3;

    if (m == 0)
    {
        if (num % 3 == 0)
            cout << n;
        else
            cout << -1;
        return 0;
    }

    vector<vector<int>> v(m + 1);
    int mincnt = num;

    for (int i = 0; i <= m; i++)
    {
        v[i].resize(n + 1);
    }

    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            v[i][j] = (i * 5) + (j * 3);
            if (v[i][j] == num && mincnt > i + j)
            {
                mincnt = i + j;
            }
        }
    }

    if (mincnt == num)
        cout << -1;
    else
        cout << mincnt;

    return 0;
}