#include <cstdio>
#include <cstring>

//搜看看有沒有BA在AB之後，以及有沒有AB在BA之後

#define maxn 100005

char str[maxn];

bool check(int from, int len, const char* target)
{
    for (int i = from; i < len - 1; ++i)
    {
        if (str[i] == target[0] && str[i + 1] == target[1])
            return true;
    }
    return false;
}

int main()
{
    scanf("%s", str);
    int len = strlen(str);
    bool ok = false;
    //找第一個AB
    for (int i = 0; i < len - 1; ++i)
    {
        if (str[i] == 'A' && str[i + 1] == 'B')
        {
            ok = check(i + 2, len, "BA");
            if (ok)
                break;
        }
    }
    if (!ok)
    {
        //找第一個BA
        for (int i = 0; i < len - 1; ++i)
        {
            if (str[i] == 'B' && str[i + 1] == 'A')
            {
                ok = check(i + 2, len, "AB");
                if (ok)
                    break;
            }
        }
    }
    puts((ok) ? "YES" : "NO");
    return 0;
}