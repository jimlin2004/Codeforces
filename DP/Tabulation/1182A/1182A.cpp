#include <cstdio>
using namespace std;

#define maxn 65

/*
    簡單dp
    每個3*2有兩種，所以一直dp[i] = dp[i - 1] * 2即可
    i is odd -> 0
*/

long long dp[65];

int main()
{
    dp[0] = 1;
    for (int i = 2; i < maxn; ++i)
    {
        if (i % 2 == 0)
            dp[i] = dp[i - 2] * 2;
        else
            dp[i] = 0;
    }
    int n;
    scanf("%d", &n);
    printf("%lld\n", dp[n]);
    return 0;
}