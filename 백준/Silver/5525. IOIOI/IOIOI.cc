#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    string s;

    cin >> n >> m >> s;

	int res = 0;
	for (int i = 0; i < m; i++)
	{

		int k = 0;
		if (s[i] == 'O') continue;

		while (s[i + 1] == 'O' && s[i + 2] == 'I')
		{
			k++;

			if (k == n)
			{
				res++;
				k--;
			}
			i += 2;
		}
	}

    cout << res;

    return 0;
}