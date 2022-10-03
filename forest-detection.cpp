// Disjoint Set Union
// Return whether the graph is a collection of trees.

#include <bits/stdc++.h>

using namespace std;

int find(int i, vector<int> &parent)
{
    if (parent[i] == -1)
        return i;

    return find(parent[i], parent);
}

void union_set(int x, int y, vector<int> &parent)
{
    int s1 = find(x, parent);
    int s2 = find(y, parent);

    if (s1 != s2)
        parent[s1] = s2;
}

bool solve(vector<vector<int>> edges)
{
    vector<int> parent(100005, -1);

    for (auto e : edges)
    {
        int x = e[0], y = e[1];
        if (find(x, parent) == find(y, parent))
            return false;

        union_set(x, y, parent);
    }

    return true;
}

int main()
{
    int n = 6;
    vector<vector<int>> query{{1, 1, 2}, {1, 1, 3}, {2, 1, 3}, {2, 2, 1}};

    return 0;
}