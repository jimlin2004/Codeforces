#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;

//二分圖最大匹配模板題

#define maxn 105
#define maxm 105

bool used[maxn];
vector<vector<int>> G;
int pa[maxn];
int body[maxn];
int girl[maxm];

bool match(int u)
{
    for (int v: G[u])
    {
        if (!used[v])
        {
            used[v] = true;
            if (pa[v] == 0 || match(pa[v]))
            {
                pa[v] = u;
                return true;
            }
        }
    }
    return false;
}

int main()
{
    int n, m;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &body[i]);
    }
    scanf("%d", &m);
    for (int i = 1; i <= m; ++i)
    {
        scanf("%d", &girl[i]);
    }

    G.assign(n + 5, vector<int>());

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (abs(body[i] - girl[j]) <= 1)
            {
                G[i].emplace_back(j);
            }
        }
    }

    int matchCount = 0;
    for (int i = 1; i <= n; ++i)
    {
        memset(used, 0, sizeof(used));
        if (match(i))
        {
            ++matchCount;
        }
    }
    printf("%d\n", matchCount);
    return 0;
}