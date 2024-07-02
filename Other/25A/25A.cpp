#include <cstdio>

//超水題

int main()
{
    long long even;
    long long odd;
    long long evenCnt = 0;
    long long oddCnt = 0;
    int n;
    scanf("%d", &n);
    long long a;
    for (int i = 1; i <= n; ++i)
    {
        scanf("%lld", &a);
        if (a & 1 == 1)
        {
            ++oddCnt;
            odd = i;
        }
        else
        {
            ++evenCnt;
            even = i;
        }
    }
    if (oddCnt == 1)
        printf("%lld\n", odd);
    else
        printf("%lld\n", even);

    return 0;
}