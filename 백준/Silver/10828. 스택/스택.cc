#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    stack<int> s;

    cin >> n;

    for (int i = 0; i <= n; i++)
    {
        string str;
        getline(cin, str);

        int num = 0;
        char front = str[0];
        switch (front)
        {
        case 'p':
            if (str.size() == 3)
            {
                if (s.empty())
                    cout << "-1\n";
                else
                {
                    cout << s.top() << "\n";
                    s.pop();
                }
            }
            else
            {
                str.erase(0, 5);
                s.push(stoi(str));
            }
            break;
        case 's':
            cout << s.size() << "\n";
            break;
        case 'e':
            num = s.empty() ? 1 : 0;
            cout << num << "\n";
            break;
        case 't':
            num = s.empty() ? -1 : s.top();
            cout << num << "\n";
            break;
        default:
            break;
        }
    }

    return 0;
}