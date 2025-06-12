#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define maxn 200005

int A[maxn];

//dp[i][j] -> 當最後打到第i位boss時，現在是j的回合，最少需要多少點數
//j = 0 -> friend, j = 1 -> 自己
//一路dp過去就行了
int dp[maxn][2];

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        memset(dp, 0x3f, sizeof(dp));
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i)
        {
            scanf("%d", &A[i]);
        }
        
        dp[0][0] = dp[0][1] = 0x3f3f3f3f;
        dp[1][0] = A[1];
        dp[2][0] = A[1] + A[2];
        for (int i = 2; i <= n; ++i)
        {
            dp[i][0] = min({dp[i][0], dp[i - 1][1] + A[i], dp[i - 2][1] + A[i] + A[i - 1]});
            dp[i][1] = min(dp[i - 1][0], dp[i - 2][0]);
        }
        printf("%d\n", min(dp[n][0], dp[n][1]));
    }
    return 0;
}