#include <cstdio>

int main()
{
    int w;
    scanf("%d", &w);
    bool ok = false;
    for (int i = 2; i <= 50; i += 2)
    {
        if (w <= i)
            break;
        if ((w - i) % 2 == 0)
        {
            ok = true;
            break;
        }
    }
    printf("%s\n", (ok) ? "YES" : "NO");
    return 0;
}