#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<int> dice;
    int res;

    for (int i = 0; i < 3; i++)
    {
        int tmp;
        cin >> tmp;
        dice.push_back(tmp);
    }

    sort(dice.begin(), dice.end());

    int count = 1;
    int dupliNum = *max_element(dice.begin(), dice.end());
    for (int i = 1; i < 3; i++)
    {
        if (dice[i] == dice[i - 1])
        {
            dupliNum = dice[i];
            count++;
        }
    }

    if (count == 3)
        res = 10000 + dupliNum * 1000;
    else if (count == 2)
        res = 1000 + dupliNum * 100;
    else if (count == 1)
        res = dupliNum * 100;
    
    cout << res;

    return 0;
}