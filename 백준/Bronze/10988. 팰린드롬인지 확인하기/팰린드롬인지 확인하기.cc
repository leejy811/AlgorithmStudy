#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s1, s2;

    cin >> s1;

    s2 = s1;
    reverse(s2.begin(), s2.end());

    int res = (s1 == s2) ? 1 : 0;

    cout << res;

    return 0;
}