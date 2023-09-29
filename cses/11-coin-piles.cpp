// https://cses.fi/problemset/task/1754
// 11. Coin Piles
#include <bits/stdc++.h>

#define ll long long int
#define endl "\n";
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;

    while (t--)
    {
        long a, b;
        cin >> a >> b;

        if (a < b)
            swap(a, b);
        if (a > 2 * b)
        {
            cout << "NO\n";
            continue;
        }

        if ((a + b) % 3 == 0)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}