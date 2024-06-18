#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    int n, m, a, b;
    scanf("%d %d %d %d", &n, &m, &a, &b);

    //完全沒必要買m程票
    if (m * a <= b)
        printf("%d\n", n * a);
    else
        printf("%d\n", (n / m) * b + min((n % m) * a, b));

    return 0;
}