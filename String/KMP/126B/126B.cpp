#include <iostream>
using namespace std;

/*
    考KMP
    利用KMP+vis[]
    快速找前後綴以及是否中間出現過
*/

#define maxn 1000005
// #define maxn 10005

int nextArr[maxn];
//到最後之前出現過
bool vis[maxn];

void getNextArr(const string& str)
{
    nextArr[0] = 0;
    int prefixLen = 0;
    for (int i = 1; i < str.size(); ++i)
    {
        prefixLen = nextArr[i - 1];
        //如果不一樣就在之前算過的prefix中搜有沒有更短的前後綴
        while (prefixLen > 0 && str[prefixLen] != str[i])
            prefixLen = nextArr[prefixLen - 1];
        //一樣就繼承之前的前後綴長度+1
        if (str[prefixLen] == str[i])
            ++prefixLen;
        nextArr[i] = prefixLen;
    }

    for (int i = 0; i < str.size() - 1; ++i)
    {
        vis[nextArr[i]] = true;
    }
}

int main()
{
    string str;
    cin >> str;

    getNextArr(str);

    bool ok = false;
    int i = str.size() - 1;
    //以i為結尾的前後綴存在
    while (nextArr[i])
    {
        //在中間也出現過->找到解了
        if (vis[nextArr[i]])
        {
            for (int j = 0; j < nextArr[i]; ++j)
            {
                printf("%c", str[j]);
                ok = true;
            }
            break;
        }
        i = nextArr[i - 1];
    }

    if (ok)
        puts("");
    else
        printf("Just a legend\n");

    return 0;
}