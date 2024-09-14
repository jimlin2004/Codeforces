#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

/*
    用線段樹維護括號
    合併區間的方法:
    int completeCnt = min(st[index << 1].left, st[(index << 1) + 1].right);
    st[index].cnt = st[index << 1].cnt + st[(index << 1) + 1].cnt + completeCnt;
    st[index].left = st[index << 1].left + st[(index << 1) + 1].left - completeCnt;
    st[index].right = st[index << 1].right + st[(index << 1) + 1].right - completeCnt;
*/

#define maxn 1000005

struct Node
{
    //左括號
    int left = 0;
    //右括號
    int right = 0;
    //完整的括號數
    int cnt = 0;
};

Node st[maxn << 2];
char line[maxn];

void build(int index, int l, int r)
{
    if (l == r)
    {
        if (line[l] == '(')
            st[index].left = 1;
        else
            st[index].right = 1;
        return;
    }

    int mid = l + ((r - l) >> 1);
    build(index << 1, l, mid);
    build((index << 1) + 1, mid + 1, r);

    //合併區間
    int completeCnt = min(st[index << 1].left, st[(index << 1) + 1].right);
    st[index].cnt = st[index << 1].cnt + st[(index << 1) + 1].cnt + completeCnt;
    st[index].left = st[index << 1].left + st[(index << 1) + 1].left - completeCnt;
    st[index].right = st[index << 1].right + st[(index << 1) + 1].right - completeCnt;
}

Node query(int index, int l, int r, int ql, int qr)
{
    if (ql <= l && r <= qr)
        return st[index];
    int mid = l + ((r - l) >> 1);
    Node res, L, R;
    if (ql <= mid)
        L = query(index << 1, l, mid, ql, qr);
    if (mid < qr)
        R = query((index << 1) + 1, mid + 1, r, ql, qr);
    
    int completeCnt = min(L.left, R.right);
    res.cnt = L.cnt + R.cnt + completeCnt;
    res.left = L.left + R.left - completeCnt;
    res.right = L.right + R.right - completeCnt;
    return res;
}

int main()
{
    scanf("%s", line + 1);
    int n = strlen(line + 1);
    build(1, 1, n);
    int m;
    scanf("%d", &m);
    int l, r;
    for (int i = 0; i < m; ++i)
    {
        scanf("%d %d", &l, &r);
        printf("%d\n", query(1, 1, n, l, r).cnt * 2);
    }
    return 0;
}