#include <cstdio>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

//Chtholly Tree 來源題(來膜拜的)
//重點: 輸入資料隨機

struct Node
{
    long long l, r;
    mutable long long val;
    Node(long long l, long long r, long long val)
        : l(l), r(r), val(val)
    {}
    bool operator < (const Node& other) const
    {
        return this->l < other.l;
    }
};

set<Node> chthollyTree;

//將[l, r] 拆成 [l, pos - 1], [pos, r]
set<Node>::iterator split(long long pos)
{
    //找第一個左端點大於等於pos的區間
    set<Node>::iterator it = chthollyTree.lower_bound(Node(pos, 0, 0));
    //運氣很好直接找到左端點是pos的區間
    if (it != chthollyTree.end() && it->l == pos)
        return it;
    //到這邊代表找到的是第一個左端點大於pos的區間
    //it - 1即可找到左端點等於pos的區間(不會是別的，因為沒有重疊的區間)
    --it;

    long long l = it->l, r = it->r;
    long long val = it->val;
    chthollyTree.erase(it);
    chthollyTree.insert(Node(l, pos - 1, val));
    //回傳左端點是pos的區間iterator
    return chthollyTree.insert(Node(pos, r, val)).first;
}

//區間賦值
void assign(long long l, long long r, long long val)
{
    //<注意> end與begin的順序不能調換，因為end的split可能會改變begin的區間
    //因為end可以在原本begin的區間中
    set<Node>::iterator end = split(r + 1), begin = split(l);
    //begin到end全部刪掉
    chthollyTree.erase(begin, end);
    //填回去[l, r]的區間
    chthollyTree.insert(Node(l, r, val));
}

//區間加值(直接一個個區間去加)
void add(long long l, long long r, long long val)
{
    set<Node>::iterator end = split(r + 1);
    set<Node>::iterator begin = split(l);
    for (set<Node>::iterator it = begin; it != end; ++it)
        it->val += val;
}

//查詢區間第k小
//直接把每個區間丟去vector排序
//暴力
long long getKthSmallest(long long l, long long r, long long k)
{
    set<Node>::iterator end = split(r + 1);
    set<Node>::iterator begin = split(l);
    
    //pair -> first: val, second: 區間長度
    vector<pair<long long, long long>> vec;
    for (set<Node>::iterator it = begin; it != end; ++it)
    {
        vec.push_back({it->val, it->r - it->l + 1});
    }

    sort(vec.begin(), vec.end());
    for (const pair<long long, long long>& p: vec)
    {
        k -= p.second;
        if (k <= 0)
            return p.first;
    }

    //不應該跑到這
    return -1;
}

//快速冪
long long qpow(long long x, long long n, long long mod)
{
    long long res = 1;
    x %= mod;
    while (n)
    {
        if (n & 1)
            res = res * x % mod;
        n >>= 1;
        x = x * x % mod;
    }
    return res;
}

//區間n次方和
long long sumOfPow(long long l, long long r, long long n, long long mod)
{
    long long total = 0;
    set<Node>::iterator end = split(r + 1);
    set<Node>::iterator begin = split(l);
    for (set<Node>::iterator it = begin; it != end; ++it)
    {
        total = (total + qpow(it->val, n, mod) * (it->r - it->l + 1)) % mod;
    }
    return total;
}

//題目要求的隨機產生算法
long long seed;
long long randInt()
{
    long long res = seed;
    seed = (seed * 7 + 13) % 1000000007;
    return res;
}

int main()
{
    long long n, m, vmax;
    scanf("%lld %lld %lld %lld", &n, &m, &seed, &vmax);
    for (int i = 1; i <= n; ++i)
    {
        long long res = randInt() % vmax + 1;
        chthollyTree.insert(Node(i, i, res));
    }
    for (int i = 1; i <= m; ++i)
    {
        long long cmd = randInt() % 4 + 1;
        long long l = randInt() % n + 1;
        long long r = randInt() % n + 1;
        long long x, y;

        if (l > r)
            swap(l, r);
        
        if (cmd == 3)
            x = randInt() % (r - l + 1) + 1;
        else
            x = randInt() % vmax + 1;
        
        if (cmd == 4)
            y = randInt() % vmax + 1;

        switch (cmd)
        {
        case 1:
            add(l, r, x);
            break;
        case 2:
            assign(l, r, x);
            break;
        case 3:
            printf("%lld\n", getKthSmallest(l, r, x));
            break;
        case 4:
            printf("%lld\n", sumOfPow(l, r, x, y));
            break;
        default:
            break;
        }
    }
    return 0;
}