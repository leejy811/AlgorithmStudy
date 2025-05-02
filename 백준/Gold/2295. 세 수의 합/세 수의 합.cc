#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;

    cin >> n;

    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    vector<int> two;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            two.push_back(v[i] + v[j]);

    sort(two.begin(), two.end());

    int max = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (binary_search(two.begin(), two.end(), v[i] - v[j]) && max < v[i])
                max = v[i];

    cout << max;

    return 0;
}