#include <cstdio>
using namespace std;

//把題目當成counting sort，但不用排，
//只需要知道數字i有C[i]個數字小於等於i

#define maxX 100005

//counting sort
int C[maxX];

int main()
{
    int n;
    scanf("%d", &n);
    int num;
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &num);
        ++C[num];
    }
    for (int i = 1; i < maxX; ++i)
    {
        C[i] += C[i - 1];
    }
    int q;
    scanf("%d", &q);
    int m;
    for (int i = 0; i < q; ++i)
    {
        scanf("%d", &m);
        if (m >= maxX - 1)
            printf("%lld\n", C[maxX - 1]);
        else
            printf("%lld\n", C[m]);
    }
    return 0;
}