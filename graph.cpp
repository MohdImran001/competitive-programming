#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll MOD = 1e9 + 7;
const ll INF = 1e9;

int dfs(int node, int target, vector<vector<int>> &graph)
{
    if (node == target)
        return 1;

    int cnt = 0;
    for (int nbr : graph[node])
        cnt += dfs(nbr, target, graph) % MOD;

    return cnt % MOD;
}

int gameRoutes(int n, vector<vector<int>> edges)
{
    vector<vector<int>> graph(n + 1);
    for (auto e : edges)
        graph[e[0]].push_back(e[1]);

    return dfs(1, n, graph);
}

int main()
{
    int n = 6;
    vector<vector<int>> edges{{1, 2}, {1, 3}, {1, 4}, {2, 5}, {3, 5}, {4, 5}, {5, 6}};
    cout << gameRoutes(n, edges) << endl;
    return 0;
}
