#include <bits/stdc++.h>
using namespace std;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;

    cin >> n >> m;

    vector<int> ladder(101);
    vector<int> snake(101);
    for (int i = 1; i <= 100; i++)
    {
        ladder[i] = i;
        snake[i] = i;
    }

    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        ladder[x] = y;
    }

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        snake[u] = v;
    }

    vector<bool> vis(101);
    queue<pair<int, int>> q;
    q.push({ 1, 0 });
    int min = INT_MAX;
    while (!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();

        for (int i = 1; i <= 6; i++)
        {
            int nxt = p.first + i;
            if (nxt > 100) continue;

            if (ladder[nxt] != nxt)
                nxt = ladder[nxt];
            else if (snake[nxt] != nxt)
                nxt = snake[nxt];

            if(vis[nxt]) continue;

            q.push({ nxt, p.second + 1 });
            vis[nxt] = true;
            if (nxt == 100 && min > p.second + 1)
                min = p.second + 1;
        }
    }

    cout << min;

    return 0;
}