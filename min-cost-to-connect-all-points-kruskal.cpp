#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()

using namespace std;

int find(int i, vector<int> &p)
{
    return p[i] < 0 ? i : p[i] = find(p[i], p);
}

void unite(int x, int y, vector<int> &p, vector<int> &size)
{
    int s1 = find(x, p);
    int s2 = find(y, p);

    if (s1 != s2)
    {
        if (size[s2] > size[s1])
            p[s1] = s2, size[s2] += size[s1];
        else
            p[s2] = s1, size[s1] += size[s2];
    }
}

int minCostConnectPoints(vector<vector<int>> &points)
{
    int n = points.size();
    vector<int> p(n, -1), sz(n, 1); // DSU
    priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> pq;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int x1 = points[i][0], y1 = points[i][1];
            int x2 = points[j][0], y2 = points[j][1];
            int weight = abs(x1 - x2) + abs(y1 - y2);

            pq.push({weight, i, j});
        }
    }

    int ans = 0;
    while (!pq.empty())
    {
        auto [dist, i, j] = pq.top();
        pq.pop();

        i = find(i, p), j = find(j, p);
        if (i != j)
        {
            unite(i, j, p, sz);
            ans += dist;
            if (sz[i] == n or sz[j] == n)
                break;
        }
    }

    return ans;
}

int main()
{
    return 0;
}