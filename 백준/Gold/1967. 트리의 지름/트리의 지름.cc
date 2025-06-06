#include <bits/stdc++.h>
using namespace std;

int max_path = 0;
int n;
vector<vector<pair<int, int>>> tree;
vector<bool> vis;

void func(int st, int wei)
{
    vis[st] = true;
    bool isLast = true;
    for (pair<int, int> x : tree[st])
    {
        if (vis[x.first]) continue;

        isLast = false;
        func(x.first, wei + x.second);
    }

    if (isLast)
        max_path = max(max_path, wei);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    tree.resize(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        tree[a].push_back({ b, c });
        tree[b].push_back({ a, c });
    }

    for (int i = 1; i <= n; i++)
    {
        vis.clear();
        vis.resize(n + 1);
        func(i, 0);
    }

    cout << max_path;

    return 0;
}