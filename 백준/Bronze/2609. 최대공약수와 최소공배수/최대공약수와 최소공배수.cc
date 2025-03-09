#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b)
{
    int r;

    while (b != 0)
    {
        r = a % b;
        a = b;
        b = r;
    }

    return a;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int a, b;

    cin >> a >> b;

    int gcdN = gcd(a, b);
    int lcmN = (a * b) / gcd(a, b);

    cout << gcdN << "\n" << lcmN;

    return 0;
}