// https://codeforces.com/contest/1873/problem/B
// Round 898 (Div .4)

#include <bits/stdc++.h>

#define ll long long int
#define endl "\n";

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        int prod = 1, minEl = 10;
        bool flag = false;
        for (int i = 0; i < n; ++i)
        {
            int x;
            cin >> x;

            if (x == 0)
            {
                flag = 1;
                continue;
            }

            prod *= x;
            if (x <= minEl)
                minEl = x;
        }

        if (!flag)
        {
            prod = prod / minEl;
            prod = prod * (minEl + 1);
        }

        cout << prod << endl;
    }

    return 0;
}