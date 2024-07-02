#include <cstdio>
#include <cmath>

//簡單數學題

int main()
{
    long long n, m, a;
    scanf("%lld %lld %lld", &n, &m, &a);
    printf("%lld\n", (long long)(ceil(n / (1.0 * a))) * (long long)(ceil(m / (1.0 * a))));
    return 0;
}