#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int m;

    cin >> m;

    set<int> allS;
    for (int i = 1; i <= 20; i++)
    {
        allS.insert(i);
    }

    set<int> s;
    for (int i = 0; i < m; i++)
    {
        string c;
        cin >> c;

        int x;
        if (c != "all" && c != "empty")
            cin >> x;

        switch (c[0])
        {
        case 'a':
            if (c == "all")
                s = allS;
            else
                s.insert(x);
            break;
        case 'r':
            s.erase(x);
            break;
        case 'c':
            if (s.find(x) == s.end())
                cout << 0 << "\n";
            else
                cout << 1 << "\n";
            break;
        case 't':
            if (s.find(x) == s.end())
                s.insert(x);
            else
                s.erase(x);
            break;
        case 'e':
            s.clear();
            break;
        default:
            break;
        }
    }

    return 0;
}