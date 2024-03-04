#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

vector<long long> squares;

int main()
{
    long long square;
    for (long long i = 0;; ++i)
    {
        square = i * i;
        if (square <= 200000000000005)
            squares.emplace_back(square);
        else
            break;
    }
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        long long total = 0;
        scanf("%d", &n);
        long long num;
        for (int i = 0; i < n; ++i)
        {
            scanf("%lld", &num);
            total += num;
        }
        if (*lower_bound(squares.begin(), squares.end(), total) == total)
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}