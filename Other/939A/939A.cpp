#include <cstdio>
using namespace std;

//如果用有向圖去dfs要記得環中只能有三個點!!!

int love[5005];

int main()
{
    int n;
    scanf("%d", &n);
    bool ok = true;
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &love[i]);
    }

    for (int i = 1; i <= n; ++i)
    {
        if (love[love[love[i]]] == i)
            ok = false;
    }

    puts((ok) ? "NO" : "YES");
    return 0;
}