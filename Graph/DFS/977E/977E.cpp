#include <cstdio>
#include <vector>
using namespace std;

/*
從無向圖中找環，直接dfs在看每個node的degree是不是2即可
(底下用degree 4是因為無向圖當雙向圖用)
*/

#define maxn 200005

int deg[maxn];
bool visited[maxn];
vector<vector<int>> G;
vector<int> component;

void dfs(int u)
{
    visited[u] = true;
    component.emplace_back(u);
    for (int v: G[u])
    {
        if (!visited[v])
        {
            dfs(v);
        }
    }
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
        deg[u] += 2;
        deg[v] += 2;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }

    int res = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (!visited[i])
        {
            component.clear();
            dfs(i);

            bool isCyclic = true;
            for (int v: component)
            {
                isCyclic &= (deg[v] == 4);
            }
            
            res += isCyclic;
        }
    }
    printf("%d\n", res);
    return 0;
}