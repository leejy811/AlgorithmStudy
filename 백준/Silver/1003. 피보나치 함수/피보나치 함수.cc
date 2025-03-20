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
        vector<int> f0;
        vector<int> f1;

        f0.push_back(1);
        f0.push_back(0);
        f0.push_back(1);

        f1.push_back(0);
        f1.push_back(1);
        f1.push_back(1);

        for (int i = 3; i <= n; i++)
        {
            f0.push_back(f0[i - 1] + f0[i - 2]);
            f1.push_back(f1[i - 1] + f1[i - 2]);
        }

        cout << f0[n] << " " << f1[n] << "\n";
    }

    return 0;
}