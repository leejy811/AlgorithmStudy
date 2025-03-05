#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;
    vector<int> pos(26, -1);

    cin >> s;

    for (int i = 0;i < s.size();i++)
    {
        if (pos[s[i] - 'a'] == -1)
            pos[s[i] - 'a'] = i;
    }

    for (int p : pos)
    {
        cout << p << " ";
    }

    return 0;
}