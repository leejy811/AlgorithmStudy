#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int total, pNum;

    cin >> total >> pNum;

    int sum = 0;
    for (int i = 0; i < pNum; i++)
    {
        int price, num;
        cin >> price >> num;
        sum += price * num;
    }

    string res = (sum == total) ? "Yes" : "No";

    cout << res;

    return 0;
}