#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    map<string, bool> s;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        s[str] = true;
    }

    int cnt = 0;
    for (int i = 0; i < m; i++)
    {
        string str;
        cin >> str;
        if (s[str])
            cnt++;
    }
    
    cout << cnt;

    return 0;
}