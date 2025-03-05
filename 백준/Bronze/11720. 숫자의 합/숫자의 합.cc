#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, sum;
    string numStr;

    cin >> n >> numStr;

    sum = accumulate(numStr.begin(), numStr.end(), 0) - '0' * n;

    cout << sum;

    return 0;
}