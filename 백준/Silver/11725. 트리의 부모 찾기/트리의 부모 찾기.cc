#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;

    cin >> n;

    vector<vector<int>> v(n + 1);
    for (int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }

    queue<int> q;
    vector<int> p(n + 1);
    q.push(1);
    p[1] = -1;

    while (!q.empty())
    {
        int f = q.front();
        q.pop();

        for (int x : v[f])
        {
            if (p[x]) continue;

            q.push(x);
            p[x] = f;
        }
    }

    for (int i = 2; i <= n; i++)
    {
        cout << p[i] << '\n';
    }

    return 0;
}