// https://cses.fi/problemset/task/1618
// 10. Trailing Zeroes
#include <bits/stdc++.h>

#define ll long long int
#define endl "\n";
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;

    while (t--)
    {
        long ans = 0, curr = 5, n;
        cin >> n;

        while (curr <= n)
        {
            ans += n / curr;
            curr *= 5;
        }

        cout << ans << endl;
    }

    return 0;
}