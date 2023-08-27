/*

Time Limit: 1.00 s
Memory limit: 512 MB
You are given a DNA sequence : a string consisting of characters A, C, G, and T.
Your task is to find the longest repetition in the sequence.

This is a maximum - length substring containing only one type of character.


Input
=>The only input line contains a string of n characters.

Output
=>Print one integer: the length of the longest repetition.


Constraints
=>1≤n≤10^6

Example
Input:
=>ATTCGGGA
Output:
=>3


*/

#include <bits/stdc++.h>

#define ll long long int
#define endl "\n";
using namespace std;

int solve(string str)
{
    int n = str.size();

    int i = 0, j = 0, ans = 1;
    while (j < n)
    {
        if (str[j] != str[i])
            i = j;

        ans = max(ans, j - i + 1);
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
        string str;
        cin >> str;

        cout << solve(str);
    }

    return 0;
}