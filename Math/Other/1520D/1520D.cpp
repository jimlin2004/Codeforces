#include <cstdio>
#include <unordered_map>
#include <vector>
using namespace std;

/*
    思考題
    a_j - a_i = j - i 移向
    => a_j - j = a_i - i
    看作b_j = b_i
    所以問題變成給定b_j求有多少個b_i

    用hash可以壓到O(n)
*/

//mp<b_i值, 與b_i相同值的有幾個>
unordered_map<long long, long long> mp;

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        mp.clear();
        int n;
        scanf("%d", &n);
        long long temp;
        long long res = 0;
        for (int i = 0; i < n; ++i)
        {
            scanf("%lld", &temp);
            res += mp[temp - i];
            ++mp[temp - i];
        }
        printf("%lld\n", res);
    }
    return 0;
}