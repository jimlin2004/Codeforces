#include <cstdio>
#include <algorithm>
using namespace std;

/*
    觀察到題目數值小，所以可以在數值上做文章
    首先刪掉數字很麻煩
    最簡單的方式是類似count sort
    先用cnt[]統計每個數字出現過的數量

    dp[x][0]代表數字x不選
    dp[x][1]代表數字x選
    那dp轉移式就簡單了
    x如果要選，x - 1就不能選，否則x會被x-1刪去
    所以dp[x][1] = dp[x - 1][0] + cnt[x] * x
    x不選，則x - 1可選可不選
    所以dp[x][0] = max(dp[x - 1][0], dp[x - 1][1])

    最後答案在max(dp[maxn - 1][0], dp[maxn - 1][1])
*/

#define maxn 100005

unsigned long long cnt[maxn];
unsigned long long dp[maxn][2];

int main()
{
    int n;
    scanf("%d", &n);
    int num;
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &num);
        ++cnt[num];
    }

    for (int i = 1; i < maxn; ++i)
    {
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
        dp[i][1] = dp[i - 1][0] + (i * cnt[i]);
    }

    printf("%llu\n", max(dp[maxn - 1][0], dp[maxn - 1][1]));
    return 0;
}