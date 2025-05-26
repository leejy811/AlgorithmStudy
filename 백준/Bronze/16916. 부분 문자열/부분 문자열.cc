#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s, p;
    cin >> s >> p;

    vector<int> f(p.size());

    int j = 0, i;
    for (i = 1; i < f.size(); i++)
    {
        while (j > 0 && p[i] != p[j]) j = f[j - 1];
        if (p[i] == p[j]) f[i] = ++j;
    }

    i = 0;
    j = 0;

    while (j != p.size() && i != s.size())
    {
        if (s[i] == p[j])
        {
            i++;
            j++;
        }
        else
        {
            if (j == 0) i++;
            else j = f[j - 1];
        }
    }

    if (j == p.size())
        cout << '1';
    else
        cout << '0';

    return 0;
}