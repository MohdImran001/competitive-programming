// https://cses.fi/problemset/task/1617
// 09. Bit Strings
#include <bits/stdc++.h>

#define ll long long int
#define endl "\n";
#define mod 1000000007

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;

    while (t--)
    {
        int n;
        cin >> n;

        int ans = 1;
        for (int i = 0; i < n; ++i)
        {
            ans *= 2;
            ans %= mod;
        }

        cout << ans << endl;
    }

    return 0;
}