/*

Time Limit: 1.00 s

Memory limit: 512 MB
You are given an array of n integers.
You want to modify the array so that it is increasing,
i.e., every element is at least as large as the previous element.

On each move, you may increase the value of any element by one.
What is the minimum number of moves required?

Input

The first input line contains an integer n : the size of the array.

Then, the second line contains n integers x1,x2,…,xn : the contents of the array.

Output
Print the minimum number of moves.

Constraints
=> 1 ≤ n ≤ 2⋅10^5
=> 1 ≤ xi ≤ 109

Example

Input:
5
3 2 5 1 7

Output:
5

*/

#include <bits/stdc++.h>

#define ll long long int
#define endl "\n";
using namespace std;

ll solve(vector<ll> arr)
{
    int n = arr.size();

    ll ans = 0;
    int i = 0, j = 1;
    while (j < n)
    {
        if (arr[j] < arr[i])
            ans += (arr[i] - arr[j]);
        else
            i = j;
        j++;
    }

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;

    while (t--)
    {
        ll n;
        cin >> n;

        vector<ll> arr(n);
        for (int i = 0; i < n; ++i)
            cin >> arr[i];

        cout << solve(arr);
    }

    return 0;
}