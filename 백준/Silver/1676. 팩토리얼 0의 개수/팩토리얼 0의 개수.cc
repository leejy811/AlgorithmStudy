#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;

    cin >> n;

    int cnt2 = 0;
    int cnt5 = 0;
    for (int i = 1; i <= n; i++)
    {
        int num = i;
        if (num % 2 == 0)
        {
            while (num % 2 == 0)
            {
                num /= 2;
                cnt2++;
            }
        }
        if (num % 5 == 0)
        {
            while (num % 5 == 0)
            {
                num /= 5;
                cnt5++;
            }
        }
    }

    cout << min(cnt2, cnt5);

    return 0;
}