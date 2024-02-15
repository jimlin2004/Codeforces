#include <cstdio>

int main()
{
    int t;
    scanf("%d", &t);
    int res = 0;
    while (t--)
    {
        int count = 0;
        int temp;
        for (int i = 0; i < 3; ++i)
        {
            scanf("%d", &temp);
            count += temp;
        }
        if (count >= 2)
            ++res;
    }
    printf("%d\n", res);
    return 0;
}