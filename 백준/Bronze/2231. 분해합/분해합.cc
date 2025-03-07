#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;

    cin >> n;

    int digit = to_string(n).size();
    for (int i = n - digit * 9; i < n - digit; i++)
    {
        string s = to_string(i);
        int decomp = i;
        for (char c : s)
        {
            decomp += c - '0';
        }

        if (decomp == n)
        {
            cout << i;
            return 0;
        }
    }

    cout << "0";

    return 0;
}