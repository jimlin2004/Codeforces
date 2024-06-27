#include <cstdio>
#include <cstring>
using namespace std;

#define maxn 105
#define MOD 100000000

//dp[n1][n2][0] -> 代表剩下n1 + n2人時最前面放的是footmen
//dp[n1][n2][1] -> 代表剩下n1 + n2人時最前面放的是horsemen
//轉移式看下面應該就懂，注意邊界條件(此用記憶化搜尋)
long long dp[maxn][maxn][2];
int k1, k2;

//prev是代表此遞迴最前面只能放什麼兵種
long long solve(int n1, int n2, int type)
{
    if (n1 < 0 || n2 < 0)
        return 0;

    if (dp[n1][n2][type] != -1)
        return dp[n1][n2][type];
    long long res = 0;
    if (type == 0)
    {
        for (int i = 1; i <= k1; ++i)
        {
            if (n1 - i < 0)
                break;
            res = (res + solve(n1 - i, n2, 1)) % MOD;
        }

        return dp[n1][n2][type] = (res % MOD);
    }
    else
    {
        for (int i = 1; i <= k2; ++i)
        {
            if (n2 - i < 0)
                break;
            res = (res + solve(n1, n2 - i, 0)) % MOD;
        }

        return dp[n1][n2][type] = (res % MOD);
    }
}

int main()
{
    int n1, n2;
    scanf("%d %d %d %d", &n1, &n2, &k1, &k2);
    memset(dp, -1, sizeof(dp));
    dp[0][0][0] = dp[0][0][1] = 0;
    for (int i = 1; i <= 50; ++i)
    {
        if (i <= k1)
            dp[i][0][0] = 1;
        if (i <= k2)
            dp[0][i][1] = 1;
    }

    printf("%lld\n", (solve(n1, n2, 0) + solve(n1, n2, 1)) % MOD);
    return 0;
}