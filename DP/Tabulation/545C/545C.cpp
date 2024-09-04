#include <cstdio>
#include <algorithm>
using namespace std;

#define maxn 100005

//定義好dp之後，轉移式就是枚舉所有狀態，看下方

long long pos[maxn];
long long height[maxn];
//dp[第幾棵樹][留 or 左倒 or 右倒]
long long dp[maxn][3];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%lld %lld", &pos[i], &height[i]);
    }
    pos[0] = -0x3f3f3f3f3f3f3f3f;
    height[0] = 0;
    pos[n + 1] = 0x3f3f3f3f3f3f3f3f;
    height[n + 1] = 0;
    for (int i = 1; i <= n; ++i)
    {
        //留
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
        if (pos[i] > pos[i - 1] + height[i - 1])
            dp[i][0] = max(dp[i][0], dp[i - 1][2]);
        //左倒
        if (pos[i - 1] < pos[i] - height[i])
        {
            dp[i][1] = max(dp[i - 1][0], dp[i - 1][1]);
        }
        if (pos[i - 1] + height[i - 1] < pos[i] - height[i])
        {
            dp[i][1] = max(dp[i][1], dp[i - 1][2]);
        }
        ++dp[i][1];
        //右倒
        if (pos[i] + height[i] < pos[i + 1])
        {
            dp[i][2] = max(dp[i - 1][0], dp[i - 1][1]);
        }
        if (pos[i - 1] + height[i - 1] < pos[i])
        {
            dp[i][2] = max(dp[i][2], dp[i - 1][2]);
        }
        ++dp[i][2];
    }
    printf("%lld\n", max({dp[n][0], dp[n][1], dp[n][2]}));
    return 0;
}