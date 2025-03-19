#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;

    cin >> n >> m;

    map<string, string> v;
    for (int i = 0; i < n; i++)
    {
        string site, pw;
        cin >> site >> pw;
        v[site] = pw;
    }

    for (int i = 0; i < m; i++)
    {
        string s;
        cin >> s;
        cout << v[s] << '\n';
    }

    return 0;
}