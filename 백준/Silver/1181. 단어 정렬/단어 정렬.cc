#include <bits/stdc++.h>
using namespace std;

bool cmp(string a, string b)
{
    if (a.size() == b.size())
        return a < b;
    else
        return a.size() < b.size();
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;

    cin >> n;

    vector<string> s(n);
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }

    sort(s.begin(), s.end(), cmp);
    s.erase(unique(s.begin(), s.end()), s.end());

    for (string str : s)
    {
        cout << str << "\n";
    }

    return 0;
}