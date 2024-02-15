#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

/*
核心觀念:
    要找出最小的組數，使沒有兩個有父子關係的節點在同一組
    此題中是tree，答案其實就是tree的最大深度，因為同一條路徑上的節點都有父子關係，
    要被分在不同組，由於tree沒有環，所以最大深度即為答案的限制來源。
    <注>: 題目沒說只有一個tree
*/

vector<vector<int>> G;
vector<int> roots;
bool visited[2005];

int bfs(int root)
{
    queue<int> q;
    q.push(root);
    int maxDepth = 0;
    int u;
    while (!q.empty())
    {
        ++maxDepth;
        int size = q.size();
        for (int i = 0; i < size; ++i)
        {
            u = q.front();
            q.pop();
            visited[u] = true;
            for (int v: G[u])
            {
                if (!visited[v])
                    q.push(v);
            }
        }
    }
    return maxDepth;
}

int main()
{
    int root;
    int n;
    scanf("%d", &n);
    int parent;

    G.assign(n + 5, vector<int>());

    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &parent);
        if (parent == -1)
            roots.emplace_back(i);
        else
        {
            G[i].emplace_back(parent);
            G[parent].emplace_back(i);
        }
    }

    int res = -1;
    for (int root: roots)
    {
        res = max(res, bfs(root));
    }
    printf("%d\n", res);
    return 0;
}