#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    vector<int> size(6);
    int t, p;

    cin >> n;
    cin >> size[0] >> size[1] >> size[2] >> size[3] >> size[4] >> size[5];
    cin >> t >> p;

    int shirt = 0, pen;
    for (int i : size)
    {
        int add = (i % t) == 0 ? 0 : 1;
        shirt += (i / t) + add;
    }

    cout << shirt << "\n";
    cout << n / p << " " << n % p;

    return 0;
}