#include <bits/stdc++.h>
using namespace std;

const long long mod = 1000000007;

long long mul(long long a, long long b)
{
    if (b == 1) return a;

    long long res = mul(a, b / 2);
    res = res * res % mod;
    if (b % 2 == 0)
        return res;

    res = res * a % mod;
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int m;

    cin >> m;

    long long res = 0;
    for (int i = 0; i < m; i++)
    {
        long long n, s;
        cin >> n >> s;
        long long x = (s * mul(n, mod - 2)) % mod;
        res += x % mod;
    }

    cout << res % mod;

    return 0;
}