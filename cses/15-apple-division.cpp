// https://cses.fi/problemset/task/1622
// 14. Apple Division

#include <bits/stdc++.h>

#define ll long long int
#define endl "\n";
using namespace std;

int total;
int solve(vector<int> &arr, int n, int sum)
{
    if (n == 0)
        return abs(sum - (total - sum));

    int x = solve(arr, n - 1, sum + arr[n]);
    int y = solve(arr, n - 1, sum);
    return min(x, y);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;

    while (t--)
    {
        int n;
        cin >> n;

        total = 0;
        vector<int> arr(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> arr[i];
            total += arr[i];
        }

        cout << solve(arr, n - 1, 0) << endl;
    }

    return 0;
}