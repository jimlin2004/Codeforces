#include <cstdio>
using namespace std;

#define maxn 100005
#define MOD 1000000007

/*
    dp[i]代表i個花朵種共有幾種方法
    可以發現當第i格要填R時，總共有dp[i - 1]種方法
    而第i格要填W時，代表前k - 1個都要填W，否則會不合法，共有dp[i - k]種方法 (因為最後k個被限制為W)

    所以可以推出轉移式
    dp[i] = dp[i - 1] - dp[i - k]

    另外當dp[]推完後
    可以用前綴和處理很多次的詢問
*/
long long dp[maxn];
long long prefixSum[maxn];

int main()
{
    int t, k;
    scanf("%d %d", &t, &k);
    // k朵花以下只能放R，0種也算一種(為了轉移式的dp[k])
    for (int i = 0; i < k; ++i)
        dp[i] = 1;
    for (int i = k; i < maxn; ++i)
        dp[i] = (dp[i - 1] + dp[i - k]) % MOD;
    for (int i = 1; i < maxn; ++i)
        prefixSum[i] = (prefixSum[i - 1] + dp[i]) % MOD;

    int a, b;
    while (t--)
    {
        scanf("%d %d", &a, &b);
        //注意mod的減法
        printf("%lld\n", (prefixSum[b] - prefixSum[a - 1] + MOD) % MOD);
    }
    return 0;
}