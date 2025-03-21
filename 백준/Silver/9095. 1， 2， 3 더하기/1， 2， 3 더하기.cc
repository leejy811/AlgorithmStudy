#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;

    cin >> n;

    vector<int> v(12);
    v[1] = 1;
    v[2] = 2;
    v[3] = 4;

    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;

        for (int j = 4; j <= num; j++)
        {
            v[j] = v[j - 1] + v[j - 2] + v[j - 3];
        }

        cout << v[num] << "\n";
    }

    return 0;
}