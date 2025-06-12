#include <bits/stdc++.h>
using namespace std;

/*
    簡單題目
    答案就是數列裡面最大的差距
    然後算一下多少時間可以解決那個差距
*/

#define maxn 100005

int A[maxn];

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n;
        scanf("%d", &n);

        for (int i = 1; i <= n; ++i)
            scanf("%d", &A[i]);

        int maxv = A[1];
        int maxDiff = -0x3f3f3f3f;

        // O(n)找最大差距
        for (int i = 2; i <= n; ++i)
        {
            maxDiff = max(maxDiff, maxv - A[i]);
            maxv = max(maxv, A[i]);
        }

        int res = 0;
        int m = 1;
        while (maxDiff > 0)
        {
            ++res;
            maxDiff -= m;
            m *= 2;
        }

        printf("%d\n", res);
    }

    return 0;
}