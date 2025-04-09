#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string n;
    int m;

    cin >> n >> m;

    list<char> l;
    list<char>::iterator it = l.begin();

    for (char c : n)
    {
        it = l.insert(it, c);
        it++;
    }

    cin.ignore();
    for (int i = 0; i < m; i++)
    {
        string s;
        getline(cin, s);

        switch (s[0])
        {
        case 'L':
            if (it != l.begin()) it--;
            break;
        case 'D':
            if (it != l.end()) it++;
            break;
        case 'B':
            if (it != l.begin())
            {
                it--;
                it = l.erase(it);
            }
            break;
        case 'P':
            l.insert(it, s[2]);
            break;
        default:
            break;
        }
    }

    for (char c : l)
    {
        cout << c;
    }

    return 0;
}