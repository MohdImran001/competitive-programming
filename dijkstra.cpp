#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(vector<vector<pair<int, int>>> graph, int source, int n)
{
    vector<int> dist(n + 1, INT_MAX), parent(n + 1, -1);
    set<pair<int, int>> s;

    dist[source] = 0;
    s.insert({0, source});

    while (!s.empty())
    {
        auto p = *s.begin();
        s.erase(p);

        int distOfParent = p.first;
        int node = p.second;

        for (auto temp : graph[node])
        {
            int distOfNbr = temp.first;
            int nbr = temp.second;

            if (distOfParent + distOfNbr < dist[nbr])
            {
                s.erase({dist[nbr], nbr});
                dist[nbr] = distOfParent + distOfNbr;
                s.insert({dist[nbr], nbr});
                parent[nbr] = node;
            }
        }
    }

    vector<int> path;
    int temp = n;
    while (temp != -1)
    {
        path.push_back(temp);
        temp = parent[temp];
    }

    reverse(path.begin(), path.end());
    return path;
}

vector<int> shortestPath(vector<vector<int>> roads, int n)
{
    vector<vector<pair<int, int>>> graph(n + 1);
    for (auto road : roads)
    {
        graph[road[0]].push_back({road[2], road[1]});
        graph[road[1]].push_back({road[2], road[0]});
    }

    int source = 1;
    return dijkstra(graph, source, n);
}

int main()
{
    int n = 5;
    vector<vector<int>> roads{{1, 2, 2}, {2, 5, 5}, {2, 3, 4}, {1, 4, 1}, {4, 3, 3}, {3, 5, 1}};
    auto v = shortestPath(roads, n);
    for (auto i : v)
        cout << i << "\t";

    cout << endl;
}