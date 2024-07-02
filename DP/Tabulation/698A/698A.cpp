#include <cstdio>
#include <algorithm>
using namespace std;

/*
    0 -> 只能休息
    1 -> 只能比賽或休息
    2 -> 只能運動或休息
    3 -> 可比賽或運動

    定義dp[第幾天][做什麼]
    之後轉移式就很簡單了
    轉移式看下面
    基本就是不能做的就設無限大
    休息就挑前一天做任何事中最小的+1
    最後答案就是dp[n][0]、dp[n][1]、dp[n][2]取最小的即為答案(dp[n]裡會有無限大的，但不影響答案)
*/

#define maxn 105

//dp[第幾天][做什麼]
int dp[maxn][5];
int a[maxn];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] == 0)
        {
            dp[i][0] = min({dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]}) + 1;
            dp[i][1] = 0x3f3f3f3f;
            dp[i][2] = 0x3f3f3f3f;
        }
        else if (a[i] == 1)
        {
            dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]);
            dp[i][2] = 0x3f3f3f3f;
            dp[i][0] = min({dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]}) + 1;
        }
        else if (a[i] == 2)
        {
            dp[i][1] = 0x3f3f3f3f;
            dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]);
            dp[i][0] = min({dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]}) + 1;
        }
        else
        {
            dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]);
            dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]);
            dp[i][0] = 0x3f3f3f3f;
        }
    }
    printf("%d\n", min({dp[n][0], dp[n][1], dp[n][2]}));
    return 0;
}