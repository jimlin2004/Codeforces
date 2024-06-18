#include <cstdio>
#include <algorithm>
using namespace std;

/*
    二分法找搜答案
    再用upper_bound快速確認答案
*/

#define maxn 200005

int arr[maxn];

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &arr[i]);
    }

    sort(arr, arr + n);

    bool ok = false;

    int l = 1, r = arr[n - 1] + 1;
    int mid;
    while (r - l >= 1)
    {
        mid = (l + r) >> 1;
        int leqLen = upper_bound(arr, arr + n, mid) - arr;
        if (leqLen == k)
        {
            printf("%d\n", mid);
            ok = true;
            break;
        }
        else if (leqLen < k)
            l = mid + 1;
        else
            r = mid;
    }
    if (!ok)
        printf("-1\n");
    return 0;
}