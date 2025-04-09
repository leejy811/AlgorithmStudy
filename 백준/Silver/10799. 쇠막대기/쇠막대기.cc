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
    int cnt = 0;

    for (char c : str)
    {
        if (c == '(')
            s.push(c);
        else
        {
            s.pop();
            if (prev == '(')
                cnt += s.size();
            else
                cnt++;
        }

        prev = c;
    }

    cout << cnt;

    return 0;
}