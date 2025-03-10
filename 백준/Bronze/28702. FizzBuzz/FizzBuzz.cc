#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    vector<string> s(3);
    string res = "";

    for (int i = 0; i < 3; i++)
    {
        cin >> s[i];
    }

    for (int i = 0; i < 3; i++)
    {
        if (s[i][0] <= '9' && s[i][0] >= '0')
        {
            n = stoi(s[i]) + 3 - i;
            break;
        }
    }

    if (n % 3 == 0)
        res += "Fizz";
    if (n % 5 == 0)
        res += "Buzz";

    if (res == "")
        cout << n;
    else
        cout << res;

    return 0;
}