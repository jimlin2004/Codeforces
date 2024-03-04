#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char axis[105];
//dp[i]: 跳到i的最小成本
int dp[105];

int main()
{
    int n, d;
    scanf("%d %d", &n, &d);
    scanf("%s", axis);

    memset(dp, 0x3f, sizeof(dp));

    dp[0] = 0;

    for (int i = 0; i < n; ++i)
    {
        if (axis[i] == '1')
        {
            for (int j = 1; j <= d; ++j)
            {
                if (i + j < n)
                {
                    if (axis[i + j] == '1')
                        dp[i + j] = min(dp[i + j], dp[i] + 1);
                }
                else
                    break;
            }
        }
    }

    if (dp[n - 1] == 0x3f3f3f3f)
        puts("-1");
    else
        printf("%d\n", dp[n - 1]);

    return 0;
}