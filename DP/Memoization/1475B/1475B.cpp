#include <cstdio>
#include <cstring>

//dp[n] -> n是否可以是2020, 2021的組合, YES: 1, NO: 0, unvisited: -1
int dp[1000005];

int solve(int n)
{
    if (n < 0)
        return 0;
    if (dp[n] != -1)
        return dp[n];
    return dp[n] = (solve(n - 2021) || solve(n - 2020));
}

int main()
{
    int t;
    int n;
    scanf("%d", &t);
    memset(dp, -1, sizeof(dp));
    dp[0] = 1;
    while (t--)
    {
        scanf("%d", &n);
        int res = solve(n);
        printf("%s\n", (res == 1) ? "YES" : "NO");
    }
    return 0;
}