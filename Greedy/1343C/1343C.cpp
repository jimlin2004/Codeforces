#include <cstdio>
#include <algorithm>
using namespace std;

/*
    題目目標:
        在保證最大長度交替序列b(b由a保留順序又b中的元素是+-+-+..或-+-+-...)的限制下
        求b的和要最大
        所以解法就是
        ex:
            [1,1,2,−1,−5,2,1,−3]先切出
            [1,1,2], [−1,−5], [2,1], [−3]
            因為要交替，所以切成這樣
            和要最大，所以就是在每個切出來的子區段挑最大的出來
        O(n)可解決
*/

#define maxn 200005

long long arr[maxn];

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
        {
            scanf("%lld", &arr[i]);
        }

        //雙指標切arr[]
        int l = 0, r = 0;
        long long res = 0;
        long long currMax = -0x3f3f3f3f3f3f3f3f;
        while (r < n)
        {
            //不同號
            if ((arr[l] < 0 && arr[r] >= 0) || (arr[l] >= 0 && arr[r] < 0))
            {
                res += currMax;
                currMax = arr[r];
                l = r;
            }
            else
            {
                currMax = max(currMax, arr[r]);
                ++r;
            }
        }
        if (currMax != -0x3f3f3f3f3f3f3f3f)
            res += currMax;
        printf("%lld\n", res);
    }
    return 0;
}