#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second || (a.second == b.second && a.first < b.first);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;

    cin >> n;

    vector<pair<int, int>> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i].first >> v[i].second;
    }

    sort(v.begin(), v.end(), cmp);

    int cnt = 1, end = v[0].second;
    for (int i = 1; i < n; i++)
    {
        if (v[i].first >= end)
        {
            cnt++;
            end = v[i].second;
        }
    }

    cout << cnt;

    return 0;
}