#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int, int>>> g;
vector<vector<int>> v;

void dijkstra(int st, int n)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({ 0, st });
    v[st].resize(n);
    fill(v[st].begin(), v[st].end(), 1e9);
    v[st][st] = 0;

    while (!pq.empty())
    {
        pair<int, int> p = pq.top();
        pq.pop();

        if (p.first != v[st][p.second]) continue;

        for (pair<int, int> x : g[p.second])
        {
            if (v[st][x.second] < p.first + x.first) continue;
            pq.push({ p.first + x.first, x.second });
            v[st][x.second] = p.first + x.first;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, x;

    cin >> n >> m >> x;

    g.resize(m);
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        g[a].push_back({ c, b });
    }

    v.resize(n);
    for (int i = 0; i < n; i++)
        dijkstra(i, n);

    int max = 0;
    x--;
    for (int i = 0; i < n; i++)
    {
        int dist = v[i][x] + v[x][i];
        if (max < dist) max = dist;
    }

    cout << max;

    return 0;
}