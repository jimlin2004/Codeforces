#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define maxn 200005

// int dep[maxn];
bool vis[maxn];
vector<vector<int>> G;
int a[maxn];
int inputOrder[maxn];
int outputOrder[maxn];

void bfs()
{
    queue<int> q;
    q.push(1);

    int outputIndex = 0;

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        if (vis[curr])
            continue;
        vis[curr] = true;
        outputOrder[outputIndex++] = curr;
        for (int v: G[curr])
        {
            if (!vis[v])
            {
                // dep[v] = dep[curr] + 1;
                q.push(v);
            }
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    G.assign(n + 5, vector<int>());
    int u, v;
    for (int i = 1; i < n; ++i)
    {
        scanf("%d %d", &u, &v);
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }

    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &a[i]);
        inputOrder[a[i]] = i;
    }
    
    //將鄰接串列以inputOrder排序
    for (int i = 1; i <= n; ++i)
    {
        sort(G[i].begin(), G[i].end(), [=](int a, int b) {
            return inputOrder[a] < inputOrder[b];
        });
    }

    bool ok = true;
    if (a[0] != 1)
        ok = false;
        
    bfs();
    //以下演算法有問題(可能判斷不出來原本的樹形狀)
    // else
    // {
    //     //BFS拜訪順序不可能有出現dep[a[i]] - maxDep > 1的
           //或dep[a[i]] < maxDep的
    //     bool ok = true;
    //     int maxDep = 0;
    //     for (int i = 1; i < n; ++i)
    //     {
    //         if ((dep[a[i]] - maxDep > 1) || (dep[a[i]] < maxDep))
    //         {
    //             ok = false;
    //             break;
    //         }
    //         maxDep = dep[a[i]];
    //     }
    //     puts((ok) ? "Yes" : "No");
    // }

    //跑跑看BFS是不是跟輸入一樣
    
    for (int i = 0; i < n; ++i)
    {
        if (outputOrder[i] != a[i])
        {
            ok = false;
            break;
        }
    }
    puts((ok) ? "Yes" : "No");
    return 0;
}