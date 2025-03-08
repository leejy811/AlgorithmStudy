#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    string s;

    cin >> n >> s;

    long long sum = 0;
    long long r = 1;
    long long m = 1234567891;
    for (int i = 0; i < n; i++)
    {
        sum += ((s[i] - 'a' + 1) * r) % m;
        r = (r * 31) % m;
    }

    cout << sum % m;

    return 0;
}