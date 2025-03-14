#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int num;

    cin >> num;

    vector<int> v(num);
    vector<int> cnt(8001);
    for (int i = 0; i < num; i++)
    {
        cin >> v[i];
        cnt[v[i] + 4000]++;
    }

    sort(v.begin(), v.end());

    //산술평균
    float sum = accumulate(v.begin(), v.end(), 0);
    cout << floor(sum / num + 0.5) << "\n";

    //중앙값
    cout << v[v.size() / 2] << "\n";

    //최빈값
    int idx0 = max_element(cnt.begin(), cnt.end()) - cnt.begin();
    int idx1 = (idx0 != 8000) ? max_element(cnt.begin() + idx0 + 1, cnt.end()) - cnt.begin() : 0;
    if (cnt[idx0] == cnt[idx1])
        cout << idx1 - 4000 << "\n";
    else
        cout << idx0 - 4000 << "\n";

    //범위
    cout << v.back() - v.front() << "\n";

    return 0;
}