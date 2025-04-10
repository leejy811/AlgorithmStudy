#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;

    cin >> n >> m;

    vector<vector<int>> v(n);
    map<pair<int, int>, int> mp;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;

        for (int j = 0; j < m; j++)
        {
            v[i].push_back(s[j] - '0');
            if (s[j] == '1')
            {
                mp[make_pair(i, j)] = cnt++;
            }
        }
    }

    vector<set<int>> g(cnt);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!v[i][j]) continue;

            if (i - 1 >= 0 && v[i - 1][j])
            {
                g[mp[make_pair(i - 1, j)]].insert(mp[make_pair(i, j)]);
                g[mp[make_pair(i, j)]].insert(mp[make_pair(i - 1, j)]);
            }

            if (i + 1 < n && v[i + 1][j])
            {
                g[mp[make_pair(i + 1, j)]].insert(mp[make_pair(i, j)]);
                g[mp[make_pair(i, j)]].insert(mp[make_pair(i + 1, j)]);
            }

            if (j - 1 >= 0 && v[i][j - 1])
            {
                g[mp[make_pair(i, j - 1)]].insert(mp[make_pair(i, j)]);
                g[mp[make_pair(i, j)]].insert(mp[make_pair(i, j - 1)]);
            }

            if (j + 1 < m && v[i][j + 1])
            {
                g[mp[make_pair(i, j + 1)]].insert(mp[make_pair(i, j)]);
                g[mp[make_pair(i, j)]].insert(mp[make_pair(i, j + 1)]);
            }
        }
    }

    queue<pair<int, int>> q;
    vector<int> visit(cnt);

    q.push(make_pair(0, 0));
    visit[0] = true;
    while (!q.empty())
    {
        pair<int, int> f = q.front();

        if (mp[make_pair(n - 1, m - 1)] == f.first)
        {
            cout << f.second + 1;
            break;
        }

        q.pop();

        for (int x : g[f.first])
        {
            if (!visit[x])
            {
                q.push(make_pair(x, f.second + 1));
                visit[x] = true;
            }
        }
    }

    return 0;
}