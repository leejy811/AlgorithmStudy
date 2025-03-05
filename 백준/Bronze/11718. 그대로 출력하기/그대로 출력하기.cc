#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<string> s;

    while (1)
    {
        string tmp;
        getline(cin, tmp);
        if (cin.eof()) break;
        s.push_back(tmp);
    }

    for (string str : s)
    {
        cout << str << "\n";
    }

    return 0;
}