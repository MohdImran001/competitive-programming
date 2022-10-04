/*
- Disjoint Set Union

LeetCode 1319. Number of Operations to Make Network Connected
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define vi vector<int>
#define vc vector<char>
#define vii vector<vector<int>>
#define vcc vector<vector<char>>
#define forn(i, n) for (int i = 0; i < int(n); ++i)

const ll MOD = 1e9 + 7;
const ll INF = 1e9;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int find(int i, vector<int> &parent)
{
    if (parent[i] == -1)
        return i;

    return parent[i] = find(parent[i], parent);
}

void union_set(int x, int y, vector<int> &parent, vector<int> &size)
{
    int s1 = find(x, parent);
    int s2 = find(y, parent);

    if (s1 != s2)
    {
        if (size[s2] > size[s1])
            parent[s1] = s2, size[s2] += size[s1];
        else
            parent[s2] = s1, size[s1] += size[s2];
    }
}

int makeConnected(int n, vector<vector<int>> connections)
{
    if (connections.size() < n - 1)
        return -1;

    vector<int> parent(n, -1), size(n, 1);
    for (auto e : connections)
    {
        int s1 = find(e[0], parent);
        int s2 = find(e[1], parent);
        union_set(s1, s2, parent, size);
    }

    int ans = 0;
    for (auto i : parent)
        if (i == -1)
            ans++;

    return ans;
}

int main()
{
    int n = 6;
    vector<vector<int>> connections{{0, 1}, {0, 2}, {0, 3}, {1, 2}, {1, 3}};
    cout << makeConnected(n, connections) << endl;
}