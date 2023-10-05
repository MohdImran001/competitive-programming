// https://cses.fi/problemset/task/1622
// 14. Creating Strings

#include <bits/stdc++.h>

#define ll long long int
#define endl "\n";
using namespace std;

set<string> ans;
void solve(string prefix, string &suffix)
{
    if (suffix.length() == 0)
    {
        ans.insert(prefix);
        return;
    }

    for (int i = 0; i < suffix.length(); ++i)
    {
        string str = prefix + suffix[i];
        string remainingStr = suffix.substr(0, i) + suffix.substr(i + 1);
        solve(str, remainingStr);
    }
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

        solve("", str);
        cout << ans.size() << endl;

        for (auto x : ans)
            cout << x << endl;
    }

    return 0;
}