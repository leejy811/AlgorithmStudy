#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
	vector<int> card;
    vector<int> res;

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        int c;
        cin >> c;
        card.push_back(c);
    }

    vector<bool> temp(n, false);
    fill(temp.end() - 3, temp.end(), true);

    do
    {
        int sum = 0;
        for (int i = 0; i < temp.size(); i++)
        {
            if (temp[i]) sum += card[i];
        }
        if (sum <= m) res.push_back(sum);
    } while (next_permutation(temp.begin(), temp.end()));
    
    cout << *max_element(res.begin(), res.end());

    return 0;
}