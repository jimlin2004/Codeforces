#include <iostream>
using namespace std;

//利用dfs每次動一步換一個顏色的棋子即可

#define maxn 105

int dir[4][2] = {
    {0, 1}, {-1, 0}, {0, -1}, {1, 0}
};
char grid[maxn][maxn];
int n, m;

inline bool isVaild(int x, int y)
{
    return (x > 0 && x <= m) && (y > 0 && y <= n);
}

void dfs(int x, int y, char val)
{
    grid[y][x] = val;
    for (int d = 0; d < 4; ++d)
    {
        int newX = x + dir[d][0];
        int newY = y + dir[d][1];

        if (isVaild(newX, newY) && grid[newY][newX] == '.')
        {
            dfs(newX, newY, (val == 'B') ? 'W' : 'B');
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            cin >> grid[i][j];
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (grid[i][j] == '.')
            {
                dfs(j, i, 'B');
            }
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            cout << grid[i][j];
        }
        cout << '\n';
    }
    return 0;
}