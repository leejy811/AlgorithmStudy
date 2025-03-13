#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        stack<char> bracket;
        string s;
        cin >> s;

        for (char c : s)
        {
            if (c == '(')
            {
                bracket.push(c);
            }
            else if (c == ')')
            {
                if (!bracket.empty() && bracket.top() == '(')
                    bracket.pop();
                else
                    bracket.push(c);
            }
        }

        if (bracket.empty())
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}