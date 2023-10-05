// https://codeforces.com/contest/1878/problem/A
// A. How Much Does Daytona Cost?
#include <bits/stdc++.h>

#define ll long long int
#define endl "\n";
using namespace std;

void solve(ll n)
{
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;

        bool flag = true;

        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            if (arr[i] == k)
                flag = true;
        }

        if (flag)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}