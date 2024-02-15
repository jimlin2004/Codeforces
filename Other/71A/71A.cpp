#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        string str;
        cin >> str;
        if (str.size() <= 10)
            cout << str << '\n';
        else
        {
            cout << str[0] << to_string(str.size() - 2) << str.back() << '\n';
        }
    }
    return 0;
}