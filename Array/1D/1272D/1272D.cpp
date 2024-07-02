#include <cstdio>
#include <algorithm>
using namespace std;

/*
    解法很簡單
    先準備好inc[]由左至右上升、dec[]//由右至左下降
    之後剩下看是inc[i]比較好
    還是inc[i - 1] + dec[i + 1](也就是去掉a[i] if a[i - 1] < a[i + 1])比較好
*/

#define maxn 200005

//由左至右上升
int inc[maxn];
//由右至左下降
int dec[maxn];
int a[maxn];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    inc[1] = 1;
    for (int i = 2; i <= n; ++i)
    {
        if (a[i - 1] < a[i])
            inc[i] = inc[i - 1] + 1;
        else
            inc[i] = 1;
    }
    dec[n] = 1;
    for (int i = n - 1; i >= 0; --i)
    {
        if (a[i] < a[i + 1])
            dec[i] = dec[i + 1] + 1;
        else
            dec[i] = 1;
    }

    int res = 0;
    a[0] = 0x3f3f3f3f;
    a[n + 1] = -0x3f3f3f3f;
    for (int i = 1; i <= n; ++i)
    {
        res = max(res, inc[i]);
        if (a[i - 1] < a[i + 1])
        {
            res = max(res, inc[i - 1] + dec[i + 1]);
        }
    }
    printf("%d\n", res);
    return 0;
}