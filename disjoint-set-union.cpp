#include <bits/stdc++.h>

using namespace std;

vector<int> parent(100005, -1);
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

vector<bool> DSU(vector<vector<int>> query)
{
    vector<bool> res;

    for (auto q : query)
    {
        int x = q[0];
        int u = q[1];
        int v = q[2];

        if (x == 1)
            union_set(u, v, parent);
        else if (x == 2)
            res.push_back(find(u, parent) == find(v, parent));
    }

    return res;
}

int main()
{
    int n = 6;
    vector<vector<int>> query{{1, 1, 2}, {1, 1, 3}, {2, 1, 3}, {2, 2, 1}};

    auto v = DSU(query);
    for (auto b : v)
        cout << b << endl;

    return 0;
}