#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

//水題

#define maxn 100005

int dp[maxn];
int a[maxn];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    a[0] = -0x3f3f3f3f;
    int res = -0x3f3f3f3f;
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] > a[i - 1])
            dp[i] = dp[i - 1] + 1;
        else
            dp[i] = 1;
        
        res = max(res, dp[i]);
    }
    printf("%d\n", res);
    return 0;
}