#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

#define maxn 5005

struct Edge
{
    int u, v;
};

int gang[maxn];
int parent[maxn];
bool connected[maxn];
vector<Edge> edges;
vector<vector<int>> G; 

int rootFind(int x)
{
    if (parent[x] < 0)
        return x;
    return parent[x] = rootFind(parent[x]);
}

bool Union(int a, int b)
{
    int r1 = rootFind(a);
    int r2 = rootFind(b);
    if (r1 == r2)
        return false;
    if (parent[r1] < parent[r2])
    {
        parent[r1] += parent[r2];
        parent[r2] = r1;
    }
    else
    {
        parent[r2] += parent[r1];
        parent[r1] = r2;
    }
    return true;
}

bool kruskal(int n)
{
    int cnt = 0;
    for (const Edge& edge: edges)
    {
        if (Union(edge.u, edge.v))
        {
            ++cnt;
            G[edge.u].emplace_back(edge.v);
            G[edge.v].emplace_back(edge.u);
            connected[edge.u] = connected[edge.v] = true;
            if (cnt == n - 1)
                return true;
        }
    }
    //不能建成樹
    return false;
}

void dfs(int u, int p)
{
    for (int v: G[u])
    {
        if (v != p)
        {
            printf("%d %d\n", u, v);
            dfs(v, u);
        }
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        memset(parent, -1, sizeof(parent));
        memset(connected, 0, sizeof(connected));
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i)
            scanf("%d", &gang[i]);
        
        edges.clear();
        G.assign(n + 5, vector<int>());

        //建出所有可能的邊
        for (int i = 1; i <= n; ++i)
        {
            for (int j = i + 1; j <= n; ++j)
            {
                if (gang[i] != gang[j])
                {
                    edges.emplace_back(Edge{i, j});
                }
            }
        }

        bool allConnected = true;
        //類似kurskal
        allConnected = kruskal(n);

        int root = -1;
        if (allConnected)
        {
            for (int i = 1; i <= n; ++i)
            {
                if (!connected[i])
                {
                    allConnected = false;
                    break;
                }
                else
                {
                    if (root == -1)
                        root = i;
                }
            }
        }

        if (!allConnected)
        {
            puts("NO");
        }
        else
        {
            puts("YES");
            dfs(root, -1);
        }
    }
    return 0;
}