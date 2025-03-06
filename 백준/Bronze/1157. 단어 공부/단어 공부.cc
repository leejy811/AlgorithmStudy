#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;
    vector<int> freq(26, 0);

    cin >> s;

    for (char c : s)
    {
        int idx = (c >= 'a') ? c - 'a' : c - 'A';
        freq[idx]++;
    }

    int maxIdx = max_element(freq.begin(), freq.end()) - freq.begin();
    char res = maxIdx + 'A';

    if (maxIdx != freq.size() - 1)
    {
        int max = *max_element(freq.begin(), freq.end());
        freq.erase(freq.begin(), freq.begin() + maxIdx + 1);
        if (max == *max_element(freq.begin(), freq.end()))
            res = '?';
    }

    cout << res;

    return 0;
}