#include <cstdio>
#include <algorithm>
using namespace std;

/*
    greedy
    首先數字越長代表整個數字越大
    所以先拿mincost的數字找出答案最多有多長
    然後答案先設為mincost的數字(有v / mincost個)
    之後就是從數字的第一位開始看看能不能更大搜完即可
*/

#define maxn 1000005

int cost[10];
int ans[maxn];

int main()
{
    int v;
    scanf("%d", &v);
    int minCost = 0x3f3f3f3f;
    int minNum = -1;
    for (int i = 1; i <= 9; ++i)
    {
        scanf("%d", &cost[i]);
        if (minCost >= cost[i])
        {
            minCost = cost[i];
            minNum = i;
        }
    }
    //最長能多長
    int len = v / minCost;
    v -= len * minCost;

    for (int i = 0; i < len; ++i)
        ans[i] = minNum;
    
    for (int i = 0; i < len; ++i)
    {
        for (int j = 9; j > minNum; --j)
        {
            if (v + cost[minNum] - cost[j] >= 0)
            {
                v = v + cost[minNum] - cost[j];
                ans[i] = j;
                break;
            }
        }
    }

    if (len == 0)
        puts("-1");
    else
    {
        for (int i = 0; i < len; ++i)
        {
            printf("%d", ans[i]);
        }
        puts("");
    }
    return 0;
}