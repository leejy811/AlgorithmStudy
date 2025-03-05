#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string tmp;
    vector<string> s;

    while (1)
    {
        cin >> tmp;
        if (cin.eof()) break;
        s.push_back(tmp);
    }

    cout << s.size();

    return 0;
}