#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string str;

    cin >> str;

    stack<char> s;
    char prev = '.';
    int cnt = 0, tmp = 1;

    for (char c : str)
    {
        if (c == '(' || c == '[')
        {
            s.push(c);
            tmp *= c == '(' ? 2 : 3;
        }
        else
        {
            if (s.empty() || (s.top() == '(' && c == ']') || (s.top() == '[' && c == ')'))
            {
                cout << 0;
                return 0;
            }

            s.pop();
            if (c == ')')
            {
                if (prev == '(')
                    cnt += tmp;
                tmp /= 2;
            }
            else if (c == ']')
            {
                if (prev == '[')
                    cnt += tmp;
                tmp /= 3;
            }
        }

        prev = c;
    }

    if (!s.empty())
        cout << 0;
    else
        cout << cnt;

    return 0;
}