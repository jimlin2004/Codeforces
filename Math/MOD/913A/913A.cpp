#include <cstdio>

//不可能算2^(10e8)
//x mod y = x (when x < y), 所以觀察
//log2(10e8) = 26.5...
//所以只要題目的n >= 27直接回傳
//n < 27直接計算

int pow2[30] = {1};

int main()
{
    for (int i = 1; i < 27; ++i)
    {
        pow2[i] = 2 * pow2[i - 1];
    }
    int n, m;
    scanf("%d", &n);
    scanf("%d", &m);
    if (n >= 27)
        printf("%d\n", m);
    else
        printf("%d\n", m % pow2[n]);
    return 0;
}