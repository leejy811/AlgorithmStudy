#include <bits/stdc++.h>
using namespace std;

map<char, int> m;

void init()
{
    vector<int> add = {0, 0, 0, 0, 0, 1, 0, 1};
    int sum = 0;
    for (int i = 0; i < add.size(); i++)
    {
        for (int j = 0; j < 3 + add[i]; j++)
        {
            m['A' + sum + j] = i + 3;
        }
        sum += 3 + add[i];
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    init();
    int res = 0;
    string s;

    cin >> s;

    for (char c : s)
    {
        res += m[c];
    }

    cout << res;

    return 0;
}