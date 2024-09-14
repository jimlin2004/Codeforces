#include <cstdio>
using namespace std;

const unsigned int maxn = (1 << 17) + 5;
// segment tree
unsigned int st[4 * maxn];

bool update(unsigned int val, int p, int index, int l, int r)
{
    if (l == r)
    {
        st[index] = val;
        //leaf的上一層要做or
        return true;
    }
    int mid = (l + r) >> 1;
    
    //這一層做or
    bool isOr;
    if (p <= mid)
        isOr = update(val, p, index << 1, l, mid);
    else
        isOr = update(val, p, (index << 1) + 1, mid + 1, r);

    if (isOr)
        st[index] = st[index << 1] | st[(index << 1) + 1];
    else
        st[index] = st[index << 1] ^ st[(index << 1) + 1];
    return !isOr;
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    unsigned int val;
    unsigned int limit = 1 << n;
    for (int i = 1; i <= limit; ++i)
    {
        scanf("%u", &val);
        update(val, i, 1, 1, limit);
    }

    unsigned int p, b;
    for (int i = 0; i < m; ++i)
    {
        scanf("%u %u", &p, &b);
        update(b, p, 1, 1, limit);
        printf("%u\n", st[1]);
    }
    return 0;
}