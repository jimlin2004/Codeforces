#include <cstdio>

/*
    要思考一下
    然後會發現每天細菌都*2
    有時有幾天可以加1隻進去
    事實上最少要加的次數就是
    x轉成二進位後1的數量
    ex: 5 -> 101
    代表的就是第1天與第3天加入1隻細菌
    bitwise << 1對應到細菌*2的操作
*/

int main()
{
    int res = 0;
    int x;
    scanf("%d", &x);
    while (x)
    {
        res += (x & 1);
        x >>= 1;
    }
    printf("%d\n", res);
    return 0;
}