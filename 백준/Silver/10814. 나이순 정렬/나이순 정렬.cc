#include <bits/stdc++.h>

using namespace std;

bool cmp(pair<int, string> p1, pair<int, string> p2)
{
    return p1.first < p2.first;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;

    cin >> n;

    vector<pair<int, string>> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].first >> v[i].second;
    }

    stable_sort(v.begin(), v.end(), cmp);

    for (pair<int, string> p : v)
    {
        cout << p.first << " " << p.second << "\n";
    }

    return 0;
}