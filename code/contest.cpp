#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define mp make_pair
#define endl "\n";
#define vc vector<char>
#define vi vector<int>
#define vii vector<vector<int>>
#define vcc vector<vector<char>>
#define all(x) x.begin(), x.end()
#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define _forn(i, n) for (int i = int(n); i >= 0; --i)

const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const int MAXN = 1e5 + 1;
const int M = 20;
const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};

int n;
int a[200001];
vi adj[200001];
int dp1[200001];
int dp2[200001];

void dfs1(int node = 1, int parent = 0)
{
    dp1[node] = a[node] == 1 ? 1 : -1;
    for (auto child : adj[node])
    {
        if (child != parent)
        {
            dfs1(child, node);
            dp1[node] += max(0, dp1[child]);
        }
    }
}

void dfs2(int node = 1, int parent = 0)
{
    dp2[node] = dp1[node];
    if (parent)
    {
        int val = dp2[parent] - max(0, dp1[node]);
        dp2[node] += max(0, val);
    }

    for (auto child : adj[node])
    {
        if (child != parent)
        {
            dfs2(child, node);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    for (int i = 0; i < n - 1; ++i)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs1();
    dfs2();

    for (int i = 1; i <= n; ++i)
        cout << dp1[i] << " ";

    return 0;
}