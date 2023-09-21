// https://codeforces.com/contest/1873/problem/A
// A. Short Sort
#include <bits/stdc++.h>

#define ll long long int
#define endl "\n";

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        string str;
        cin >> str;

        if (str[0] == 'a' or str[1] == 'b' or str[2] == 'c')
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}