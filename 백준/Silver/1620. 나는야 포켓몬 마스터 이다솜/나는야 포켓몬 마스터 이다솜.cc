#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;

    cin >> n >> m;

    map<string, int> si;
    vector<string> v(n);
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        si[s] = i + 1;
        v[i] = s;
    }

    for (int i = 0; i < m; i++)
    {
        string s;
        cin >> s;
        if (s[0] < 65)
            cout << v[stoi(s) - 1];
        else
            cout << si[s];
        cout << "\n";
    }

    return 0;
}