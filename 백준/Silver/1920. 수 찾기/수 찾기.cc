#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int m, n;

    cin >> n;

    map<int, int> map;

    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        map[num] = 1;
    }

    cin >> m;

    for (int i = 0; i < m; i++)
    {
        int target;
        cin >> target;

        if(map.find(target) != map.end())
            cout << 1 << "\n";
        else
            cout << 0 << "\n";
    }

    return 0;
}