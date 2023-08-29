/*

Time limit: 1.00 s
Memory limit: 512 MB

A permutation of integers 1,2,…,n is called beautiful
if there are no adjacent elements whose difference is 1

Given n
construct a beautiful permutation if such a permutation exists.

Input
The only input line contains an integer n.

Output
Print a beautiful permutation of integers 1,2,…,n.
If there are several solutions, you may print any of them.
If there are no solutions, print "NO SOLUTION".

Constraints
=> 1 ≤ n ≤ 10^6

Example 1
Input:
5

Output:
4 2 5 3 1

Example 2
Input:
3

Output:
NO SOLUTION

*/

#include <bits/stdc++.h>

#define ll long long int
#define endl "\n";
using namespace std;

void solve(int n)
{
    for (int i = 2; i <= n; i += 2)
        cout << i << " ";

    for (int i = 1; i <= n; i += 2)
        cout << i << " ";
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

        if (n == 1)
        {
            cout << "1";
            return 0;
        }

        if (n < 4)
        {
            cout << "NO SOLUTION";
            return 0;
        }

        solve(n);
    }

    return 0;
}