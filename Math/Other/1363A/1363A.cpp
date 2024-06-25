#include <cstdio>

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int oddCnt = 0;
        int evenCnt = 0;
        int n, x;
        scanf("%d %d", &n, &x);
        int temp;
        for (int i = 0; i < n; ++i)
        {
            scanf("%d", &temp);
            if (temp % 2 == 0)
                ++evenCnt;
            else
                ++oddCnt;
        }

        bool ok = false;
        //奇數個odd加起來才會是odd
        for (int i = 1; i <= oddCnt; i += 2)
        {
            if (x - i < 0)
                break;
            if (evenCnt >= (x - i))
            {
                ok = true;
                break;
            }
        }
        
        puts((ok) ? "Yes" : "No");
    }
    return 0;
}