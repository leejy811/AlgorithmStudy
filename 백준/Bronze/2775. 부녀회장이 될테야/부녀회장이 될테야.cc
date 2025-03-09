#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;

    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int k, n;
        cin >> k >> n;
        vector<int> prev(n);
        vector<int> cur(n);

        for (int j = 0; j < n; j++)
        {
            prev[j] = j + 1;
        }

        for (int j = 1; j < k; j++)
        {
            for (int m = 0; m < n; m++)
            {
                cur[m] = accumulate(prev.begin(), prev.begin() + m + 1, 0);
            }
            prev = cur;
        }

        cout << accumulate(prev.begin(), prev.end(), 0) << "\n";
    }

    return 0;
}