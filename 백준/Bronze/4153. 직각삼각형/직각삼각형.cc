#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while (1)
    {
        vector<int> length(3);
        cin >> length[0] >> length[1] >> length[2];

        if (length[0] == 0 && length[1] == 0 && length[2] == 0) break;

        sort(length.begin(), length.end());
        if (pow(length[0], 2) + pow(length[1], 2) == pow(length[2], 2))
            cout << "right\n";
        else
            cout << "wrong\n";
    }

    return 0;
}