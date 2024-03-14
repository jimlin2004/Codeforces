#include <cstdio>

#define maxn 100005

//二分搜找出第一個>=target的數字

long long prefix[maxn];

int n;

void binarySearch(long long x)
{
    int l = 1, r = n + 1;
    int mid;
    while (l < r)
    {
        mid = (l + r) / 2;
        if (prefix[mid] >= x)
            r = mid;
        else
            l = mid + 1;
    } 
    printf("%d\n", l);
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%lld", &prefix[i]);
        prefix[i] += prefix[i - 1];
    }

    int m;
    scanf("%d", &m);
    int target;
    while (m--)
    {
        scanf("%d", &target);
        binarySearch(target);
    }
    return 0;
}