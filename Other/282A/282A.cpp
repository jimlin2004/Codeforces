#include <iostream>
using namespace std;

int main()
{
    int x = 0;
    int t;
    string cmd;
    cin >> t;
    while (t--)
    {
        cin >> cmd;
        if (cmd == "++X" || cmd == "X++")
            ++x;
        else
            --x;
    }
    cout << x << '\n';
    return 0;
}