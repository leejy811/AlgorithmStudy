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

int lcm(int a, int b)
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
        int m, n, x, y;

        cin >> m >> n >> x >> y;

        int a = x, b = (x % n == 0) ? n : x % n, cnt = x;
        int limit = lcm(m, n);
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