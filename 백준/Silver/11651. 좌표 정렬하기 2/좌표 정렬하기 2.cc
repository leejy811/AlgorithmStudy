#include <bits/stdc++.h>

using namespace std;

bool cmp(pair<int, int> p1, pair<int, int> p2)
{
    if (p1.second == p2.second)
        return p1.first < p2.first;
    else
        return p1.second < p2.second;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;

    cin >> n;

    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].first >> v[i].second;
    }

    sort(v.begin(), v.end(), cmp);

    for (pair<int, int> p : v)
    {
        cout << p.first << " " << p.second << "\n";
    }

    return 0;
}