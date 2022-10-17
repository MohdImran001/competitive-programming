#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int x, y, dist;
    Node(int i, int j, int dist)
    {
        this->x = i;
        this->y = j;
        this->dist = dist;
    }
};

class Compare
{
public:
    bool operator()(Node a, Node b)
    {
        return a.dist <= b.dist;
    }
};

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int shortest_path(vector<vector<int>> grid)
{
    int m = grid.size();
    int n = grid[0].size();
    int i = 0;
    int j = 0;

    vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
    dist[i][j] = grid[i][j];

    set<Node, Compare> s;
    s.insert(Node(i, j, dist[i][j]));

    while (!s.empty())
    {
        auto p = *s.begin();
        s.erase(p);

        int cx = p.x;
        int cy = p.y;
        int cd = p.dist;

        for (int k = 0; k < 4; ++k)
        {
            int nx = cx + dx[k];
            int ny = cy + dy[k];

            if (nx >= 0 and nx < m and ny >= 0 and ny < n and cd + grid[nx][ny] < dist[nx][ny])
            {
                Node temp(nx, ny, dist[nx][ny]);
                if (s.find(temp) != s.end())
                    s.erase(s.find(temp));

                dist[nx][ny] = cd + grid[nx][ny];
                s.insert(Node(nx, ny, dist[nx][ny]));
            }
        }
    }

    return dist[m - 1][n - 1];
}