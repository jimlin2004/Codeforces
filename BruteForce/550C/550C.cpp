#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

//能被8整除的看最後三位數能不能被8整除即可
//然後題目字串只有100，解法就一個個位數枚舉 -> O(len ^ 3)

int main()
{
    string line;
    cin >> line;
    for (int i = line.size() - 1; i >= 0; --i)
    {
        int res1 = line[i] - '0';
        if (res1 % 8 == 0)
        {
            cout << "YES\n";
            cout << res1 << '\n';
            return 0;
        }
        for (int j = i - 1; j >= 0; --j)
        {
            if (j == i)
                break;
            int res2 = (line[j] - '0') * 10 + res1;
            if (res2 % 8 == 0)
            {
                cout << "YES\n";
                cout << res2 << '\n';
                return 0;
            }
            for (int k = j - 1; k >= 0; --k)
            {
                if (k == j || k == i)
                    break;
                int res3 = (line[k] - '0') * 100 + res2;
                if (res3 % 8 == 0)
                {
                    cout << "YES\n";
                    cout << res3 << '\n';
                    return 0;
                }
            }
        }
    }
    cout << "NO\n";
    return 0;
}