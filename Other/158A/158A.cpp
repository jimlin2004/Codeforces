#include <cstdio>
using namespace std;

int scores[55];

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &scores[i]);
    }
    int res = 0;
    for (int i = 0; i < k; ++i)
    {
        if (scores[i] > 0)
            ++res;
    }
    for (int i = k; i < n; ++i)
    {
        if (scores[i] == scores[k - 1] && scores[i] > 0)
            ++res;
        else
            break;
    }
    printf("%d\n", res);
    return 0;
}