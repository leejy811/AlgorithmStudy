#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int v, e;

    cin >> v >> e;
    vector<vector<pair<int, int>>> adj(v);

    for (int i = 0; i < e; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        a--;
        b--;
        adj[a].push_back({ w, b });
    }

    int st, en;
    cin >> st >> en;
    st--; en--;

    vector<int> d(v);
    vector<int> pre(v);
    for (int i = 0; i < v; i++)
    {
        if (i != st)
            d[i] = 1e9 + 10;
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({ 0, st });

    while (!pq.empty())
    {
        int wei, ver;
        tie(wei, ver) = pq.top();
        pq.pop();
        if (d[ver] != wei) continue;

        for (auto x : adj[ver])
        {
            if (d[x.second] > d[ver] + x.first)
            {
                d[x.second] = d[ver] + x.first;
                pre[x.second] = ver;
                pq.push({ d[x.second] , x.second });
            }
        }
    }

    cout << d[en] << '\n';

    int prev = en;
    vector<int> path;
    while (prev != st)
    {
        path.push_back(prev + 1);
        prev = pre[prev];
    }
    path.push_back(st + 1);

    cout << path.size() << '\n';
    for (int i = path.size(); i > 0; i--)
        cout << path[i - 1] << ' ';

    return 0;
}