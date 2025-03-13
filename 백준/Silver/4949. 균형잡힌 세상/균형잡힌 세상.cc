#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while (1)
    {
        stack<char> bracket;
        string s;
        getline(cin, s);
        if (s.size() == 1 && s[0] == '.')
            break;

        for (char c : s)
        {
            if (c == '[' || c == '(')
            {
                bracket.push(c);
            }
            else if (c == ']')
            {
                if (!bracket.empty() && bracket.top() == '[')
                    bracket.pop();
                else
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
            cout << "yes\n";
        else
            cout << "no\n";
    }

    return 0;
}