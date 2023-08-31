/*
Time Limit: 1.00 s
Memory limit: 512 MB

Your task is to count for k=1,2,…,n
the number of ways two knights can be placed on a k×k chessboard so that
they do not attack each other.

Input
The only input line contains an integer n.

Output
Print n integers: the results.

Constraints
1 ≤ n ≤ 10000

Example
Input:
8

Output:
0
6
28
96
252
550
1056
1848
*/

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
    // cin >> t;

    while (t--)
    {
        ll n;
        cin >> n;

        cout << 0 << endl;
        for (ll k = 2; k <= n; ++k)
            cout << ((k * k) * (k * k - 1) / 2) - 4 * (k - 1) * (k - 2) << endl;
    }

    return 0;
}