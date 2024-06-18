#include <cstdio>
#include <algorithm>
using namespace std;

/*
    prefix sum 找區間翻轉後或不翻轉的最大方式
    O(n ^ 2)
    可以用Kadane O(n)
*/

#define maxn 105

int prefixSumOf0[maxn];
int prefixSumOf1[maxn];

int main()
{
    int n;
    scanf("%d", &n);
    int in;
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &in);
        if (in == 0)
        {
            prefixSumOf0[i] = prefixSumOf0[i - 1] + 1;
            prefixSumOf1[i] = prefixSumOf1[i - 1];
        }
        else
        {
            prefixSumOf1[i] = prefixSumOf1[i - 1] + 1;
            prefixSumOf0[i] = prefixSumOf0[i - 1];
        }
    }
    int res = -0x3f3f3f3f;

    for (int i = 1; i <= n; ++i)
    {
        for (int j = i; j <= n; ++j)
        {
            int numOf0 = prefixSumOf0[j] - prefixSumOf0[i - 1];
            int numOf1 = prefixSumOf1[j] - prefixSumOf1[i - 1];
            
            res = max({res, (prefixSumOf1[n] + (prefixSumOf0[j] - prefixSumOf0[i - 1]) - (prefixSumOf1[j] - prefixSumOf1[i - 1]))});
        }
    }

    printf("%d\n", res);

    return 0;
}