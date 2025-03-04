#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<int> res;

    while (1)
    {
        int a, b;
        cin >> a >> b;

        if (cin.eof()) break;

        res.push_back(a + b);
    }

    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << "\n";
    }

    return 0;
}