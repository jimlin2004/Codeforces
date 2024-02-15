#include <cstdio>
using namespace std;

//能直接從大的除是因為coins能湊出其他人的mod

int coins[5] = {
    1, 5, 10, 20, 100
};

int main()
{
    int n;
    scanf("%d", &n);
    int res = 0;
    for (int i = 4; i >= 0; --i)
    {
        res += (n / coins[i]);
        n %= coins[i];
        if (n == 0)
            break;
    }
    printf("%d\n", res);
    return 0;
}