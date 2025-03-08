#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    string s;

    cin >> n >> s;

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += (s[i] - 'a' + 1) * pow(31, i);
    }

    cout << sum % 1234567891;

    return 0;
}