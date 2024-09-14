#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

/*
    題意跟解法很清楚
    就是查詢次數越多次的indexB[]乘上A[]越大的值最後結果就會越大(簡單貪婪)
    答案為sum(A[i] * B[i]) 
    因此這題難點在於要處理統計查詢次數的B[]
    由於是區間修改，最簡單的方式就是直接套線段樹
    最後將A[]與B[]分別由小到大排序後
    每個A[i]、B[i]相乘加起來即可
*/

#define maxn 200005

unsigned long long st[maxn << 2];
unsigned long long tag[maxn << 2];

vector<unsigned long long> queryTimes;
vector<unsigned long long> A;

void update(int ql, int qr, int l, int r, int i, unsigned long long c)
{
    if (ql <= l && r <= qr)
    {
        st[i] += (r - l + 1) * c;
        tag[i] += c;
        return;
    }
    int mid = l + ((r - l) >> 1);
    if (tag[i] && l != r)
    {
        st[i * 2] += tag[i] * (mid - l + 1);
        st[i * 2 + 1] += tag[i] * (r - mid);
        tag[i * 2] += tag[i];
        tag[i * 2 + 1] += tag[i];
        tag[i] = 0;
    }
    if (ql <= mid)
        update(ql, qr, l, mid, i * 2, c);
    if (mid < qr)
        update(ql, qr, mid + 1, r, i * 2 + 1, c);
    st[i] = st[i * 2] + st[i * 2 + 1];
}

// 這個查詢不是一般線段樹的查詢，是一次對所有1~n做單點查詢
void query(int ql, int qr, int l, int r, int i)
{
    if (l == r)
    {
        queryTimes.emplace_back(st[i]);
        return;
    }
    int mid = l + ((r - l) >> 1);
    if (tag[i])
    {
        st[i * 2] += tag[i] * (mid - l + 1);
        st[i * 2 + 1] += tag[i] * (r - mid);
        tag[i * 2] += tag[i];
        tag[i * 2 + 1] += tag[i];
        tag[i] = 0;
    }
    if (ql <= mid)
        query(ql, mid, l, mid, i * 2);
    if (mid < qr)
        query(ql, qr, mid + 1, r, i * 2 + 1);
}

int main()
{
    int n, q;
    scanf("%d %d", &n, &q);
    unsigned long long num;
    for (int i = 0; i < n; ++i)
    {
        scanf("%llu", &num);
        A.emplace_back(num);
    }
    int l, r;
    for (int i = 0; i < q; ++i)
    {
        scanf("%d %d", &l, &r);
        update(l, r, 1, n, 1, 1);
    }
    
    query(1, n, 1, n, 1);
    
    sort(A.begin(), A.end(), greater<unsigned long long>());
    sort(queryTimes.begin(), queryTimes.end(), greater<unsigned long long>());
    unsigned long long res = 0;
    for (int i = 0; i < queryTimes.size(); ++i)
    {
        res += queryTimes[i] * A[i];
    }
    printf("%llu\n", res);
    return 0;
}