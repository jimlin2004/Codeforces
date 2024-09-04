#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

/*
    Greedy

    觀察題目後會發現
    1. 選leaf不會影響到其他人(+depth[u]分)
    2. 若選擇中間節點，底下的child如果被選過就要-1
       (因為child計算的path中有一個變成工業都市了)
    3. 越遠的leaf先選可使總和變大

    綜合以上，一個node被選為工業城市時
    他可以提供(depth[u] - (subtreeSize[u] - 1))的happiness
    因為當一子樹中我選擇中間節點，之前一定已經把該點u之下的所有子樹都選過了
    否則如果選在一個有子樹點還沒選過的點還不如選在那個點，可以提供更多的happiness
    subtreeSize[u] - 1是去掉u
    最後將所有happiness sort從大的取即可
*/

#define maxn 200005

//tree
vector<vector<int>> G;

int subtreeSize[maxn];
int depth[maxn];
int happiness[maxn];

//計算subtree、depth
void dfs(int u, int p)
{
    subtreeSize[u] = 1;
    for (int v: G[u])
    {
        if (v != p)
        {
            depth[v] = depth[u] + 1;
            dfs(v, u);
            subtreeSize[u] += subtreeSize[v];
        }
    }
    happiness[u] = depth[u] - (subtreeSize[u] - 1);
}

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    G.assign(n + 5, vector<int>());
    int u, v;
    for (int i = 1; i < n; ++i)
    {
        scanf("%d %d", &u, &v);
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }
    dfs(1, -1);
    sort(happiness + 1, happiness + n + 1);
    long long res = 0;
    for (int i = n; i > n - k; --i)
    {
        res += happiness[i];
    }
    printf("%lld\n", res);
    return 0;
}