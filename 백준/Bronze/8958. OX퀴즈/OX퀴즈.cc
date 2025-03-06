#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;

        int cnt = 0;
        int sum = 0;
        for (char c : s)
        {
            if (c == 'O')
            {
                cnt++;
                sum += cnt;
            }
            else if (c == 'X')
                cnt = 0;
        }

        cout << sum << "\n";
    }

    return 0;
}