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

    if (p[x] == p[y])
        p[x]--;

    if (p[x] < p[y])
        swap(x, y);

    p[y] = x;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int v, e;

    cin >> v >> e;

    p.resize(v);
    fill(p.begin(), p.end(), -1);
    vector<tuple<int, int, int>> vt(e);
    for (int i = 0; i < e; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        vt[i] = { c, --a, --b };
    }

    sort(vt.begin(), vt.end());

    int sum = 0;
    int cnt = 0;
    for (int i = 0; i < e; i++)
    {
        int cost = get<0>(vt[i]);
        int x = get<1>(vt[i]);
        int y = get<2>(vt[i]);

        if (!uni(x, y)) continue;

        sum += cost;
        cnt++;
        if (cnt == v - 1) break;
    }

    cout << sum;

    return 0;
}