#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

#define maxn 100005

vector<vector<int>> G;
bool vis[maxn];

//類似Dijkstar或換成priority queue的BFS
void solve()
{
    bool first = true;
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(1);
    while (!pq.empty())
    {
        int curr = pq.top();
        pq.pop();
        if (vis[curr])
            continue;
        vis[curr] = true;

        if (first)
        {
            printf("%d", curr);
            first = false;
        }
        else
            printf(" %d", curr);

        for (int v: G[curr])
        {
            if (!vis[v])
                pq.push(v);
        }
    }
    puts("");
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    G.assign(n + 5, vector<int>());
    int u, v;
    for (int i = 0; i < m; ++i)
    {
        scanf("%d %d", &u, &v);
        if (u != v)
        {
            G[u].emplace_back(v);
            G[v].emplace_back(u);
        }
    }
    solve();
    return 0;
}