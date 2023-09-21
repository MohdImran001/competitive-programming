// https://codeforces.com/contest/1873/problem/C
// C. Target Practice
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
        char grid[11][11];

        for (int i = 1; i <= 10; ++i)
            for (int j = 1; j <= 10; ++j)
                cin >> grid[i][j];

        int k = 1, r, c, total = 0;
        while (k <= 5)
        {

            r = k;
            for (int c = k; c <= 10 - k + 1; c++)
                total += grid[r][c] == 'X' ? k : 0;

            r = 10 - k + 1;
            for (int c = k; c <= 10 - k + 1; c++)
                total += grid[r][c] == 'X' ? k : 0;

            c = k;
            for (int r = k + 1; r < 10 - k + 1; r++)
                total += grid[r][c] == 'X' ? k : 0;

            c = 10 - k + 1;
            for (int r = k + 1; r < 10 - k + 1; r++)
                total += grid[r][c] == 'X' ? k : 0;

            k++;
        }

        cout << total << endl;
    }

    return 0;
}