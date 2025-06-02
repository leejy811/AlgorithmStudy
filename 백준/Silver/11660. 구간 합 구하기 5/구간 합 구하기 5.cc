#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> v(n + 1);
    for (int i = 1; i <= n; i++)
    {
        v[i].resize(n + 1);
        for (int j = 1; j <= n; j++)
            cin >> v[i][j];
    }

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            v[i][j] += v[i][j - 1];

    for (int i = 0; i < m; i++)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        int sum = 0;
        for (int j = x1; j <= x2; j++)
            sum += v[j][y2] - v[j][y1 - 1];

        cout << sum << '\n';
    }

    return 0;
}