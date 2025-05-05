#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;

    cin >> n;

    unordered_set<string> s;

    for (int i = 0; i < n; i++)
    {
        string s1, s2;
        cin >> s1 >> s2;
        if (s2 == "enter")
            s.insert(s1);
        else
            s.erase(s1);
    }

    vector<string> v(s.begin(), s.end());
    sort(v.begin(), v.end(), greater<string>());
    for (auto name : v)
    {
        cout << name << '\n';
    }

    return 0;
}