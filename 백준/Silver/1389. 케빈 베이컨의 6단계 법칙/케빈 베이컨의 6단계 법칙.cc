#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;

    cin >> n >> m;

    vector<vector<int>> g(n);

    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;

        x--;
        y--;
        if (find(g[x].begin(), g[x].end(), y) == g[x].end())
            g[x].push_back(y);
        if (find(g[y].begin(), g[y].end(), x) == g[y].end())
            g[y].push_back(x);
    }

    int min = INT_MAX;
    int minIdx = 0;

    queue<pair<int, int>> q;
    vector<bool> v(n);
    for (int i = 0; i < n; i++)
    {
        v.clear();
        v.resize(n);

        int cnt = 0;
        q.push(make_pair(i, cnt));
        v[i] = true;
        while (!q.empty())
        {
            pair<int, int> f = q.front();
            q.pop();

            for (int i : g[f.first])
            {
                if (!v[i])
                {
                    v[i] = true;
                    cnt += f.second + 1;
                    q.push(make_pair(i, f.second + 1));
                }
            }
        }

        if (min > cnt)
        {
            min = cnt;
            minIdx = i;
        }
    }

    cout << minIdx + 1;

    return 0;
}