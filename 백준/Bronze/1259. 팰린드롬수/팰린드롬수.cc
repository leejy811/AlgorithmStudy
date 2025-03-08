#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while (1)
    {
        string s1;
        cin >> s1;
        if (stoi(s1) == 0) break;

        string s2 = s1;
        reverse(s2.begin(), s2.end());
        if (s1 == s2)
            cout << "yes\n";
        else
            cout << "no\n";
    }

    return 0;
}