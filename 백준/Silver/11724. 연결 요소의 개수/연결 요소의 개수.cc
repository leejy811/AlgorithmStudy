#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
vector<bool> v;

void Visit(int idx)
{
    v[idx] = true;
    for (int i : g[idx])
    {
        if (!v[i])
            Visit(i);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;

    cin >> n >> m;

    g.resize(n);
    v.resize(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        u--;
        v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int cnt = 0;
    while (find(v.begin(), v.end(), false) != v.end())
    {
        int idx = find(v.begin(), v.end(), false) - v.begin();
        Visit(idx);
        cnt++;
    }

    cout << cnt;

    return 0;
}