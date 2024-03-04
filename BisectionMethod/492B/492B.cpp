#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

#define eps 1e-10

vector<int> lanterns;
int lanternCount = 0;
//道路總長
int len = 0;

bool canLightAll(double r)
{
    if (r < lanterns[0])
        return false;
    for (int i = 1; i < lanternCount; ++i)
    {
        int dis = lanterns[i] - lanterns[i - 1];
        if (2 * r < dis)
            return false;
    }
    if (r < (len - lanterns[lanternCount - 1]))
        return false;
    return true;
}

int main()
{
    int n;
    scanf("%d %d", &n, &len);

    int pos;

    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &pos);
        lanterns.emplace_back(pos);
    }

    sort(lanterns.begin(), lanterns.end());
    lanternCount = unique(lanterns.begin(), lanterns.end()) - lanterns.begin();

    double l = 0, r = len;
    double mid;

    // while (r - l > eps)
    // {
    //     mid = (l + r) / 2.0;
    //     if (canLightAll(mid))
    //         r = mid;
    //     else
    //         l = mid;
    // }

    //上面那個的時間會超過QQ

    for (int i = 0; i < 100; ++i)
    {
        mid = (l + r) / 2.0;
        if (canLightAll(mid))
            r = mid;
        else
            l = mid;
    }

    printf("%.10lf", l);

    return 0;
}