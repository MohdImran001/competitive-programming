#include <bits/stdc++.h>

using namespace std;

int prims_mst(vector<vector<pair<int, int>>> &graph)
{
    int ans = 0;
    vector<int> visited(graph.size());
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

    q.push({0, 0}); // weight, pair

    while (q.size())
    {
        auto best = q.top();
        q.pop();

        int weight = best.first;
        int node = best.second;

        if (visited[node])
            continue;

        ans += weight;
        visited[node] = 1;

        for (auto temp : graph[node])
        {
            int weight = temp.first;
            int node = temp.second;

            if (!visited[node])
                q.push({weight, node});
        }
    }

    return ans;
}
