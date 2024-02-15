#include <cstdio>
using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    long long n;
    while (t--)
    {
        scanf("%lld", &n);
        long long res = 0;
        while (n)
        {
            res += n;
            n >>= 1;
        }
        printf("%lld\n", res);
    }
    return 0;
}