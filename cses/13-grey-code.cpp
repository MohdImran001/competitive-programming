// https://cses.fi/problemset/task/2205
// 13. Grey Code

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
        int n;
        cin >> n;

        vector<string> grey_code;
        grey_code.push_back("");

        for (int i = 0; i < n; ++i)
        {
            // double the size
            int size = grey_code.size();
            for (int j = size - 1; j >= 0; --j)
            {
                grey_code.push_back(grey_code[j]);
            }

            // append 0s and 1s
            size *= 2;
            for (int j = 0; j < size; ++j)
            {
                if (j < grey_code.size() / 2)
                    grey_code[j] += "0";
                else
                    grey_code[j] += "1";
            }
        }

        for (auto str : grey_code)
            cout << str << endl;
    }

    return 0;
}