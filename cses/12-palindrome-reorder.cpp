// https://cses.fi/problemset/task/1755
// Palindrome Reorder

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
        string str, f = "", s = "";
        cin >> str;

        map<char, int> mp;
        for (auto ch : str)
            mp[ch]++;

        int odd = 0;
        char oddChar;
        for (auto p : mp)
        {
            if (p.second & 1)
            {
                odd++;
                oddChar = p.first;
            }
        }

        if (odd > 1 or (odd == 1 and str.length() % 2 == 0))
        {
            cout << "NO SOLUTION\n";
            return 0;
        }

        for (auto p : mp)
        {
            char ch = p.first;
            int cnt = p.second;

            string x = string(cnt / 2, ch);
            f = f + x;
            s = x + s;
        }

        string ans = (odd == 0) ? f + s : f + string(1, oddChar) + s;
        cout << ans << endl;
    }

    return 0;
}