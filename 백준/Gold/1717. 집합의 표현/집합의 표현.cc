#include <bits/stdc++.h>
using namespace std;

vector<int> v;

int find(int x)
{
    if (v[x] < 0)
        return x;

    return v[x] = find(v[x]);
}

bool uni(int x, int y)
{
    x = find(x);
    y = find(y);

    if (x == y)
        return false;

    if (v[x] < v[y])
        swap(x, y);

    if (v[x] == v[y])
        v[x]--;

    v[y] = x;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;

    cin >> n >> m;

    v.resize(n + 1);
    fill(v.begin(), v.end(), -1);
    for (int i = 0; i < m; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;

        if (x == 1)
        {
            if (find(y) == find(z))
                cout << "YES\n";
            else
                cout << "NO\n";
        }
        else
        {
            uni(y, z);
        }
    }

    return 0;
}