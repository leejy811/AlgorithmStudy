#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b)
{
    long long r;
    while (b != 0)
    {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

long long lcm(long long a, long long b)
{
    return (a * b) / gcd(a, b);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	int t;

    cin >> t;

	for (int i = 0; i < t; i++)
	{
        long long m, n, x, y;

        cin >> m >> n >> x >> y;

        long long a = x, b = (x % n == 0) ? n : x % n, cnt = x;
        long long limit = lcm(m, n);
        while (1)
        {
            if (a == x && b == y)
            {
                cout << cnt << "\n";
                break;
            }
            else if (limit < cnt)
            {
                cout << -1 << "\n";
                break;
            }

            if ((b + m) % n == 0)
                b = n;
            else
                b = (b + m) % n;

            cnt += m;
        }
	}

    return 0;
}