#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int m, n;
    map<int, int> card;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        card[num]++;
    }

    cin >> m;

    for (int i = 0; i < m; i++)
    {
        int num;
        cin >> num;
        cout << card[num] << " ";
    }

    return 0;
}