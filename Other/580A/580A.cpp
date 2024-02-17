#include <cstdio>

#define max(a, b) (a < b) ? b : a

int main()
{
    int n;
    scanf("%d", &n);
    int res = 0;
    int count = 1;
    int prev, curr;
    scanf("%d", &prev);
    for (int i = 1; i < n; ++i)
    {
        scanf("%d", &curr);
        if (prev <= curr)
            ++count;
        else
        {
            res = max(count, res);
            count = 1;
        }
        prev = curr;
    }
    res = max(count, res);
    printf("%d\n", res);
    return 0;
}