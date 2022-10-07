#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()

using namespace std;

class DSU
{
    vector<int> parent;
    vector<int> size;

public:
    DSU(int n)
    {
        parent.resize(n, -1);
        size.resize(n, 1);
    }

    int find(int i)
    {
        if (parent[i] == -1)
            return i;

        return parent[i] = find(parent[i]);
    }

    void unite(int x, int y)
    {
        int s1 = find(x);
        int s2 = find(y);

        if (s1 != s2)
        {
            if (size[s2] > size[s1])
                parent[s1] = s2, size[s2] += size[s1];
            else
                parent[s2] = s1, size[s1] += size[s2];
        }
    }
};

class Graph
{
    vector<vector<int>> edgeList;
    int n;

public:
    Graph(int n)
    {
        this->n = n;
    }

    void addEdge(int x, int y, int w)
    {
        edgeList.push_back({w, x, y});
    }

    int kruskal_mst()
    {
        DSU s(n);

        sort(all(edgeList));

        int ans = 0;
        for (auto e : edgeList)
        {
            int w = e[0];
            int x = e[1];
            int y = e[2];

            if (s.find(x) != s.find(y))
            {
                s.unite(x, y);
                ans += w;
            }
        }

        return ans;
    }
};

int MST(int n, vector<vector<int>> edges)
{
    Graph g(n + 1);
    for (auto e : edges)
        g.addEdge(e[0], e[1], e[2]);

    return g.kruskal_mst();
}