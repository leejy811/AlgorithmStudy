#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;

    cin >> n;

    int cnt = n;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;

        if (num == 1) cnt--;
        for (int j = 2; j <= num / 2; j++)
        {
            if (num % j == 0)
            {
                cnt--;
                break;
            }
        }
    }

    cout << cnt;

    return 0;
}