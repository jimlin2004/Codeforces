#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

//用cnt[]統計輸入的數值個數後直接枚舉就完了

#define maxn 8005

int a[maxn];
//統計輸入出現的每個數值個數
int cnt[maxn];

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        memset(cnt, 0, sizeof(cnt));
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i)
        {
            scanf("%d", &a[i]);
            ++cnt[a[i]];
        }
        long long res = 0;
        for (int i = 1; i < n; ++i)
        {
            long long curr = a[i];
            for (int j = i + 1; j <= n; ++j)
            {
                curr += a[j];
                if (curr > n)
                    break;
                res += cnt[curr];
                cnt[curr] = 0;
            }
        }
        printf("%lld\n", res);
    }
    return 0;
}