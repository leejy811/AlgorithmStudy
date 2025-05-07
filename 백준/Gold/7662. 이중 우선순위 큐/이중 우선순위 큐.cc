#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;

    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int k;
        cin >> k;

        multiset<int> s;
        for (int j = 0; j < k; j++)
        {
            char c;
            int n;
            cin >> c >> n;

            if (c == 'I')
            {
                s.insert(n);
            }
            if (c == 'D' && !s.empty())
            {
                if (n == 1)
                {
                    auto it = s.end();
                    it--;
                    s.erase(it);
                }
                else
                    s.erase(s.begin());
            }
        }

        if (s.empty())
            cout << "EMPTY\n";
        else
        {
            auto it = s.end();
            it--;
            cout << *it << ' ' << *s.begin() << '\n';
        }
    }

    return 0;
}