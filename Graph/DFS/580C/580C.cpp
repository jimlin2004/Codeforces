#include <cstdio>
#include <vector>
using namespace std;

#define maxn 100005

int n, m;
int hasCat[maxn];
vector<vector<int>> G;
int res = 0;

void dfs(int u, int p, int catCnt)
{
    if (catCnt > m)
        return;
    int ok = 1;
    for (int v: G[u])
    {
        if (v != p)
        {
            ok = 0;
            dfs(v, u, catCnt * hasCat[u] + hasCat[v]);
        }
    }
    res += ok;
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &hasCat[i]);
    G.assign(n + 5, vector<int>());
    int u, v;
    for (int i = 1; i < n; ++i)
    {
        scanf("%d %d", &u, &v);
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }

    //root 1上在多一個0
    hasCat[0] = 1;

    dfs(1, 0, hasCat[1]);
    printf("%d\n", res);

    return 0;
}