#include <iostream>
using namespace std;

int main()
{
    string input;
    cin >> input;
    string res = input;
    //轉轉看有沒有比較好
    for (int i = 0; i < input.size(); ++i)
    {
        int n = input[i] - '0';
        int invertN = 9 - n;
        if (i == 0)
        {
            //第一個9不能轉
            if (invertN != 0 && invertN < n)
                res[i] = invertN + '0';
        }
        else if (invertN < n)
            res[i] = (invertN) + '0';
    }
    int index = 0;
    //去掉前導0
    for (int i = 0; i < res.size(); ++i)
    {
        if (res[i] != '0')
            break;
        ++index;
    }
    //只有0還是要輸出
    if (index == res.size())
        cout << '0';
    for (int i = index; i < res.size(); ++i)
    {
        cout << res[i];
    }
    cout << '\n';
    return 0;
}