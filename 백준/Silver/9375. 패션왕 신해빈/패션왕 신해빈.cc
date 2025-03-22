#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;

    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;

        map<string, int> m;
        vector<string> v;
        for (int j = 0; j < n; j++)
        {
            string cloth, kind;
            cin >> cloth >> kind;
            m[kind]++;

            if (m[kind] == 1)
                v.push_back(kind);
        }

        int cnt = 1;
        for (string s : v)
        {
            cnt *= m[s] + 1;
        }

        cout << cnt - 1 << "\n";
    }

    return 0;
}