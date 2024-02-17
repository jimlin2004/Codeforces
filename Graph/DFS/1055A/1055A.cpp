#include <cstdio>
#include <vector>
using namespace std;

vector<vector<int>> G;
int isOpened[1005];
bool visited[1005];

bool dfs(int u, int target)
{
    visited[u] = true;
    bool res = false;
    for (int v: G[u])
    {
        if (!visited[v])
        {
            if (v == target)
                return true;
            res = res || dfs(v, target);
            if (res)
                return res;
        }
    }
    return res;
}

int main()
{
    int n, s;
    scanf("%d %d", &n, &s);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &isOpened[i]);
    G.assign(1005, vector<int>());
    for (int i = 1; i <= n; ++i)
    {
        if (isOpened[i])
        {
            for (int j = i + 1; j <= n; ++j)
            {
                if (isOpened[j])
                {
                    G[i].emplace_back(j);
                }
            }
        }
    }
    for (int i = 1; i <= n; ++i)
        scanf("%d", &isOpened[i]);
    for (int i = n; i >= 1; --i)
    {
        if (isOpened[i])
        {
            for (int j = i - 1; j >= 1; --j)
            {
                if (isOpened[j])
                {
                    G[i].emplace_back(j);
                }
            }
        }
    }
    printf("%s\n", (dfs(1, s)) ? "YES" : "NO");
    return 0;
}