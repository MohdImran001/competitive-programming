#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define mp make_pair
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
const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};

vector<vector<int>> G;
vector<int> dp;

int dfs(int v, int par = -1)
{
    if (G[v].size() == 0)
        return dp[v] = 1;

    int count = 0;
    for (int nv : G[v])
        if (nv != par)
            count += dfs(nv, v);

    return dp[v] = count + 1; // add 1 for current node
}

vector<int> subtreeProblem(int n, vector<vector<int>> edges, vector<int> queries)
{
    G.resize(MAXN);
    dp.resize(MAXN, 0);
    for (auto e : edges)
        G[e[0]].push_back(e[1]), G[e[1]].push_back(e[0]);

    dfs(1);
    vector<int> ans;
    for (int u : queries)
        ans.push_back(dp[u]);

    return ans;
}