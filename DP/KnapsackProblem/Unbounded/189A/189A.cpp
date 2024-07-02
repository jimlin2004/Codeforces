#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

/*
    當作無限背包問題即可
    但要先將dp[] init為-INF
    因為要求要完整的用coins湊出n
    所以dp[0] = 0, otherwise -INF
    之後就背包。
*/

#define maxn 4005

int coins[3];
long long dp[maxn];

int main()
{
    int n;
    scanf("%d %d %d %d", &n, &coins[0], &coins[1], &coins[2]);
    fill(dp, dp + n, -0x3f3f3f3f3f3f3f3f);
    dp[0] = 0;
    for (int i = 0; i < 3; ++i)
    {
        for (int j = coins[i]; j <= n; ++j)
        {
            dp[j] = max(dp[j], dp[j - coins[i]] + 1);
        }
    }
    printf("%lld\n", dp[n]);
    return 0;
}