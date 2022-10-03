/*
- Disjoint Set Union

Q. Useless Connection
Return an edge that can be removed so that the resulting graph is a tree of n nodes.
If there are multiple answers, return the answer that occurs last in the input.
*/

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

vector<int> findUselessConnection(vector<vector<int>> edges)
{
    int n = edges.size();
    vector<int> parent(n + 1, -1);

    for (auto e : edges)
    {
        if (find(e[0], parent) == find(e[1], parent))
            return {e[0], e[1]};

        union_set(e[0], e[1], parent);
    }

    return {};
}

int main()
{
    int n = 6;
    vector<vector<int>> query{{1, 1, 2}, {1, 1, 3}, {2, 1, 3}, {2, 2, 1}};

    // auto v = DSU(query);
    // for (auto b : v)
    //     cout << b << endl;

    return 0;
}