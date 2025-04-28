#include <bits/stdc++.h>
using namespace std;

vector<int> v(2000001);

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v[x + 1000000]++;
    }

    for (int i = 0; i <= 2000000; i++)
    {
        for (int j = 0; j < v[i]; j++)
        {
            cout << i - 1000000 << '\n';
        }
    }

    return 0;
}