#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> g(n);
    for (int i = 0; i < m; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        a--;
        b--;
        g[a].push_back({ w, b });
    }

    int a, b;
    cin >> a >> b;
    a--;
    b--;

    vector<int> dist(n);
    fill(dist.begin(), dist.end(), 1e9 * 2);
    dist[a] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({ 0, a });

    while (!pq.empty())
    {
        pair<int, int> p = pq.top();
        pq.pop();

        if (p.first != dist[p.second]) continue;

        for (auto x : g[p.second])
        {
            if (dist[x.second] > x.first + p.first)
            {
                dist[x.second] = x.first + p.first;
                pq.push({ dist[x.second] , x.second });
            }
        }
    }

    cout << dist[b];


    return 0;
}