#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int num;
    vector<int> res;

    cin >> num;

    for (int i = 0; i < num; i++)
    {
        int a, b;
        cin >> a >> b;
        res.push_back(a + b);
    }

    for (int i = 0; i < num; i++)
    {
        cout << "Case #" << i + 1 << ": " << res[i] << "\n";
    }

    return 0;
}