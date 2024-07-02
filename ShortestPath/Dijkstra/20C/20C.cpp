#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

//無聊的dijkstra水題

#define maxn 100005

struct Edge
{
    int u, v;
    long long w;
};

struct Item
{
    int u;
    long long w;
    bool operator < (const Item& other) const
    {
        return this->w > other.w;
    }
};

vector<vector<Edge>> G;
long long dis[maxn];
int p[maxn];
bool vis[maxn];

void dijkstra(int s, int t)
{
    memset(dis, 0x3f, sizeof(dis));
    priority_queue<Item> pq;
    p[s] = -1;
    dis[s] = 0;
    pq.push({s, 0});
    while (!pq.empty())
    {
        Item item = pq.top();
        pq.pop();

        vis[item.u] = true;

        if (item.u == t)
            return;

        for (const Edge& edge: G[item.u])
        {
            if (!vis[edge.v])
            {
                if (dis[edge.v] > dis[edge.u] + edge.w)
                {
                    dis[edge.v] = dis[edge.u] + edge.w;
                    p[edge.v] = edge.u;
                    pq.push({edge.v, dis[edge.v]});
                }
            }
        }
    }
}

void printPath(int u)
{
    if (p[u] == -1)
    {
        printf("%d ", u);
        return;
    }
    printPath(p[u]);
    printf("%d ", u);
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    G.assign(n + 5, vector<Edge>());
    int u, v, w;
    for (int i = 0; i < m; ++i)
    {
        scanf("%d %d %d", &u, &v, &w);
        G[u].push_back({u, v, w});
        G[v].push_back({v, u, w});
    }

    dijkstra(1, n);
    if (dis[n] == 0x3f3f3f3f3f3f3f3f)
        puts("-1");
    else
    {
        printPath(n);
        puts("");
    }
    return 0;
}