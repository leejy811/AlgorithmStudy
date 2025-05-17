#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;

    cin >> n >> m;

    vector<vector<int>> g(n + 1);
    vector<int> ind(n + 1);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        ind[y]++;
    }

    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (ind[i] == 0)
            q.push(i);
    }

    while (!q.empty())
    {
        int f = q.front();
        q.pop();
        cout << f << ' ';

        for (int i : g[f])
        {
            ind[i]--;
            if (ind[i] == 0)
                q.push(i);
        }
    }

    return 0;
}