#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<bool> num(30, false);

    for (int i = 0; i < 28; i++)
    {
        int idx;
        cin >> idx;
        num[idx - 1] = true;
    }

    vector<bool>::iterator iter = find(num.begin(), num.end(), false);
    cout << iter - num.begin() + 1 << "\n";
    cout << find(iter + 1, num.end(), false) - num.begin() + 1 << "\n";

    return 0;
}