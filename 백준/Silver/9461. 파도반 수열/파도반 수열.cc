#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;

    cin >> t;

    vector<long long> v = { 1, 1, 1, 2, 2, 3, 4, 5, 7, 9 };
    for (int i = 10; i < 100; i++)
    {
        v.push_back(v[i - 1] + v[i - 5]);
    }

    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;

        cout << v[n - 1] << "\n";
    }

    return 0;
}