#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

#define maxn 200005

/*
    將圖用dfs著色，看是color 0還是color 1的數量符合題目要求即可
*/

// vector<int> G[maxn];
vector<vector<int>> G;
int color[maxn];

//color 0
vector<int> A;
//color 1
vector<int> B;

void dfs(int u, int c)
{
    color[u] = c;
    for (int v: G[u])
    {
        if (color[v] == -1)
            dfs(v, 1 - c);
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, m;
        scanf("%d %d", &n, &m);
        //以下會超時QQ(memset)
        G.assign(n + 5, vector<int>());
        // memset(color, -1, sizeof(color));
        for (int i = 1; i <= n; ++i)
        {
            // G[i].clear();
            color[i] = -1;
        }
        A.clear();
        B.clear();

        int u, v;
        for (int i = 0; i < m; ++i)
        {
            scanf("%d %d", &u, &v);
            G[u].emplace_back(v);
            G[v].emplace_back(u);
        }

        dfs(1, 0);

        for (int i = 1; i <= n; ++i)
        {
            if (color[i] == 0)
                A.emplace_back(i);
            else
                B.emplace_back(i);
        }

        if (A.size() <= (n / 2))
        {
            printf("%d\n", A.size());
            for (int u: A)
            {
                printf("%d ", u);
            }
        }
        else
        {
            printf("%d\n", B.size());
            for (int u: B)
            {
                printf("%d ", u);
            }
        }
        puts("");
    }
    return 0;
}