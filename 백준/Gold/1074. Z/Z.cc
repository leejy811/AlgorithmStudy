#include <bits/stdc++.h>
using namespace std;

int func(int n, int r, int c)
{
    if (n == 1)
        return r * 2 + c;

    int pow2 = (int)pow(2, n - 1);
    int pow4 = (int)pow(4, n - 1);
    return pow4 * (r / pow2 * 2 + c / pow2) + func(n - 1, r % pow2, c % pow2);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, r, c;

    cin >> n >> r >> c;

    cout << func(n, r, c);

    return 0;
}