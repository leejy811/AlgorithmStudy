#include <bits/stdc++.h>
using namespace std;

vector<int> p;

int find(int x)
{
    if (p[x] < 0)
        return x;

    return p[x] = find(p[x]);
}

bool uni(int x, int y)
{
    x = find(x);
    y = find(y);

    if (x == y)
        return false;

    if (p[x] < p[y])
        swap(x, y);

    if (p[x] == p[y])
        p[x]--;

    p[y] = x;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;

    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int n, k;
        cin >> n >> k;

        p.resize(n);
        fill(p.begin(), p.end(), -1);

        for (int j = 0; j < k; j++)
        {
            int a, b;
            cin >> a >> b;
            uni(a, b);
        }

        cout << "Scenario " << i + 1 << ":\n";
        int m;
        cin >> m;
        for (int j = 0; j < m; j++)
        {
            int u, v;
            cin >> u >> v;
            if (find(u) == find(v))
                cout << "1\n";
            else
                cout << "0\n";
        }
        cout << "\n";
    }

    return 0;
}