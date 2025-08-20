#include <bits/stdc++.h>
using namespace std;

int max_path = 0;
int max_node = 0;
int v;
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

    if (isLast && max_path < wei)
    {
        max_path = wei;
        max_node = st;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> v;

    tree.resize(v);
    for (int i = 0; i < v; i++)
    {
        int x;
        cin >> x;
        x--;
        while (1)
        {
            int y, c;
            cin >> y;
            if (y == -1) break;
            cin >> c;

            y--;
            tree[x].push_back({ y, c });
        }
    }

    vis.resize(v);
    func(0, 0);
    fill(vis.begin(), vis.end(), false);
    func(max_node, 0);

    cout << max_path;

    return 0;
}