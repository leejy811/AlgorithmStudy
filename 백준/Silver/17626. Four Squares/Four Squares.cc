#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;

    cin >> n;

    vector<int> v(n + 1);

    for (int i = 1; i <= min(n, 3); i++)
    {
        v[i] = i;
    }

    for (int i = 4; i <= n; i++)
    {
        int sq = sqrt(i);

        if (sq * sq == i)
        {
            v[i] = 1;
            continue;
        }

        int m = 4;
        for (int j = 0; j < sq; j++)
        {
            int id = pow(sq - j, 2);
            m = min(m, v[id] + v[i - id]);
        }
        v[i] = m;
    }

    cout << v[n];

    return 0;
}