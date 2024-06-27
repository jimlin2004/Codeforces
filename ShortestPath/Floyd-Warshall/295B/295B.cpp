#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define maxn 505

/*
    關鍵: 把題目逆過來想
    變成每次加一個點
    這樣Floyd-Warshall的最外層for loop可以拿來裡用
    否則正著作要n ^ 4(試過了，超時)
*/

long long dp[maxn][maxn];
int removeNodes[maxn];
long long ans[maxn];
//點出現了沒
bool exists[maxn];

int main()
{
    int n;
    scanf("%d", &n);
    
    memset(dp, 0x3f, sizeof(dp));
    
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            scanf("%lld", &dp[i][j]);
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &removeNodes[i]);
    }
    
    for (int i = n; i >= 1; --i)
    {
        //把題目變成加一個點
        int k = removeNodes[i];
        exists[k] = true;

        //新的點當成中繼點，跑Floyd-Warshall
        for (int x = 1; x <= n; ++x)
        {
            //不能這樣判斷exists，因為就算還沒出現，還是要先鬆弛過，否則後面計算會錯
            // if (!exists[x])
            //     continue;
            for (int y = 1; y <= n; ++y)
            {
                // if (!exists[y])
                    // continue;
                dp[x][y] = min(dp[x][y], dp[x][k] + dp[k][y]);
            }
        }

        for (int x = 1; x <= n; ++x)
        {
            for (int y = 1; y <= n; ++y)
            {
                if (exists[x] && exists[y])
                    ans[i] += dp[x][y];
            }
        }
    }

    printf("%lld", ans[1]);
    for (int i = 2; i <= n; ++i)
        printf(" %lld", ans[i]);
    puts("");
    return 0;
}