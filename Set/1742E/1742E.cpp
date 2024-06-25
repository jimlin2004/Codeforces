#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

#define maxn 200005

/*
    總之就是之前算過的繼續拿來用
*/

//紀錄之前的答案
struct Ans
{
    long long leg; //腳的長度
    int index; //最多可以跨到多少階
    long long res; //跨了多少
    bool operator < (const Ans& other) const
    {
        return this->leg < other.leg;
    }

    bool operator == (const Ans& other) const
    {
        return this->leg == other.leg;
    }
};

//用set加速後面的算法
set<Ans> cache;

long long steps[maxn];

void solve(Ans& ans, int indexStart, long long res, int n)
{
    ans.index = indexStart;
    ans.res = res;
    for (int i = indexStart + 1; i< n; ++i)
    {
        if (ans.leg >= steps[i])
        {
            ++ans.index;
            ans.res += steps[i];
        }
        else
            break;
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        cache.clear();

        int n, q;
        scanf("%d %d", &n, &q);
        for (int i = 0; i < n; ++i)
        {
            scanf("%lld", &steps[i]);
        }

        long long leg;

        for (int i = 0; i < q; ++i)
        {
            scanf("%lld", &leg);
            Ans ans = {leg, 0, 0};
            auto it = cache.upper_bound(ans);
            if (cache.empty())
            {
                solve(ans, -1, 0, n);
                cache.insert(ans);
            }
            else if (it == cache.begin())
            {
                //比cache的第一個還小
                solve(ans, -1, 0, n);
                cache.insert(ans);
            }
            else if (it == cache.end())
            {
                //抓最後一個
                auto prevAnsPtr = --cache.end();
                solve(ans, prevAnsPtr->index, prevAnsPtr->res, n);
                cache.insert(ans);
            }
            else
            {
                //要的是小於等於leg的
                auto prevAnsPtr = --it;
                solve(ans, prevAnsPtr->index, prevAnsPtr->res, n);
                cache.insert(ans);
            }

            if (i != 0)
                printf(" %lld", ans.res);
            else
                printf("%lld", ans.res);
        }
        puts("");
    }
    return 0;
}