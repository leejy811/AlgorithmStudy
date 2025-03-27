#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
vector<bool> v;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, b;

    cin >> n >> m >> b;

    vector<vector<int>> v(n);
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        v[i].resize(m);
        for (int j = 0; j < m; j++)
        {
            cin >> v[i][j];
            if (max < v[i][j])
                max = v[i][j];
        }
    }

    int minTime = 2 * max * n * m, minHeight = 0;
    for (int i = 0; i <= max; i++)
    {
        int time = 0, block = b;
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < m; k++)
            {
                if (v[j][k] < i)
                {
                    int x = i - v[j][k];
                    time += x;
                    block -= x;
                }
                else if (v[j][k] > i)
                {
                    int x = v[j][k] - i;
                    time += x * 2;
                    block += x;
                }
            }
        }

        if (time <= minTime && block >= 0)
        {
            minTime = time;
            minHeight = i;
        }
    }

    cout << minTime << " " << minHeight;

    return 0;
}