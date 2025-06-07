#include <bits/stdc++.h>
using namespace std;

int max_path = 0;
int r, c;
vector<string> v;
vector<bool> vis(26);

void func(int x, int y, int cnt)
{
    max_path = max(cnt, max_path);

    if (x > 0 && !vis[v[x - 1][y] - 'A'])
    {
        vis[v[x - 1][y] - 'A'] = true;
        func(x - 1, y, cnt + 1);
        vis[v[x - 1][y] - 'A'] = false;
    }

    if (y > 0 && !vis[v[x][y - 1] - 'A'])
    {
        vis[v[x][y - 1] - 'A'] = true;
        func(x, y - 1, cnt + 1);
        vis[v[x][y - 1] - 'A'] = false;
    }

    if (x < r - 1 && !vis[v[x + 1][y] - 'A'])
    {
        vis[v[x + 1][y] - 'A'] = true;
        func(x + 1, y, cnt + 1);
        vis[v[x + 1][y] - 'A'] = false;
    }

    if (y < c - 1 && !vis[v[x][y + 1] - 'A'])
    {
        vis[v[x][y + 1] - 'A'] = true;
        func(x, y + 1, cnt + 1);
        vis[v[x][y + 1] - 'A'] = false;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> r >> c;

    v.resize(r);
    for (int i = 0; i < r; i++)
    {
        cin >> v[i];
    }

    vis[v[0][0] - 'A'] = true;
    func(0, 0, 1);

    cout << max_path;

    return 0;
}