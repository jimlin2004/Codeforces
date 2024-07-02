#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

/*
    還蠻好想到的dp
    定義dp[第幾瓶][喝了幾瓶] = 最大生命值
    init dp[i][0] = 0, otherwise -1
    轉移式:
    if (dp[i - 1][j - 1] != -1 && dp[i - 1][j - 1] + a[i] >= 0)
        dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] + a[i]); <- a[i]拿或不拿
    else
        dp[i][j] = dp[i - 1][j]; <- a[i]只能不拿

    最後答案選最大的j使dp[n][j] >= 0
*/

#define maxn 2005

//dp[第幾瓶][喝了幾瓶] = 最大生命值
long long dp[maxn][maxn];
long long a[maxn];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%lld", &a[i]);
    memset(dp, -1, sizeof(dp));
    dp[0][0] = 0;
    for (int i = 1; i <= n; ++i)
    {
        dp[i][0] = 0;
        for (int j = 1; j <= i; ++j)
        {
            if (dp[i - 1][j - 1] != -1 && dp[i - 1][j - 1] + a[i] >= 0)
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] + a[i]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    int res = 0;
    for (int j = n; j >= 0; --j)
    {
        if (dp[n][j] >= 0)
        {
            res = j;
            break;
        }
    }
    printf("%d\n", res);
    return 0;
}