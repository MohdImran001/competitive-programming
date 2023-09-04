// https://cses.fi/problemset/task/1092
// 08 - Two Sets
#include <bits/stdc++.h>

#define ll long long int
#define endl "\n";

using namespace std;

void solve(int n)
{
    vector<int> a;
    vector<int> b;

    int first = 1, last = n;
    if (n & 1)
    {
        a.push_back(1);
        a.push_back(2);
        b.push_back(3);

        first = 4;
    }

    while (first < last)
    {
        if (first & 1)
        {
            a.push_back(first);
            a.push_back(last);
        }
        else
        {
            b.push_back(first);
            b.push_back(last);
        }

        first++;
        last--;
    }

    cout << "YES" << endl;
    cout << a.size() << endl;
    for (int x : a)
        cout << x << " ";
    cout << endl;

    cout << b.size() << endl;
    for (int y : b)
        cout << y << " ";
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        int sum = n * (n + 1) / 2;
        if (sum & 1)
        {
            cout << "NO";
            return 0;
        }

        solve(n);
    }

    return 0;
}