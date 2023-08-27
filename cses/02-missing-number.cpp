/*
Time Limit : 1.00 s
Memory limit : 512 MB

You are given all numbers between
1, 2, …, n except one.

Your task is to find the missing number.

Input
The first input line contains an integer n.
The second line contains n−1 numbers.
Each number is distinct and between 1 and n(inclusive).

Output
=>Print the missing number.

Constraints
=>2≤n≤2⋅10^5

Example
Input : 5 2 3 1 5
Output : 4
*/

#include <bits/stdc++.h>

#define ll long long int
#define endl "\n";
using namespace std;

// void solve(ll n)
// {
// }

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;

    while (t--)
    {
        ll n;
        cin >> n;

        ll sum = 0;
        for (int i = 1; i <= n - 1; ++i)
        {
            ll x;
            cin >> x;
            sum += x;
        }

        ll total = n * (n + 1) / 2;
        cout << total - sum;

        // solve(n);
    }

    return 0;
}