#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int a, b, c;
    long mul;
    vector<int> res(10);

    cin >> a >> b >> c;

    mul = a * b * c;
    int mulSize = to_string(mul).size();
    for (int i = 0; i < mulSize; i++)
    {
        res[mul % 10]++;
        mul /= 10;
    }

    for (int i = 0; i < 10; i++)
    {
        cout << res[i] << "\n";
    }

    return 0;
}