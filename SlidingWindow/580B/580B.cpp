#include <cstdio>
#include <algorithm>
using namespace std;

#define maxn 100005

struct Friend
{
    long long money;
    long long friendship;
    bool operator < (const Friend& other) const
    {
        return this->money < other.money;
    }
};

Friend friends[maxn];

int main()
{
    long long n, d;
    scanf("%lld %lld", &n, &d);
    for (int i = 0; i < n; ++i)
        scanf("%lld %lld", &friends[i].money, &friends[i].friendship);

    sort(friends, friends + n);

    // SlidingWindow
    long long res = 0;
    long long windowSum = 0;
    int l = 0, r = 0;

    while (l < n && r < n)
    {
        windowSum += friends[r].friendship;
        while (friends[r].money - friends[l].money >= d)
        {
            windowSum -= friends[l].friendship;
            ++l;
        }
        res = max(res, windowSum);
        ++r;
    }
    printf("%lld\n", res);
    return 0;
}