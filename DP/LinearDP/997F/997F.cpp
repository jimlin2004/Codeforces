#include <cstdio>
#include <unordered_map>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

#define maxn 200005

//與LIS類似，只是改成dp[x] -> 序列最後為x能有多長
//用hash map是為了離散化(數值範圍太大)
// unordered_map<int, int> dp; <- 會超時QQ
map<int, int> dp;

int arr[maxn];

int main()
{
    int n;
    scanf("%d", &n);
    int x;
    int maxLen = -0x3f3f3f3f;
    int lastX = -1;
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &arr[i]);
        x = arr[i];
        
        dp[x] = dp[x - 1] + 1;

        if (maxLen < dp[x])
        {
            maxLen = dp[x];
            lastX = x;
        }
    }

    vector<int> res;

    for (int i = n; i >= 1; --i)
    {
        if (arr[i] == lastX)
        {
            res.emplace_back(i);
            --lastX;
        }
    }

    printf("%d\n", maxLen);
    for (int i = res.size() - 1; i >= 0; --i)
    {
        printf("%d ", res[i]);
    }
    puts("");
    return 0;
}