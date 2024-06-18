#include <cstdio>
#include <algorithm>
using namespace std;

/*
    做兩個prefix sum即可
*/

#define maxn 100005

long long prefixSum[maxn];
long long sortedPrefixSum[maxn];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%lld", &prefixSum[i]);
        sortedPrefixSum[i] = prefixSum[i];
    }

    sort(sortedPrefixSum + 1, sortedPrefixSum + 1 + n);

    for (int i = 1; i <= n; ++i)
    {
        prefixSum[i] += prefixSum[i - 1];
        sortedPrefixSum[i] += sortedPrefixSum[i - 1];
    }
        
    int m;
    scanf("%d", &m);
    int type, l, r;
    for (int i = 0; i < m; ++i)
    {
        scanf("%d %d %d", &type, &l, &r);
        if (type == 1)
            printf("%lld\n", prefixSum[r] - prefixSum[l - 1]);
        else if (type == 2)
            printf("%lld\n", sortedPrefixSum[r] - sortedPrefixSum[l - 1]);
    }
    return 0;
}