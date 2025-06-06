#include <bits/stdc++.h>
using namespace std;

const int INF = 1e8 * 2 + 10;
int n;
vector<vector<pair<int, int>>> g;

int path(int st, int en)
{
    vector<int> dist(n + 1);
    for (int i = 1; i <= n; i++)
        dist[i] = INF;
    dist[st] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({ 0, st });
    while (!pq.empty())
    {
        int wei, node;
        tie(wei, node) = pq.top();
        pq.pop();

        if (dist[node] != wei) continue;

        for (pair<int, int> p : g[node])
        {
            if (dist[p.second] > dist[node] + p.first)
            {
                dist[p.second] = dist[node] + p.first;
                pq.push({ dist[p.second] ,p.second });
            }
        }
    }

    return dist[en];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int e;

    cin >> n >> e;

    g.resize(n + 1);
    for (int i = 0; i < e; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back({ c, b });
        g[b].push_back({ c, a });
    }

    int v1, v2;
    cin >> v1 >> v2;

    int p1 = path(1, v1) + path(v1, v2) + path(v2, n);
    int p2 = path(1, v2) + path(v2, v1) + path(v1, n);
    int p = min(p1, p2);
    if (p >= INF)
        cout << -1;
    else
        cout << p;

    return 0;
}