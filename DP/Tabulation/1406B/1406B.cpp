#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

#define maxn 200005

//fill會超時 QQ

//一個記最小，一個記最大
//maxProduct[i][j]代表只用前i個時j個乘起來最大的
//最小的乘上負值可能變最大
// long long maxProduct[maxn][10];
// long long minProduct[maxn][10];
vector<vector<long long>> maxProduct;
vector<vector<long long>> minProduct;

//dp轉移式看底下應該算簡單

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        // fill(&maxProduct[0][0], &maxProduct[0][0] + sizeof(maxProduct) / sizeof(maxProduct[0][0]), -0x3f3f3f3f3f3f3f3f);
        // fill(&minProduct[0][0], &minProduct[0][0] + sizeof(minProduct) / sizeof(minProduct[0][0]), 0x3f3f3f3f3f3f3f3f);
        int n;
        scanf("%d", &n);

        maxProduct.assign(n + 5, vector<long long>(6, -0x3f3f3f3f3f3f3f3f));
        minProduct.assign(n + 5, vector<long long>(6, 0x3f3f3f3f3f3f3f3f));

        long long num;
        for (int i = 1; i <= n; ++i)
        {
            scanf("%lld", &num);
            maxProduct[i][1] = max(maxProduct[i - 1][1], num);
            minProduct[i][1] = min(minProduct[i - 1][1], num);
            for (int j = 2; j <= 5; ++j)
            {
                if (i >= j)
                {
                    maxProduct[i][j] = max(maxProduct[i - 1][j - 1] * num, minProduct[i - 1][j - 1] * num);
                    minProduct[i][j] = min(maxProduct[i - 1][j - 1] * num, minProduct[i - 1][j - 1] * num);
                    if (i - 1 >= j)
                    {
                        //當超過當前可選時，就可以選擇要現在的還是之前的
                        maxProduct[i][j] = max(maxProduct[i][j], maxProduct[i - 1][j]);
                        minProduct[i][j] = min(minProduct[i][j], minProduct[i - 1][j]);
                    }
                }
            }
        }
        printf("%lld\n", maxProduct[n][5]);
    }
    return 0;
}