#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
vector<int> v;
vector<int> cntV;
int cnt = 0;

void Visit(int idx)
{
    v[idx] = true;
    cntV[cnt]++;

    for (int i : g[idx])
    {
        if (!v[i])
            Visit(i);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;

    cin >> n;

    map<pair<int, int>, int> m;
    vector<pair<int, int>> pv;

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;

        for (int j = 0; j < n; j++)
        {
            int x = s[j] - '0';

            if (x == 1)
            {
                m[make_pair(i, j)] = cnt;
                pv.push_back(make_pair(i, j));
                cnt++;
            }
        }
    }

    g.resize(pv.size());
    v.resize(pv.size());
    for (int i = 0; i < pv.size(); i++)
    {
        pair<int, int> p1 = make_pair(pv[i].first - 1, pv[i].second);
        pair<int, int> p2 = make_pair(pv[i].first + 1, pv[i].second);
        pair<int, int> p3 = make_pair(pv[i].first, pv[i].second - 1);
        pair<int, int> p4 = make_pair(pv[i].first, pv[i].second + 1);

        if (find(pv.begin(), pv.end(), p1) != pv.end())
        {
            if (find(g[i].begin(), g[i].end(), m[p1]) == g[i].end())
                g[i].push_back(m[p1]);

            if (find(g[m[p1]].begin(), g[m[p1]].end(), i) == g[m[p1]].end())
                g[m[p1]].push_back(i);
        }
        if (find(pv.begin(), pv.end(), p2) != pv.end())
        {
            if (find(g[i].begin(), g[i].end(), m[p2]) == g[i].end())
                g[i].push_back(m[p2]);

            if (find(g[m[p2]].begin(), g[m[p2]].end(), i) == g[m[p2]].end())
                g[m[p2]].push_back(i);
        }
        if (find(pv.begin(), pv.end(), p3) != pv.end())
        {
            if (find(g[i].begin(), g[i].end(), m[p3]) == g[i].end())
                g[i].push_back(m[p3]);

            if (find(g[m[p3]].begin(), g[m[p3]].end(), i) == g[m[p3]].end())
                g[m[p3]].push_back(i);
        }
        if (find(pv.begin(), pv.end(), p4) != pv.end())
        {
            if (find(g[i].begin(), g[i].end(), m[p4]) == g[i].end())
                g[i].push_back(m[p4]);

            if (find(g[m[p4]].begin(), g[m[p4]].end(), i) == g[m[p4]].end())
                g[m[p4]].push_back(i);
        }
    }

    cnt = 0;
    while (find(v.begin(), v.end(), false) != v.end())
    {
        int idx = find(v.begin(), v.end(), false) - v.begin();
        cntV.push_back(0);
        Visit(idx);
        cnt++;
    }
    sort(cntV.begin(), cntV.end());

    cout << cnt << '\n';

    for (int i : cntV)
    {
        cout << i << '\n';
    }

    return 0;
}