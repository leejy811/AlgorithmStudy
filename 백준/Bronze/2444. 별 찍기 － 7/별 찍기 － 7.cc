#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n + i; j++)
        {
            if (j >= n - i - 1)
                cout << "*";
            else
                cout << " ";
        }
        cout << "\n";
    }

    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = 0; j < n + i; j++)
        {
            if (j >= n - i - 1)
                cout << "*";
            else
                cout << " ";
        }
        cout << "\n";
    }

    return 0;
}