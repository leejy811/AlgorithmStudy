#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    queue<int> q;

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
                if (q.empty())
                    cout << "-1\n";
                else
                {
                    cout << q.front() << "\n";
                    q.pop();
                }
            }
            else
            {
                str.erase(0, 5);
                q.push(stoi(str));
            }
            break;
        case 's':
            cout << q.size() << "\n";
            break;
        case 'e':
            num = q.empty() ? 1 : 0;
            cout << num << "\n";
            break;
        case 'f':
            num = q.empty() ? -1 : q.front();
            cout << num << "\n";
            break;
        case 'b':
            num = q.empty() ? -1 : q.back();
            cout << num << "\n";
            break;
        default:
            break;
        }
    }

    return 0;
}