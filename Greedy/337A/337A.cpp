#include <cstdio>
#include <algorithm>
using namespace std;

//利用sort快速找到n個puzzle區間的最大最小值，
//並利用sort去保證可以找到的差距最小的一組(sort使相鄰元素相差變少)
//(Greedy)

int main()
{
    int n, m;
    int puzzles[55];
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; ++i)
        scanf("%d", &puzzles[i]);
    sort(puzzles, puzzles + m);
    int res = 0x3f3f3f3f;
    for (int i = 0, j = i + (n - 1); j < m; ++i, ++j)
    {
        res = min(res, puzzles[j] - puzzles[i]);
    }
    printf("%d\n", res);
    return 0;
}