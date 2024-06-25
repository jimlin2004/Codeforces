#include <cstdio>
using namespace std;

#define maxn 500005

/*
    重點觀察
    假設輸入總和是S
    當可以切出3的part都一樣時
    代表每個part都等於S / 3

    問題可以轉為
    求前綴和中 prefixSum[i]為總和的2/3的切點之前
    有多少個點prefixSum[j]是總和的1/3
    全部加起來即可
    因為當找到為總和的2/3的點
    剩下的一定是part3(1/3 S)
    在i之前的那些1/3 S的點是part1
*/

long long prefixSum[maxn];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%lld", &prefixSum[i]);
        prefixSum[i] += prefixSum[i - 1];
    }

    long long S = prefixSum[n];
    if (S % 3 != 0 || n < 3)
    {
        puts("0");
        return 0;
    }
    long long partSum = S / 3;
    long long res = 0;
    //為總和的1/3的數量
    long long cnt = 0;
    for (int i = 1; i < n; ++i)
    {
        // 2/3 S的點
        if (prefixSum[i] == partSum * 2)
        {
            res += cnt;
        }
        if (prefixSum[i] == partSum)
        {
            cnt++;
        }
    }
    printf("%lld\n", res);
    return 0;
}