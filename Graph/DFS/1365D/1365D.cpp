#include <iostream>
#include <cstring>
using namespace std;

#define maxn 55

int n, m;
char grid[maxn][maxn];
int dir[4][2] = {
    {1, 0}, {0, 1}, {-1, 0}, {0, -1}
};
bool vis[maxn][maxn];

inline bool isVaild(int x, int y)
{
    return ((x > 0 && x <= m) && (y > 0 && y <= n));
}

void dfs(int x, int y, int& G_cnt)
{
    vis[y][x] = true;
    if (grid[y][x] == 'G')
        --G_cnt;
    for (int d = 0; d < 4; ++d)
    {
        int newX = x + dir[d][0];
        int newY = y + dir[d][1];
        if (isVaild(newX, newY))
        {
            if (!vis[newY][newX] && (grid[newY][newX] == '.' || grid[newY][newX] == 'G'))
                dfs(newX, newY, G_cnt);
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        int G_cnt = 0;
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= m; ++j)
            {
                cin >> grid[i][j];
                if (grid[i][j] == 'G')
                    ++G_cnt;
            }
        }

        //直接在B的四周堵牆，如果有G在B的旁邊->B只要跟著G走->不可能有答案
        //只堵B的四周有點Greedy的味道
        bool ok = true;
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= m; ++j)
            {
                if (grid[i][j] == 'B')
                {
                    for (int d = 0; d < 4; ++d)
                    {
                        int newX = j + dir[d][0];
                        int newY = i + dir[d][1];
                        if (isVaild(newX, newY))
                        {
                            if (grid[newY][newX] == 'G')
                            {
                                ok = false;
                                break;
                            }
                            else if (grid[newY][newX] != 'B')
                                grid[newY][newX] = '#';
                        }
                    }
                }
                if (!ok)
                    break;
            }
            if (!ok)
                break;
        }
        if (!ok)
        {
            puts("No");
            continue;
        }

        //每個好人都走看看會超時
        // for (int i = 1; i <= n; ++i)
        // {
        //     for (int j = 1; j <= m; ++j)
        //     {
        //         if (grid[i][j] == 'G')
        //         {
        //             memset(vis, 0, sizeof(vis));
        //             //走走看
        //             dfs(j, i);
        //             if (!vis[n][m])
        //             {
        //                 ok = false;
        //                 break;
        //             }
        //         }
        //     }
        //     if (!ok)
        //         break;
        // }
        
        //改成從終點能不能走到所有好人(可以加快很多)
        if (grid[n][m] == 'B')
            ok = false;
        else if (grid[n][m] == '#' && G_cnt != 0)
            ok = false;
        else
        {
            memset(vis, 0, sizeof(vis));
            dfs(m, n, G_cnt);
            if (G_cnt != 0)
                ok = false;
        }
        if (!ok)
            puts("No");
        else
            puts("Yes");
    }
    return 0;
}