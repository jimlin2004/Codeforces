#include <iostream>
using namespace std;

int main()
{
    string a;
    string b;
    int res = 0;
    cin >> a;
    cin >> b;
    int len = a.size();
    for (int i = 0; i < len; ++i)
    {
        char aC = tolower(a[i]);
        char bC = tolower(b[i]);
        if (aC == bC)
        {
            continue;
        }
        else if (aC > bC)
        {
            res = 1;
            break;
        }
        else
        {
            res = -1;
            break;
        }
    }
    printf("%d\n", res);
    return 0;
}