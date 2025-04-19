#include <bits/stdc++.h>
using namespace std;

long long mul(long long a, long long b, long long c)
{
    if (b == 1) return a % c;

    long long res = mul(a, b / 2, c);
    res = res * res % c;
    if (b % 2 == 0)
        return res;

    res = res * a % c;
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long a, b, c;

    cin >> a >> b >> c;

    cout << mul(a, b, c);

    return 0;
}