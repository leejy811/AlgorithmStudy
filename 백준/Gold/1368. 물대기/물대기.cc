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

    int v;

    cin >> v;

    vector<int> c(v);
    for (int i = 0; i < v; i++)
    {
        cin >> c[i];
    }

    vector<vector<int>> g(v);
    for (int i = 0; i < v; i++)
    {
        g[i].resize(v);
        for (int j = 0; j < v; j++)
        {
            cin >> g[i][j];
        }
    }

    vector<tuple<int, int, int>> vt;
    for (int i = 0; i < v; i++)
    {
        for (int j = i + 1; j < v; j++)
        {
            vt.push_back({ g[i][j], i, j });
        }
    }

    for (int i = 0; i < v; i++)
    {
        vt.push_back({ c[i], i, v});
    }

    sort(vt.begin(), vt.end());
    p.resize(v + 1);
    fill(p.begin(), p.end(), -1);
    int sum = 0;
    int cnt = 0;
    for (int i = 0; i < vt.size(); i++)
    {
        int cost = get<0>(vt[i]);
        int x = get<1>(vt[i]);
        int y = get<2>(vt[i]);

        if (!uni(x, y)) continue;

        sum += cost;
        cnt++;
        if (cnt == v) break;
    }

    cout << sum;

    return 0;
}