#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    vector<string> str;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        str.push_back(s);
    }

    for (int i = 0; i < n; i++)
    {
        cout << str[i].front() << str[i].back() << "\n";
    }

    return 0;
}