#include <cstdio>
using namespace std;

/*
n = 3, k = 7
1, 2, (3), 4, 5, (6), 7, 8, (9), 10

每個n的倍數會把答案右移1(假設共有need個)，
最後答案就是k + need

問題剩下need怎麼推
由上面的例子很明顯可看出可以分成
(一段長度n - 1)、(一段長度n - 1)、(一段長度n - 1)...
所以有幾段相當於第k個不被n整除之前有幾個整除的
1. 
    當(k % (n - 1) == 0)時代表最後面我們多算了個n的倍數
    所以need = (k / (n - 1)) - 1
2.
    當(k % (n - 1) != 0)時很簡單
    need = (k / (n - 1))
*/

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        long long n, k;
        scanf("%lld %lld", &n, &k);
        if (k % (n - 1) == 0)
            printf("%lld\n", k / (n - 1) - 1 + k);
        else
            printf("%lld\n", k / (n - 1) + k);
    }
    return 0;
}