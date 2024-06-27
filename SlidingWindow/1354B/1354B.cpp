#include <iostream>
#include <algorithm>
using namespace std;

/*
    用滑動窗戶維護最小可以達到有1、2、3的字串即可
    O(n)
*/

int cnt[5];

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        for (int i = 1; i <= 3; ++i)
            cnt[i] = 0;

        string str;
        cin >> str;
        int l = 0, r = 0;
        int res = 0x3f3f3f3f;
        while (r < str.size())
        {
            ++cnt[str[r] - '0'];
            while (cnt[str[l] - '0'] > 1)
            {
                --cnt[str[l] - '0'];
                ++l;
            }
            
            bool ok = true;
            for (int i = 1; i <= 3; ++i)
            {
                if (cnt[i] == 0)
                {
                    ok = false;
                    break;
                }
            }
            if (ok)
            {
                res = min(res, r - l + 1);
            }
            
            ++r;
        }
        if (res == 0x3f3f3f3f)
            puts("0");
        else
            printf("%d\n", res);
    }
    return 0;
}