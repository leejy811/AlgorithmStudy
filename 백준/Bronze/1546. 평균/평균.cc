#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, max, sum;
    vector<int> score;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int s;
        cin >> s;
        score.push_back(s);
    }

    max = *max_element(score.begin(), score.end());
    sum = accumulate(score.begin(), score.end(), 0);

    float average = sum * 100.0f / max / n;

    cout << average;

    return 0;
}