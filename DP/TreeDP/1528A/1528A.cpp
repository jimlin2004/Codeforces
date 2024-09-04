#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

/*
    Greedy + tree dp

    題意要最大化abs的和
    利用greedy思維可知每個node
    只需要設定為最極端的l or r
    最後可找到最大化的值
    接下來就剩樹DP
    定義: dp[u][選l還是r]
    轉移式:
        dp[u][0] += max(dp[v][0] + abs(l[u] - l[v]), dp[v][1] + abs(l[u] - r[v]));
        dp[u][1] += max(dp[v][0] + abs(r[u] - l[v]), dp[v][1] + abs(r[u] - r[v]));
    就是把所有可能取最大的即可
*/

#define maxn 100005

long long l[maxn];
long long r[maxn];
//tree
vector<vector<int>> G;
//dp[u][選l還是r]
long long dp[maxn][2];

void dfs(int u, int p)
{
    for (int v: G[u])
    {
        if (v != p)
        {
            dfs(v, u);
            dp[u][0] += max(dp[v][0] + abs(l[u] - l[v]), dp[v][1] + abs(l[u] - r[v]));
            dp[u][1] += max(dp[v][0] + abs(r[u] - l[v]), dp[v][1] + abs(r[u] - r[v]));
        }
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        G.assign(n + 5, vector<int>());
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= n; ++i)
            scanf("%lld %lld", &l[i], &r[i]);
        int u, v;
        for (int i = 1; i < n; ++i)
        {
            scanf("%d %d", &u, &v);
            G[u].emplace_back(v);
            G[v].emplace_back(u);
        }

        dfs(1, -1);
        printf("%lld\n", max(dp[1][0], dp[1][1]));
    }
    return 0;
}