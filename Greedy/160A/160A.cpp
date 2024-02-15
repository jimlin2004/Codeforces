#include <cstdio>
#include <algorithm>
#include <functional>
using namespace std;

int coins[105];

int main()
{
    int n;
    scanf("%d", &n);
    int total = 0;
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &coins[i]);
        total += coins[i];
    }
    sort(coins, coins + n, greater<int>());
    int sum = 0;
    for (int i = 0; i < n; ++i)
    {
        sum += coins[i];
        if (sum * 2 > total)
        {
            printf("%d\n", i + 1);
            break;
        }
    }
    return 0;
}