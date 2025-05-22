#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int v, e, k;

    cin >> v >> e >> k;
    k--;
    vector<vector<pair<int, int>>> adj(v);

    for (int i = 0; i < e; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        a--;
        b--;
        adj[a].push_back({ w, b });
    }

    vector<int> d(v);
    for (int i = 0; i < v; i++)
    {
        if (i != k)
            d[i] = 1e9 + 10;
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({ 0, k });

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
                pq.push({ d[x.second] , x.second });
            }
        }
    }

    for (int i = 0; i < v; i++)
    {
        if (d[i] == 1e9 + 10)
            cout << "INF\n";
        else
            cout << d[i] << '\n';
    }

    return 0;
}