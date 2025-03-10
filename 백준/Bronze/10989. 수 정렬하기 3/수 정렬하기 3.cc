#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;

    cin >> n;

    vector<int> v(10001);
    for (int i = 0; i < n; i++)
    {
        int idx;
        cin >> idx;
        v[idx]++;
    }

    for (int i = 0;i < v.size();i++)
    {
        for (int j = 0; j < v[i]; j++)
        {
            cout << i << "\n";
        }
    }

    return 0;
}