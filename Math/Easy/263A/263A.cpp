#include <cstdio>
#include <cmath>

/*
    單純考曼哈頓距離
*/

int main()
{
    int input;
    int x, y;
    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            scanf("%d", &input);
            if (input == 1)
            {
                x = j;
                y = i;
            }
        }
    }

    printf("%d\n", abs(x - 2) + abs(y - 2));
    return 0;
}